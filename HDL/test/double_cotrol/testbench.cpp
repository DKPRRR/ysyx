
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Vtop.h"             // Verilator 生成的 C++ 模型类
#include "verilated.h"            // Verilator 的核心仿真库
#include "verilated_fst_c.h"      // Verilator 生成的 VCD 波形库

int main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);  // 初始化 Verilator 参数

    Vtop* top = new Vtop;        // 创建 Verilog 模块的 C++ 实例


    while (1) {
      int a = rand() & 1;
      int b = rand() & 1;
      top->a = a;
      top->b = b;
      top->eval();
      printf("a = %d, b = %d, f = %d\n", a, b, top->f);
      assert(top->f == (a ^ b));
    }


    delete top;                          // 释放模块实例对象
    return 0;
}
