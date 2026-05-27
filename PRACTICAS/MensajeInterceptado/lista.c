//
// Created by i.campillo.2025 on 04/04/2026.
//

#include "lista.h"
#include <stdlib.h>
#include "elemento.h"

void crearVacia (tLista *l) {
    *l = NULL;
}
int esVacia (tLista l) {
    return l == NULL;
}
void construir (tLista *l, tElemento elem) {
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&(nuevo->info), elem);

    if (esVacia(*l)) {
        *l = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = (*l)->sig;
        (*l)->sig = nuevo;
    }
}
void insertarFinal (tLista *l, tElemento elem) {
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&(nuevo->info), elem);

    if (esVacia(*l)) {
        *l = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = (*l)->sig;
        (*l)->sig = nuevo;
        (*l) = nuevo;
    }
}

void mostrarLista (tLista l) {
    if (!esVacia(l)) {
        tNodo *aux;
        aux = l->sig;
        do {
            mostrarElemento(aux->info);
            aux = aux->sig;
        } while (aux != l->sig);
    }
}

void concatenar(tLista *l, tLista l1, tLista l2) {
    tNodo *aux;
    if (!esVacia(l1)) {
        aux = l1->sig;
        do {
            insertarFinal(l, aux->info);
            aux = aux->sig;
        } while (aux != l1->sig);
    }
    if (!esVacia(l2)) {
        aux = l2->sig;
        do {
            insertarFinal(l, aux->info);
            aux = aux->sig;
        } while (aux != l2->sig);
    }
}
void primero (tElemento *elem, tLista l) {
    if (!esVacia(l)) {
        asignarElemento(elem, l->sig->info);
    }
}
void resto (tLista *l) {
    if (!esVacia(*l)) {
        tNodo *aux = (*l)->sig;

        if (*l == aux) {
            free(aux);
            *l = NULL;
        } else {
            (*l)->sig = aux->sig;
            free(aux);
        }
    }
}
void destruir (tLista *l) {
    while (!esVacia(*l)) {
        resto(l);
    }
}