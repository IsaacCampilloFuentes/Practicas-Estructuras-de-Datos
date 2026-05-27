cmake_minimum_required(VERSION 3.31)
project(ColasPrioridad C)

set(CMAKE_C_STANDARD 11)

add_executable(ColasPrioridad main.c
        elemento.c
        elemento.h
        fecha.c
        fecha.h
        prioridad.c
        prioridad.h
        colaCircular.c
        colaCircular.h
        listaPrioridades.c
        listaPrioridades.h
        hospital.c
        hospital.h
)
