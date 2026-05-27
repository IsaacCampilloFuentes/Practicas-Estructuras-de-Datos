cmake_minimum_required(VERSION 3.31)
project(arboles_twitter C)

set(CMAKE_C_STANDARD 11)

add_executable(arboles_twitter main.c
        tArbolBB.c
        tArbolBB.h
        tLista.c
        tLista.h
        tElemento.c
        tElemento.h
        UArbolBB.c
        UArbolBB.h
)
