cmake_minimum_required(VERSION 3.31)
project(Lista C)

set(CMAKE_C_STANDARD 11)

add_executable(Lista main.c
        tElemento.c
        tElemento.h
        ListaEstatica.c
        ListaEstatica.h
)
