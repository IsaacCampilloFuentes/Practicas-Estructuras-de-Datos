//
// Created by i.campillo.2025 on 07/04/2026.
//

#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "fecha.h"

#define DIM 50

typedef struct {
    char nombre[DIM];
    char apellidos[DIM];
    int edad;
    char motivo[DIM];
    tFecha fecha;
} tElemento;

void crearElemento (tElemento *elem, char nombre[DIM], char apellidos[DIM], int edad, char motivo[DIM], tFecha fecha);
void asignarElemento (tElemento *dest, tElemento orig);

#endif //ELEMENTO_H
