cmake_minimum_required(VERSION 3.21)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code main.c takuzu.c takuzu.h 4x4.c 4x4.h 8x8.c)
