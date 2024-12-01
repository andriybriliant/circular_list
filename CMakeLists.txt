cmake_minimum_required(VERSION 3.28)
project(Circular_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(Circular_list main.c
        circular_list.c
        circular_list.h)
