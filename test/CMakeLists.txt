cmake_minimum_required(VERSION 3.10)
project(main VERSION 0.1)

configure_file(config.h.in config.h)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(main main.c)

target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}")
