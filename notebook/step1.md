<!--
 * @Author       : lqm283
 * @Date         : 2022-11-11 15:48:54
 * @LastEditTime : 2022-11-12 10:20:47
 * @LastEditors  : lqm283
 * --------------------------------------------------------------------------------------------------------------------<
 * @Description  : Please edit a descrition about this file at here.
 * --------------------------------------------------------------------------------------------------------------------<
 * @FilePath     : /notebook/step1.md
-->

# 一个基本的起点

## 练习一：构建一个基本的工程

1. CMake 工程需要有一个名为 `CMakeLists.txt` 的文件。
2. 该练习中会使用到 CMake 的三个命令： `cmake_minimum_required()`、`add_executable()` 、`project()`。

### 目标

了解如何创建一个简单的 CMake 工程。

### 要编辑的文件

+ CMakeLists.txt

### 开始

CMakeLists.txt 中的初始内容为：

```cmake
# TODO 1: Set the minimum required version of CMake to be 3.10

# TODO 2: Create a project named Tutorial

# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True

# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx

# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
```

#### 编写 CMakeLists.txt

现在，我们先完成 TODO 1 到 TODO 3。

##### TODO 1

设置 CMake 的最低需求版本为 3.10

```cmake
# TODO 1: Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)
```

##### TODO 2

创建一个名为 Tutorial 的工程

```cmake
# TODO 2: Create a project named Tutorial
project(Tutorial)
```

**注意：** 这个命令如果不写，那么 CMake 将会使用默认设置，并输出警告：

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake ../Step1
CMake Warning (dev) in CMakeLists.txt:
  No project() command is present.  The top-level CMakeLists.txt file must
  contain a literal, direct call to the project() command.  Add a line of
  code such as

    project(ProjectName)

  near the top of the file, but after cmake_minimum_required().

  CMake is pretending there is a "project(Project)" command on the first
  line.
This warning is for project developers.  Use -Wno-dev to suppress it.
```

##### TODO 3

为工程添加一个源文件，这里源文件的名称为 tutorial.cxx

```cmake
# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)
```

**雷区：** `add_executable(Tutorial tutorial.cxx)` 的第一个参数是工程名称，如果第一个参数与工程名称不同，那么构建出来的可执行程序的名称就会以这个参数为准。

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake --build .
Scanning dependencies of target main
[ 50%] Building CXX object CMakeFiles/main.dir/tutorial.cxx.o
[100%] Linking CXX executable main
[100%] Built target main
```

#### 创建一个构建目录

构建生产的所有文件都会在这个目录中。
目录路径为 tutorial/

```bash
mkdir Step1_build
```

#### 初始化工程

进入 Step1_build 目录，执行以下的命令

```bash
cmake ../Step1
```

CMake 会初始化构建环境，出现以下的内容，说明工程成功被初始化

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake ../Step1
-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/lqm/develop/c/cmake/tutorial/Step1_build
```

#### 构建工程

在完成初始化后，使用以下命令构建工程

```bash
cmake --build .
```

工程的构建过程如下：

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake --build .
Scanning dependencies of target Tutorial
[ 50%] Building CXX object CMakeFiles/Tutorial.dir/tutorial.cxx.o
[100%] Linking CXX executable Tutorial
[100%] Built target Tutorial
```

在构建目录下生成了可执行文件 Tutorial

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  Makefile  Tutorial
```

#### 尝试运行 Tutorial

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial
Usage: ./Tutorial number
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial 1223
The square root of 1223 is 34.9714
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial 16
The square root of 16 is 4
```

## 练习二

1. 该练习会使用到一个命令 `set` 和两个变量 `CMAKE_CXX_STANDARD` 及 `CMAKE_CXX_STANDARD_REQUIRED`。

### 目标

指定工程使用 C++11。

### 要编辑的文件

+ CMakeLists.txt
+ tutorial.cxx

### 开始

首先，编写 CMakeLists.txt ，初始内容为：

```cmake
# TODO 1: Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)
# TODO 2: Create a project named Tutorial
# project(Tutorial)
# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True

# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
```

#### 编写 CMakeLists.txt 和 tutorial.cxx

这里，我们完成其中的 TODO 4 到 TODO 6

##### TODO 4

在 tutorial.cxx 文件中添加如下的语句

```c++
  // convert input to double
  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
const double inputValue = std::stod(argv[1]);
```

##### TODO 5

删除tutorial.cxx 文件中的 `#include <cstdlib` 语句

```c++
#include <cstdlib> // TODO 5: Remove this line
```

##### TODO 6

在 CMakeLists.txt 文件中添加以下的语句

```cmake
# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

#### 验证

按照练习一中的方式构建并运行程序

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake ../Step1
-- Configuring done
-- Generating done
-- Build files have been written to: /home/lqm/develop/c/cmake/tutorial/Step1_build
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake --build .
[ 50%] Building CXX object CMakeFiles/Tutorial.dir/tutorial.cxx.o
[100%] Linking CXX executable Tutorial
[100%] Built target Tutorial
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial 123
The square root of 123 is 11.0905
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial 235
The square root of 235 is 15.3297
```

## 练习三

1. 该练习会使用到两个变量 `<PROJECT-NAME>_VERSION_MAJOR`、`<PROJECT-NAME>_VERSION_MINOR` 及两个命令 `configure_file()` 、`target_include_directories()`。

### 目标

定义并在程序中获取到工程的版本号。

### 要编辑的文件

+ CMakeLists.txt
+ tutorial.cxx

### 开始

CMakeLists.txt 文件的初始状态

```cmake
# TODO 1: Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)
# TODO 2: Create a project named Tutorial
project(Tutorial)
# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
```

#### 编写 CMakeLists.txt 和 tutorial.cxx

这里，我们完成 TODO 7 到 TODO 12。

##### TODO 7

在 CMakeLists.txt 文件中添加工程的版本

```cmake
# TODO 7: Set the project version number as 1.0 in the above project command
project(Tutorial VERSION 1.0)
```

##### TODO 8

使用 configure_file() 命令来从 TutorialConfig.h.in 生成 TutorialConfig.h 文件

```cmake
# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h
configure_file(TutorialConfig.h.in TutorialConfig.h)
```

##### TODO 9

TutorialConfig.h 会在构建目录中生成，因此需要将该目录加入到头文件的搜索路径。

```cmake
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```

其中变量 `PROJECT_BINARY_DIR` 就是构建目录的路径。

##### TODO 10

在 TutorialConfig.h.in 文件中加入以下的语句，这是两个宏定义，在编译的过程中这两个宏会被分别替换为工程的主版本和次版本号。

```c++
// the configured options and settings for Tutorial
// TODO 10: Define Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

##### TODO 11

在 `tutorial.cxx` 中包含头文件 `TutoroalConfig.h`.

```c++
// TODO 11: Include TutorialConfig.h
#include "TutorialConfig.h"
```

##### TODO 12

在 `tutorial.cxx` 中添加代码，输出工程的版本号。

```c++
// report version
std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
```

#### 验证

按照练习一中的方式构建并运行程序

```bash
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake ../Step1
-- Configuring done
-- Generating done
-- Build files have been written to: /home/lqm/develop/c/cmake/tutorial/Step1_build
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ cmake --build .
Scanning dependencies of target Tutorial
[ 50%] Building CXX object CMakeFiles/Tutorial.dir/tutorial.cxx.o
[100%] Linking CXX executable Tutorial
[100%] Built target Tutorial
lqm@VM-8-15-centos:~/develop/c/cmake/tutorial/Step1_build$ ./Tutorial
./Tutorial Version 1.0
Usage: ./Tutorial number
```
