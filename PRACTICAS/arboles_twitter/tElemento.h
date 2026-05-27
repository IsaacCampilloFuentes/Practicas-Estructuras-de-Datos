//
// Created by i.campillo.2025 on 18/05/2026.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#include "tLista.h"

#define DIM 50
typedef struct {
    char hashtag[DIM];
    tLista tweets;
} tElemento;

void crearElemento(tElemento *e, char hashtag[DIM], tLista tweets);
void asignarElemento(tElemento *dest, tElemento orig);
int esIgualElemento(tElemento e1, tElemento e2);
int esMayorElemento(tElemento e1, tElemento e2);

#endif //TELEMENTO_H
