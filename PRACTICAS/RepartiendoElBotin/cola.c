//
// Created by i.campillo.2025 on 05/04/2026.
//

#include "cola.h"
#include <stdlib.h>

void crearColaVacia (tCola *l) {
    *l = NULL;
}
int esColaVacia (tCola l) {
    return l == NULL;
}
void mostrarCola (tCola l) {
    if (!esColaVacia(l)) {
        tNodo *aux = l->sig;
        do {
            mostrarElemento (aux->info);
            aux = aux->sig;
        } while (aux != l->sig);
    }
}
void primeroCola (tElemento *elem, tCola l) {
    if (!esColaVacia(l)) {
        asignarElemento(elem, l->sig->info);
    }
}
void eliminar (tCola *l) {
    if (!esColaVacia(*l)) {
        tNodo *aux = (*l)->sig;
        (*l)->sig = aux->sig;
        if (*l == aux) {
            *l = NULL;
        }
        free(aux);
    }
}
void insertar (tCola *l, tElemento elem) {
    tNodo *nuevo = (tNodo *) malloc (sizeof(tNodo));
    asignarElemento (&(nuevo->info), elem);

    if (esColaVacia(*l)) {
        *l = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = (*l)->sig;
        (*l)->sig = nuevo;
        *l = nuevo;
    }
}