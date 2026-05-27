cmake_minimum_required(VERSION 3.31)
project(RepartiendoElBotin C)

set(CMAKE_C_STANDARD 11)

add_executable(RepartiendoElBotin main.c
        elemento.c
        elemento.h
        cola.c
        cola.h)
