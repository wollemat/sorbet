cmake_minimum_required(VERSION 3.15)
project(sorbet)

set(CMAKE_C_STANDARD 11)

add_executable(sorbet src/main.c)
