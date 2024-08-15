`string.h` 是 C 标准库中的一个头文件，提供了一组用于操作字符串和内存块的函数。这些函数包括字符串的复制、连接、比较、查找、长度计算等，以及内存块的复制、移动、设置等操作。

### 常见的字符串操作函数

#### 1. **字符串复制和连接**

- **`strcpy`**: 复制字符串到另一个字符数组。
  ```c
  char *strcpy(char *dest, const char *src);
  ```

- **`strncpy`**: 复制指定长度的字符串到另一个字符数组。
  ```c
  char *strncpy(char *dest, const char *src, size_t n);
  ```

- **`strcat`**: 将一个字符串追加到另一个字符串的末尾。
  ```c
  char *strcat(char *dest, const char *src);
  ```

- **`strncat`**: 将指定长度的字符串追加到另一个字符串的末尾。
  ```c
  char *strncat(char *dest, const char *src, size_t n);
  ```

#### 2. **字符串比较**

- **`strcmp`**: 比较两个字符串。
  ```c
  int strcmp(const char *str1, const char *str2);
  ```

- **`strncmp`**: 比较指定长度的两个字符串。
  ```c
  int strncmp(const char *str1, const char *str2, size_t n);
  ```

#### 3. **字符串查找**

- **`strchr`**: 查找字符串中首次出现的字符。
  ```c
  char *strchr(const char *str, int c);
  ```

- **`strrchr`**: 查找字符串中最后一次出现的字符。
  ```c
  char *strrchr(const char *str, int c);
  ```

- **`strstr`**: 在字符串中查找另一个字符串的第一次出现。
  ```c
  char *strstr(const char *haystack, const char *needle);
  ```

- **`strtok`**: 分割字符串（基于指定的分隔符）。
  ```c
  char *strtok(char *str, const char *delim);
  ```

#### 4. **字符串长度**

- **`strlen`**: 计算字符串的长度（不包括终止符 `\0`）。
  ```c
  size_t strlen(const char *str);
  ```

#### 5. **字符串转换**

- **`strdup`**: 动态分配内存，并复制字符串（非标准，POSIX 定义）。
  ```c
  char *strdup(const char *str);
  ```

### 常见的内存操作函数

#### 1. **内存块复制**

- **`memcpy`**: 复制指定大小的内存块。
  ```c
  void *memcpy(void *dest, const void *src, size_t n);
  ```

- **`memmove`**: 复制指定大小的内存块（允许重叠）。
  ```c
  void *memmove(void *dest, const void *src, size_t n);
  ```

#### 2. **内存块比较**

- **`memcmp`**: 比较指定大小的内存块。
  ```c
  int memcmp(const void *str1, const void *str2, size_t n);
  ```

#### 3. **内存块设置**

- **`memset`**: 将指定大小的内存块设置为某个值。
  ```c
  void *memset(void *str, int c, size_t n);
  ```

### 小结

`string.h` 头文件提供了一系列操作字符串和内存的常用函数。这些函数在 C 语言编程中非常重要，广泛用于处理字符数组（字符串）和内存块。通过这些函数，程序员可以方便地进行字符串操作、内存管理等操作。