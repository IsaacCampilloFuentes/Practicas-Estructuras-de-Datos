//
// Created by i.campillo.2025 on 04/04/2026.
//

#ifndef LISTA_H
#define LISTA_H

#include "elemento.h"

typedef struct nodo {
    tElemento info;
    struct nodo *sig;
}tNodo;

typedef tNodo *tLista;

void crearVacia (tLista *l);
int esVacia (tLista l);
void construir (tLista *l, tElemento elem);
void insertarFinal (tLista *l, tElemento elem);
void mostrarLista (tLista l); //parcial
void concatenar (tLista *l, tLista l1, tLista l2);
void primero (tElemento *elem, tLista l); //parcial
void resto (tLista *l); //parcial
void destruir (tLista *l);

#endif //LISTA_H
