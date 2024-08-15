`stdio.h` 是 C 标准库中的一个头文件，提供了标准输入输出函数的声明。这些函数用于处理文件输入输出、控制台输入输出等操作，是 C 语言中最常用的头文件之一。

### 常见的输入输出函数

#### 1. **标准输入输出**

- **`printf`**: 格式化输出到标准输出（通常是控制台）。
  ```c
  int printf(const char *format, ...);
  ```

- **`scanf`**: 从标准输入读取格式化数据。
  ```c
  int scanf(const char *format, ...);
  ```

- **`fprintf`**: 格式化输出到指定文件流。
  ```c
  int fprintf(FILE *stream, const char *format, ...);
  ```

- **`fscanf`**: 从指定文件流读取格式化数据。
  ```c
  int fscanf(FILE *stream, const char *format, ...);
  ```

- **`sprintf`**: 格式化输出到字符串。
  ```c
  int sprintf(char *str, const char *format, ...);
  ```

- **`sscanf`**: 从字符串中读取格式化数据。
  ```c
  int sscanf(const char *str, const char *format, ...);
  ```

- **`vprintf`**, **`vfprintf`**, **`vsprintf`**: 这些是 `printf`、`fprintf`、`sprintf` 的变体，使用 `va_list` 处理可变参数。

#### 2. **文件操作**

- **`fopen`**: 打开文件并返回文件指针。
  ```c
  FILE *fopen(const char *filename, const char *mode);
  ```

- **`fclose`**: 关闭文件。
  ```c
  int fclose(FILE *stream);
  ```

- **`fread`**: 从文件中读取数据到缓冲区。
  ```c
  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
  ```

- **`fwrite`**: 将缓冲区的数据写入文件。
  ```c
  size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
  ```

- **`fseek`**: 设置文件指针的位置。
  ```c
  int fseek(FILE *stream, long int offset, int whence);
  ```

- **`ftell`**: 获取文件指针的当前位置。
  ```c
  long int ftell(FILE *stream);
  ```

- **`rewind`**: 将文件指针重置到文件的开头。
  ```c
  void rewind(FILE *stream);
  ```

- **`fflush`**: 刷新文件流，将缓冲区中的数据写入文件。
  ```c
  int fflush(FILE *stream);
  ```

#### 3. **字符和行输入输出**

- **`fgetc`**: 从文件中读取一个字符。
  ```c
  int fgetc(FILE *stream);
  ```

- **`fputc`**: 将一个字符写入文件。
  ```c
  int fputc(int char, FILE *stream);
  ```

- **`fgets`**: 从文件中读取一行字符串。
  ```c
  char *fgets(char *str, int n, FILE *stream);
  ```

- **`fputs`**: 将一个字符串写入文件。
  ```c
  int fputs(const char *str, FILE *stream);
  ```

- **`getc`** 和 **`putc`**: 类似于 `fgetc` 和 `fputc`，但可能实现为宏。

- **`gets`**: 从标准输入读取一行字符串（已被弃用，建议使用 `fgets`）。
  ```c
  char *gets(char *str);
  ```

- **`puts`**: 将字符串写入标准输出。
  ```c
  int puts(const char *str);
  ```

- **`ungetc`**: 将字符推回到流中。
  ```c
  int ungetc(int char, FILE *stream);
  ```

#### 4. **错误处理**

- **`perror`**: 输出最后一个发生的错误消息。
  ```c
  void perror(const char *str);
  ```

- **`clearerr`**: 清除文件流中的错误和 EOF 标志。
  ```c
  void clearerr(FILE *stream);
  ```

- **`feof`**: 检查文件流是否到达 EOF（文件结束）。
  ```c
  int feof(FILE *stream);
  ```

- **`ferror`**: 检查文件流是否发生错误。
  ```c
  int ferror(FILE *stream);
  ```

### 常见的类型和宏

- **`FILE`**: 用于表示文件流的类型。
  
- **`EOF`**: 表示文件结束或错误的宏，通常为 `-1`。

- **`NULL`**: 空指针常量。

### 小结

`stdio.h` 提供了标准输入输出和文件操作的基础工具。通过这些函数，C 语言程序可以进行文件读写、控制台输入输出，以及处理各种类型的字符和数据流，是 C 语言编程中最常用的头文件之一。