//
// Created by i.campillo.2025 on 07/04/2026.
//

#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H

#include "elemento.h"

typedef struct nodo {
    tElemento info;
    struct nodo *sig;
} tNodo;

typedef tNodo *tCola;

//sigue metodología FIFO
void crearColaVacia (tCola *c);
int esColaVacia (tCola c);
void insertar (tCola *c, tElemento elem); //se pone al final de la cola (FIFO)
void eliminar (tCola *c); //sale el primero (FIFO)

#endif //COLACIRCULAR_H
