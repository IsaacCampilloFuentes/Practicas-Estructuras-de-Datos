//
// Created by i.campillo.2025 on 04/04/2026.
//

#ifndef PILA_H
#define PILA_H

#include "elemento.h"

typedef struct Nodo {
    tElemento info;
    struct Nodo *ant;
}tNodoP;

typedef tNodoP *tPila;

void crearPilaVacia(tPila *p);
int esPilaVacia(tPila p);
//apilar
void push(tPila *p, tElemento elem);
//desapilar
void pop(tPila *p); //parcial
void cima(tElemento *elem, tPila p); //parcial

#endif //PILA_H
