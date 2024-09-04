GDB调试工具

## 编译

编译可执行文件时注意添加调试参数，使可执行文件保留调试信息可以被GDB调试

```
gcc -g
```

## 调试模式指令

### break

打断点

```
break <文件>:<行号>
```

```
break <文件>：<函数名>
```

如果只有一个文件可以不写文件

### run

开始运行程序

### next

步过，不进入函数内部，继续执行下一行

### step

步入，进入函数内部。

### continue

继续运行被停止的程序

### finish

退出当前所在的函数回到上一级调用

### kill

停止运行的程序

### list

查看源代码

### quit/exit

退出调试模式

### info 

查看所有断点的情况

如：查看所有的break断点

```
info break
```

### print

查看变量的值，允许表达式

如

```
print arr[0]   #输出arr第0个地址的值
```

```
print &a   #输出a的地址
```

edit



help

breakpoint,watchpoint,catchpoint

## TUI

GDB提供了一个更直观的界面来调试程序

可以在启动gdb的时候调用`--tui`参数来直接启动TUI模式

或者

在GDB模式中按下`ctrl+X+A`来开启或者关闭TUI模式

默认显示command窗口和source窗口

可以通过layout来切换窗口

```
layout <窗口类型>
```

cmd 命令窗口

src 源代码窗口

asm 汇编代码窗口

reg 寄存器窗口