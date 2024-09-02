#include "Vtop.h"              // Verilator 生成的 C++ 模型类
#include "verilated.h"             // Verilator 的核心仿真库
#include "verilated_fst_c.h"       // Verilator 的 FST 支持库

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // 初始化 Verilator 参数

    Vtop* top = new Vtop;        // 创建 Verilog 模块的 C++ 实例
    VerilatedFstC* m_trace = new VerilatedFstC;  // 创建 FST 跟踪对象

    Verilated::traceEverOn(true);        // 启用波形跟踪功能
    top->trace(m_trace, 99);                 // 将 FST 对象连接到仿真模块，99 是跟踪深度
    m_trace->open("waveform.fst");               // 打开并创建一个名为 "dump.fst" 的 FST 文件

    top->x[0] = 0;
    top->x[1] = 1;
    top->x[2] = 2;
    top->x[3] = 3;

    top->y = 0;
    top->eval();                     // 调用 eval() 进行仿真计算
    m_trace->dump(0);                    // 将当前周期的波形数据记录到 FST 文件中

    top->y = 1;
    top->eval();
    m_trace->dump(1);

    top->y = 2;
    top->eval();
    m_trace->dump(2);

    top->y = 3;
    top->eval();
    m_trace->dump(3);

    m_trace->close();                        // 关闭 FST 文件
    top->final();                        // 终止仿真，进行必要的清理
    delete top;                          // 释放模块实例对象
    delete m_trace;                          // 释放 FST 对象
    return 0;
}
