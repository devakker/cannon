cmake_minimum_required(VERSION 3.15)
project(cannon C)

set(CMAKE_C_STANDARD 11)

add_executable(cannon main.c cannon.c cannon.h)
add_executable(tests tests.c cannon.c cannon.h miniunit.h)