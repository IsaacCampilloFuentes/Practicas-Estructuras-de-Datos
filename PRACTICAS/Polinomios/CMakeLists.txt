cmake_minimum_required(VERSION 3.31)
project(Polinomios C)

set(CMAKE_C_STANDARD 11)

add_executable(Polinomios main.c
        listaOrdenada.c
        listaOrdenada.h
        elemento.c
        elemento.h
        polinomio.c
        polinomio.h
)
