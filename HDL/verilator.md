## ysyx讲义的适配

ysyx讲义说ysyx-workbench中的是NPC（New Processor Core）

PA1（(Programming Assignment）说的是NEMU（NJU EMUlator）南大硬件仿真器

> - 请把`ysyx-workbench`作为PA讲义中的项目目录, 即将PA讲义中的`ics2022`看成是`ysyx-workbench`
> - 修改`ysyx-workbench/Makefile`中的学号和姓名时, 学号可先不修改, 等到大家完成预学习之后再修改
>
> 这种来回跳转的做法可能会给你带来一些麻烦, 但我们之所以这样做, 是希望把文档看作代码来管理: 我们希望做到类似`"一生一芯"讲义调用PA讲义`的效果, 因此我们在PA讲义中尽可能少地提到"一生一芯", 而把"一生一芯"的相关内容都放到"一生一芯"本身的讲义中. 如果不遵守这条原则, 不仅会使我们维护讲义时感到困难, 而且大家阅读讲义时也不知道应该到哪里寻找相关的内容.

看起来

要做四个东西

**linux**

**C**

**HDL**

**NEMU**

NPC应该是HDL里的内容

# verilator

verilator并不像其他数电仿真器一样，输入HDL工程和testbench就可以生成波形

甚至在verilator的工具链中testbench都是用c++编写的，verilator会将HDL工程转换成c++的一个类，这个过程就叫`verilate`，然后通过testbench调用这个类，然后运行testbench编译后的可执行文件即可完成仿真，然而我们要看波形图。

### verilate

该操作将HDL转译成c++文件，verilate的操作和参数和gcc很像

该命令会在根据top.v当前工作目录生成一个obj_dir文件夹

```
verilator --cc top.v
```

--cc是指定verilater将HDL工程转译成c++语言

相对的你也可以使用--sc指定转译成system c语言

并在后面指定HDL文件



该命令会在上面的基础上追加.mk文件，这是makefile文件。可以用这个直接构建整个工程了。

```
verilator --Wall --trace --cc top.v --exe testbench.cpp
```



```
make -C obj_dir -f V<top>.mk V<top>
```

-C 指示make的工作目录为obj_dir

-f 指示makefile文件名为V<top>.mk

通过查看makefile你可以知道名为V<top>的target是指定可执行文件的名字。

运行可执行文件就可以开启仿真并输出波形文件了。

### 波形图

波形图是在执行testbench可执行文件时同时生成的。testbench中，我们用verilator提供的包（API），在仿真环节的前后设置监测，并在最终生成一个二值波形文件。

这个文件通常是.vcd格式也可以是.fst格式，但是ysyx讲义建议使用.fst

>  生成FST格式的波形
>
> FST格式的波形文件大致是VCD格式的1/50, 但它仅能被GTKWave支持. 尽管如此, 我们还是推荐你使用它.

至于为什么是二值的

> 这是因为`Verilator`是一个双状态的仿真工具，默认情况下，所有的信号都被初始化为0。这对于提高仿真速度来说是有效的，因为2个状态比4个状态要少，但是如果我们想检查我们的复位逻辑工作得如何，就不是很好。

这里的四个状态指的是低电平、高电平、未知值和高阻态。

查看波形文件的波形，需要使用GTKWave工具

```bash
sudo apt install gtkwave #使用apt下载安装
```

```
gtkwave <波形文件> #查看生成后的波形
```



### testbench

和其他testbench使用HDL语言不同的是，verilator使用的testbench是c++语言

因此需要补充一些c++的类和对象的知识来确保掌握testbench的编写，并且熟悉该文件的基本套路。 

```c++
//c++标准库文件，不再多说
#include <stdlib.h>
#include <iostream>

//veriliator的用于仿真的api
#include <verilated.h>

//veriliator的用于生成vcd波形文件的api
#include <verilated_vcd_c.h>

//声明HDL工程转换后的c++类的的头文件，对应Valu.c
#include "Valu.h"

//system verilog特有的的数据类型的声明
#include "Valu___024unit.h"

//设置仿真的周期数
#define MAX_SIM_TIME 20

//用于计数周期数
vluint64_t sim_time = 0;

int main(int argc, char* argv[], char* env[]) {
    
    // 初始化 Verilator 参数
    Verilated::commandArgs(argc, argv);
    
    //例化HDL的顶层模块
    Valu *dut = new Valu;
	
    //开启波形监测
    Verilated::traceEverOn(true);
    
    //在堆上例化一个记录波形的类，防止爆栈
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    
    //用m_trace监测dut 第二个参数是的是深度
    dut->trace(m_trace, 5);
    
    //将监测的波形保存为.vcd文件
    m_trace->open("waveform.vcd");

    //开始仿真
    while (sim_time < MAX_SIM_TIME) {
        
        ///每一周期翻转时钟信号
        dut->clk ^= 1;
        
        //为什么没有激励信号？？？
        
        //HDL电路工作，更新响应信号
        dut->eval();
        
        //将被监测的响应信号写入波形中
        m_trace->dump(sim_time);
        
        //下一周期
        sim_time++;
    }
    
    //结束监测
    m_trace->close();
    
    //释放dut在堆的内存
    delete dut;
    
    //退出程序，返回相应值
    exit(EXIT_SUCCESS);
}

```

如果想要生成fst格式的波形文件`#include "verilated_fst_c.h"`就可以了

```c++
#include "Vcounter.h"              // Verilator 生成的 C++ 模型类
#include "verilated.h"             // Verilator 的核心仿真库
#include "verilated_fst_c.h"       // Verilator 的 FST 支持库

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // 初始化 Verilator 参数

    Vcounter* top = new Vcounter;        // 创建 Verilog 模块的 C++ 实例
    VerilatedFstC* tfp = new VerilatedFstC;  // 创建 FST 跟踪对象

    Verilated::traceEverOn(true);        // 启用波形跟踪功能
    top->trace(tfp, 99);                 // 将 FST 对象连接到仿真模块，99 是跟踪深度
    tfp->open("dump.fst");               // 打开并创建一个名为 "dump.fst" 的 FST 文件

    // 初始化输入信号
    top->clk = 0;
    top->rst = 1;

    // 仿真循环
    for (int i = 0; i < 20; i++) {
        if (i == 2) top->rst = 0;        // 在第 2 个周期清除复位信号
        
        top->clk = !top->clk;            // 模拟时钟的上升沿和下降沿
        top->eval();                     // 调用 eval() 进行仿真计算
        tfp->dump(i);                    // 将当前周期的波形数据记录到 FST 文件中
    }

    tfp->close();                        // 关闭 FST 文件
    top->final();                        // 终止仿真，进行必要的清理
    delete top;                          // 释放模块实例对象
    delete tfp;                          // 释放 FST 对象
    return 0;
}

```

函数是完全一样的。

### obj_dir

这个文件夹是verilator后，将所有目标文件都放到了此处。如果要仿真，必须要知道都生成了哪些文件

V<top>.cpp

V<top>.h



V<top>_Syms.cpp

V<top>_Syms.h



V<top>.mk



V<top>_Trance.cpp



V<top>_Trace_Slow.cpp



V<top>_ALL.a



V<top>_Slow.cpp
