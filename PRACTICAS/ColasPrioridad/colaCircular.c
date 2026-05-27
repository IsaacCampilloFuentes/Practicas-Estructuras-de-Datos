//
// Created by i.campillo.2025 on 07/04/2026.
//

#include "colaCircular.h"
#include <stdlib.h>

void crearColaVacia (tCola *c) {
    *c = NULL;
}
int esColaVacia (tCola c) {
    return c == NULL;
}
void insertar (tCola *c, tElemento elem) {
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&(nuevo->info), elem);

    if (esColaVacia(*c)) {
        nuevo->sig = nuevo;
        *c = nuevo;
    } else {
        nuevo->sig = (*c)->sig;
        (*c)->sig = nuevo;
        (*c) = nuevo;
    }
}
void eliminar (tCola *c) {
    if (!esColaVacia(*c)) {
        tNodo *aux = (*c)->sig;
        (*c)->sig = aux->sig;
        if (aux == *c) {
            *c = NULL;
        }
        free(aux);
    }
}