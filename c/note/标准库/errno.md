`errno.h` 是 C 标准库中的一个头文件，用于处理和报告程序运行中的错误。它定义了全局变量 `errno` 以及一组标准的错误代码（宏），这些错误代码表示程序运行过程中可能出现的各种错误类型。

### 主要内容

#### 1. **`errno` 变量**

`errno` 是一个全局整型变量，用于保存函数调用失败时的错误代码。大多数 C 标准库函数在出错时不会直接返回错误信息，而是将错误信息保存在 `errno` 中，函数本身可能返回一个特定的值（通常是 `-1` 或 `NULL`）来表示失败。

```c
#include <errno.h>

int errno;
```

在使用时，你可以通过检查 `errno` 的值来判断具体的错误类型。注意，`errno` 的值在每次成功的函数调用之后不会自动重置，所以在处理错误时，应在调用函数之前将 `errno` 清零。

#### 2. **标准错误代码宏**

`errno.h` 定义了一些标准错误代码，这些错误代码是整数常量，表示不同类型的错误。常见的错误代码包括：

- **`EPERM`**：操作不允许（Operation not permitted）
- **`ENOENT`**：没有找到文件或目录（No such file or directory）
- **`ESRCH`**：没有找到进程（No such process）
- **`EINTR`**：系统调用被中断（Interrupted system call）
- **`EIO`**：输入/输出错误（I/O error）
- **`ENXIO`**：没有这样的设备或地址（No such device or address）
- **`E2BIG`**：参数列表太长（Argument list too long）
- **`ENOMEM`**：内存不足（Out of memory）
- **`EACCES`**：权限被拒绝（Permission denied）
- **`EFAULT`**：坏地址（Bad address）
- **`EBUSY`**：设备或资源忙（Device or resource busy）
- **`EEXIST`**：文件已存在（File exists）
- **`ENOTDIR`**：不是一个目录（Not a directory）
- **`EISDIR`**：是一个目录（Is a directory）
- **`EINVAL`**：无效的参数（Invalid argument）
- **`ENFILE`**：系统打开文件过多（File table overflow）
- **`EMFILE`**：进程打开文件过多（Too many open files）
- **`EFBIG`**：文件过大（File too large）
- **`ENOSPC`**：设备上没有空间（No space left on device）
- **`ESPIPE`**：非法的偏移值（Illegal seek）
- **`EROFS`**：只读文件系统（Read-only file system）
- **`EMLINK`**：链接数过多（Too many links）
- **`EPIPE`**：管道破裂（Broken pipe）
- **`EDOM`**：数学函数参数域错误（Math argument out of domain of func）
- **`ERANGE`**：数学结果超出范围（Math result not representable）

这些错误代码用来描述函数调用失败的具体原因。

#### 3. **错误处理流程**

通常，错误处理的流程如下：

1. **调用函数**：执行可能失败的函数。
2. **检查返回值**：根据函数的返回值判断是否出现错误。
3. **检查 `errno`**：如果函数返回错误，查看 `errno` 的值，以确定错误的具体类型。
4. **错误处理**：根据 `errno` 的值进行相应的错误处理或输出错误信息。

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistent_file.txt", "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
    }

    return 0;
}
```

在这个例子中，如果文件打开失败，`errno` 会保存错误代码，`strerror(errno)` 将错误代码转换为对应的错误消息并打印出来。

### 小结

`errno.h` 主要用于错误处理，提供了全局变量 `errno` 以及一系列标准错误代码。这些工具使得 C 语言程序能够在遇到错误时做出适当的响应，并提供用户友好的错误信息。