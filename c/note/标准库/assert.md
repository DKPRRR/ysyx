`assert.h` 是 C 语言标准库中的一个头文件，它提供了一个宏 `assert`，用于在程序运行时进行条件检查，并在条件不满足时报告错误。

### `assert` 宏

`assert` 宏的作用是检查一个表达式，如果表达式的值为假（即 `0`），则它会打印一条错误消息并终止程序。这在调试时非常有用，因为它允许开发者在特定条件不满足时立即捕获并查看问题。

#### 语法
```c
#include <assert.h>

void assert(int expression);
```

- **`expression`**：一个可以求值为非零（真）或零（假）的表达式。

如果 `expression` 为假，`assert` 宏会输出一条错误消息，内容包括表达式、源文件名、行号以及一个终止程序的调用。否则，程序继续运行。

#### 使用示例
```c
#include <assert.h>

int main() {
    int x = 10;
    int y = 0;

    // 检查 y 是否为非零
    assert(y != 0);

    // 如果 y 为零，上面的 assert 将会中止程序
    int z = x / y;

    return 0;
}
```
在上述例子中，如果 `y` 为 0，则 `assert` 会打印一条错误消息，并使程序终止，防止出现除以零的错误。

#### 输出示例
当 `assert` 失败时，可能会产生如下输出（假设 `y == 0`）：
```
Assertion failed: (y != 0), function main, file example.c, line 7.
```

### `NDEBUG` 宏

如果在编译时定义了宏 `NDEBUG`，`assert` 宏将被禁用，即使表达式为假，也不会进行检查或终止程序。这通常用于在发布版本中禁用调试检查。

#### 禁用 assert 的示例
```c
#define NDEBUG
#include <assert.h>

int main() {
    int x = 10;
    int y = 0;

    // 即使 y 为 0，assert 也不会触发
    assert(y != 0);

    int z = x / y; // 仍然会发生运行时错误：除以零

    return 0;
}
```

### 总结

- **`assert` 宏**：用于在调试过程中检查条件，确保程序在关键条件下的正确性。如果条件为假，程序会打印错误信息并终止。
- **`NDEBUG` 宏**：用于禁用 `assert`，常用于发布版本，以提高程序性能并避免调试代码的干扰。

`assert.h` 只包含 `assert` 这个宏，但它在调试中非常有用，帮助开发者捕获潜在的问题。