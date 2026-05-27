//
// Created by i.campillo.2025 on 05/04/2026.
//

#ifndef COLA_H
#define COLA_H

#include "elemento.h"

typedef struct nodo {
    tElemento info;
    struct nodo *sig;
}tNodo;

typedef tNodo *tCola;

void crearColaVacia (tCola *l);
int esColaVacia (tCola l);
void mostrarCola (tCola l); //parcial
void primeroCola (tElemento *elem, tCola l); //parcial
void eliminar (tCola *l); //parcial
void insertar (tCola *l, tElemento elem);
//void copiarCola
//int igualCola

#endif //COLA_H
