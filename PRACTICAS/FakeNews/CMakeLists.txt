cmake_minimum_required(VERSION 3.31)
project(FakeNews C)

set(CMAKE_C_STANDARD 11)

add_executable(FakeNews main.c
        tLista.c
        tLista.h
        tElemento.c
        tElemento.h
        tFecha.c
        tFecha.h)
