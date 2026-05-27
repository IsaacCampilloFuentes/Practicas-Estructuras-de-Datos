cmake_minimum_required(VERSION 3.31)
project(grafos_vuelos C)

set(CMAKE_C_STANDARD 11)

add_executable(grafos_vuelos main.c
        tGrafo.c
        tGrafo.h
        tCiudad.c
        tCiudad.h
        tListaAdyacencia.c
        tListaAdyacencia.h
        tVuelo.c
        tVuelo.h
        usoGrafo.c
        usoGrafo.h)
