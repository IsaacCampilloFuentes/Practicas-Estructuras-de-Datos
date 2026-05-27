cmake_minimum_required(VERSION 3.31)
project(grafos_metro C)

set(CMAKE_C_STANDARD 11)

add_executable(grafos_metro main.c
        tGrafo.c
        tGrafo.h
        tListaAdy.c
        tListaAdy.h
        tElemento.c
        tElemento.h)
