//
// Created by i.campillo.2025 on 02/04/2026.
//

#include "tElemento.h"
#include <string.h>
#include <stdio.h>
#include "tFecha.h"

void asignarElemento(tElemento *destino, tElemento origen) {
    strcpy(destino->titulo, origen.titulo);
    asignarFecha(&(destino->fecha), origen.fecha);
    strcpy(destino->medio, origen.medio);
    destino->numLectores = origen.numLectores;
}
void mostrarNoticia(tElemento noticia) {
    printf("%s, ", noticia.titulo);
    mostrarFecha(noticia.fecha);
    printf(", ");
    printf("%s, ", noticia.medio);
    printf("%d \n", noticia.numLectores);
}
int esIgualElemento(tElemento n1, tElemento n2) {
    int igual = 0;
    if (strcmp(n1.titulo, n2.titulo) == 0) {
        igual = 1;
    }
    return igual;
}
int obtenerLectores(tElemento noticia) {
    return noticia.numLectores;
}

void crearNoticia(tElemento *noticia, char titulo[LIM], tFecha fecha, char medio[LIM],int numLectores) {
    strcpy(noticia->titulo, titulo);
    asignarFecha(&(noticia->fecha), fecha);
    strcpy(noticia->medio, medio);
    noticia->numLectores = numLectores;
}