> 获取后, 你就可以回到PA讲义的相应位置, 继续阅读了. 不过你还需要注意:
>
> - 请把`ysyx-workbench`作为PA讲义中的项目目录, 即将PA讲义中的`ics2022`看成是`ysyx-workbench`
> - 修改`ysyx-workbench/Makefile`中的学号和姓名时, 学号可先不修改, 等到大家完成预学习之后再修改
>
> 这种来回跳转的做法可能会给你带来一些麻烦, 但我们之所以这样做, 是希望把文档看作代码来管理: 我们希望做到类似`"一生一芯"讲义调用PA讲义`的效果, 因此我们在PA讲义中尽可能少地提到"一生一芯", 而把"一生一芯"的相关内容都放到"一生一芯"本身的讲义中. 如果不遵守这条原则, 不仅会使我们维护讲义时感到困难, 而且大家阅读讲义时也不知道应该到哪里寻找相关的内容.

获取ysyx-workbench

```
git clone -b master git@github.com:OSCPU/ysyx-workbench.git
```

配置NPC环境（设置NPC_HOME环境变量）

```
bash init.sh npc
```

获取并配置NVBoard环境

```
bash init.sh nvboard
```

获取并配置NEMU环境

```
bash init.sh nemu
```

获取并配置AM环境

```
bash init.sh abstract-machine
```

获取并配置测试程序

```
bash init.sh am-kernels
```

