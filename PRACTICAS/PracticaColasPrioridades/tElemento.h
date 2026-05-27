//
// Created by i.campillo.2025 on 23/03/2026.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#include "tFecha.h"

#define MAX 50

typedef struct {
    char nombre[MAX];
    char apellidos[MAX];
    int edad;
    char motivo[MAX];
    tFecha fecha;
}tElemento;

void crearElemento(char nombre[MAX], char apellidos[MAX], int edad, char motivo[MAX], tFecha fecha, tElemento *elemento);

#endif //TELEMENTO_H
