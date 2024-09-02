## 锁存器latch，触发器DFF，寄存器register

锁存器，电平触发，易传播毛刺，且难分析时序，仅用于异步电路和低功耗电路

触发器和寄存器（未完）

有无复位信号 触发方式 是否延迟 延迟一个周期

### 如何防止综合出锁存器？

(未完)

## 位宽和深度

```
reg [宽度] memory [深度/组数];
```

```verilog
memory[255] //索引第255个元素
```

```verilog
memory[4][5] //索引第4个元素第五位
```

## reg还是wire？

always被变量符号使用reg

assign被赋值变量使用wire

变量名不是区分寄存器和线型的依据

依据是时序电路综合成寄存器，组合电路综合成线型

## assign还是always？

简单的组合逻辑推荐使用assign描述，复杂的组合逻辑推荐使用always

虽然always时序分析和优化可能不如assign，但是可读性要好很多

ifelse和case的优先性问题

## 可综合还是不可综合？

使用 assgin always begin end

使用 initial for fun？？？ while fork join

## 串行还是并行？

begin end内部的全是串行

## 阻塞还是非阻塞？

always中=和<=该怎么区分和使用？

> 组合逻辑用阻塞=
>
> 时序逻辑用非阻塞<=

新手只需要知道这一点就够了

## 组合逻辑还是时序逻辑？

> 时序逻辑的规范是要有复位
>
> 每加一个DFF，输出就推迟一个时钟周期

## 流水线