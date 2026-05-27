cmake_minimum_required(VERSION 3.31)
project(PracticaColasPrioridades C)

set(CMAKE_C_STANDARD 11)

add_executable(PracticaColasPrioridades main.c
        tElemento.c
        tElemento.h
        tFecha.c
        tFecha.h
        tPrioridad.c
        tPrioridad.h
        tCola.c
        tCola.h)
