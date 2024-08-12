## 引言

这是一个ubuntu系统，所以软件包管理器是APT，所以我们要学习apt的指令

## APT（Advanced Package Tool）

```
apt update
```

是用于更新apt中的软件包列表的命令，这个可以让apt知道有哪些软件的最新版本可以更新了，最新版本的版本信息等

```
apt upgrade
```

可以将，可以更新的所有软件进行更新



通常你需要添加sudo，因为apt通常需要root的权限

如

```
sudo apt update
sudo apt upgrade
```

## 来自chatgpt的补充

以下是一些常用的 `apt` 命令及其功能：

### 1. **更新和升级系统**
- **`apt update`**  
  更新软件包列表，从软件源获取最新的包信息。

- **`apt upgrade`**  
  升级已安装的软件包到新版本，不会移除已安装的软件包或安装新软件包。

- **`apt full-upgrade`**  
  类似于 `apt upgrade`，但在需要时可以自动移除已安装的软件包或安装新软件包，以完成升级。

### 2. **安装软件包**
- **`apt install <package-name>`**  
  安装指定的软件包。例如：`apt install vim` 安装 Vim 文本编辑器。

- **`apt install -y <package-name>`**  
  安装指定软件包并自动接受所有提示（例如安装过程中要求确认的步骤）。

### 3. **移除软件包**
- **`apt remove <package-name>`**  
  移除指定的软件包，但保留配置文件。

- **`apt purge <package-name>`**  
  移除指定的软件包及其相关的配置文件。

### 4. **清理系统**
- **`apt autoremove`**  
  自动移除不再需要的依赖包。这些依赖包通常是在卸载软件包后留下的。

- **`apt autoclean`**  
  删除已过时的软件包缓存，保留当前已安装版本的包。

- **`apt clean`**  
  删除所有下载的软件包缓存，释放磁盘空间。

### 5. **查看包信息**
- **`apt search <package-name>`**  
  搜索软件包。根据关键字返回匹配的包名和简短描述。

- **`apt show <package-name>`**  
  显示有关指定软件包的详细信息，包括版本、大小、依赖项等。

### 6. **管理软件源**
- **`apt edit-sources`**  
  使用默认编辑器打开软件源列表文件 (`/etc/apt/sources.list`)，以便手动编辑软件源。

### 7. **修复依赖关系**
- **`apt install -f`**  
  修复系统中断或未满足的依赖关系，常用于解决软件包安装过程中出现的问题。

### 8. **获取帮助**
- **`apt help`**  
  显示 apt 命令的帮助信息。

这些命令涵盖了日常使用中最常见的场景，可以帮助你有效地管理系统中的软件包。
