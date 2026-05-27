//
// Created by i.campillo.2025 on 02/04/2026.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#include "tFecha.h"

#define LIM 50

typedef struct {
    char titulo[LIM];
    tFecha fecha;
    char medio[LIM];
    int numLectores;
}tElemento;

void asignarElemento(tElemento *destino, tElemento origen);
void mostrarNoticia(tElemento noticia);
int esIgualElemento(tElemento n1, tElemento n2);
int obtenerLectores(tElemento noticia);
void crearNoticia(tElemento *noticia, char titulo[LIM], tFecha fecha, char medio[LIM],int numLectores);
#endif //TELEMENTO_H
