cmake_minimum_required(VERSION 3.31)
project(arboles_dioses C)

set(CMAKE_C_STANDARD 11)

add_executable(arboles_dioses main.c
        tElemento.c
        tElemento.h
        tArbolBin.c
        tArbolBin.h)
