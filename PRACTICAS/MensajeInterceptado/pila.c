//
// Created by i.campillo.2025 on 04/04/2026.
//

#include "pila.h"
#include <stdlib.h>


void crearPilaVacia(tPila *p) {
    *p = NULL;
}
int esPilaVacia(tPila p) {
    return p == NULL;
}
void push(tPila *p, tElemento elem) {
    tNodoP *nuevo = (tNodoP *) malloc(sizeof(tNodoP));
    asignarElemento(&(nuevo->info), elem);

    if (esPilaVacia(*p)) {
        *p = nuevo;
        nuevo->ant = NULL;
    } else {
        nuevo->ant = (*p);
        (*p)= nuevo;
    }
}
void pop(tPila *p) {
    if (!esPilaVacia(*p)) {
        tNodoP *aux = *p;
        *p = (*p)->ant;
        free(aux);
    }
}
void cima(tElemento *elem, tPila p) {
    if (!esPilaVacia(p)) {
        asignarElemento(elem, p->info);
    }
}