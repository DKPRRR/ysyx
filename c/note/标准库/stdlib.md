`stdlib.h` 是 C 标准库中的一个头文件，提供了许多实用的通用函数，涵盖了内存分配、进程控制、数学计算、随机数生成、字符串转换等方面的功能。

### 常见的函数和功能

#### 1. **内存管理函数**

- **`malloc`**: 分配指定大小的内存块。
  ```c
  void* malloc(size_t size);
  ```

- **`calloc`**: 分配内存并初始化为零。
  ```c
  void* calloc(size_t num, size_t size);
  ```

- **`realloc`**: 重新调整以前分配的内存块大小。
  ```c
  void* realloc(void* ptr, size_t size);
  ```

- **`free`**: 释放以前分配的内存块。
  ```c
  void free(void* ptr);
  ```

#### 2. **进程控制函数**

- **`exit`**: 终止程序，并返回一个状态码给操作系统。
  ```c
  void exit(int status);
  ```

- **`abort`**: 使程序异常终止。
  ```c
  void abort(void);
  ```

- **`atexit`**: 注册在 `exit` 调用时要执行的函数。
  ```c
  int atexit(void (*func)(void));
  ```

#### 3. **环境和实用函数**

- **`system`**: 执行 shell 命令。
  ```c
  int system(const char* command);
  ```

- **`getenv`**: 获取环境变量的值。
  ```c
  char* getenv(const char* name);
  ```

- **`putenv`**: 设置环境变量。
  ```c
  int putenv(char* string);
  ```

#### 4. **随机数生成**

- **`rand`**: 返回一个随机数。
  ```c
  int rand(void);
  ```

- **`srand`**: 设置随机数生成器的种子。
  ```c
  void srand(unsigned int seed);
  ```

#### 5. **数学函数**

- **`abs`**: 计算整数的绝对值。
  ```c
  int abs(int n);
  ```

- **`labs`**: 计算长整数的绝对值。
  ```c
  long labs(long n);
  ```

- **`llabs`**: 计算长长整数的绝对值。
  ```c
  long long llabs(long long n);
  ```

- **`div`**: 计算整数除法的商和余数。
  ```c
  div_t div(int numer, int denom);
  ```

- **`ldiv`**: 计算长整数除法的商和余数。
  ```c
  ldiv_t ldiv(long numer, long denom);
  ```

- **`lldiv`**: 计算长长整数除法的商和余数。
  ```c
  lldiv_t lldiv(long long numer, long long denom);
  ```

#### 6. **字符串转换**

- **`atoi`**: 将字符串转换为整数。
  ```c
  int atoi(const char* str);
  ```

- **`atol`**: 将字符串转换为长整数。
  ```c
  long atol(const char* str);
  ```

- **`atoll`**: 将字符串转换为长长整数。
  ```c
  long long atoll(const char* str);
  ```

- **`strtod`**: 将字符串转换为 `double` 类型。
  ```c
  double strtod(const char* str, char** endptr);
  ```

- **`strtol`**: 将字符串转换为长整数。
  ```c
  long strtol(const char* str, char** endptr, int base);
  ```

- **`strtoll`**: 将字符串转换为长长整数。
  ```c
  long long strtoll(const char* str, char** endptr, int base);
  ```

- **`strtoul`**: 将字符串转换为无符号长整数。
  ```c
  unsigned long strtoul(const char* str, char** endptr, int base);
  ```

- **`strtoull`**: 将字符串转换为无符号长长整数。
  ```c
  unsigned long long strtoull(const char* str, char** endptr, int base);
  ```

#### 7. **伪随机数生成**

- **`rand`**: 返回一个随机整数。
  ```c
  int rand(void);
  ```

- **`srand`**: 设置随机数生成器的种子。
  ```c
  void srand(unsigned int seed);
  ```

### 小结

`stdlib.h` 提供了很多非常基础且重要的函数，用于内存管理、程序控制、数学运算、随机数生成以及字符串转换。这些函数在 C 程序的开发中非常常用，是每个 C 程序员都需要熟悉的工具。