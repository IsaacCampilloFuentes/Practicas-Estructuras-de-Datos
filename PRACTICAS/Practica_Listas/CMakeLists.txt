cmake_minimum_required(VERSION 3.31)
project(Practica_Listas C)

set(CMAKE_C_STANDARD 11)

add_executable(Practica_Listas main.c
        elemento.c
        elemento.h
        fecha.c
        fecha.h
        listaCircular.c
        listaCircular.h)
