cmake_minimum_required(VERSION 3.31)
project(MensajeInterceptado C)

set(CMAKE_C_STANDARD 11)

add_executable(MensajeInterceptado main.c
        lista.c
        lista.h
        elemento.c
        elemento.h
        pila.c
        pila.h)
