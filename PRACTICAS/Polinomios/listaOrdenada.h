//
// Created by i.campillo.2025 on 03/04/2026.
//

#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "elemento.h"

typedef struct nodo{
    tElemento info;
    struct nodo *sig;
}tNodo;

typedef tNodo *tListaOrd;

void crearVacia (tListaOrd *l);
int esListaVacia (tListaOrd l);
void insertarOrd (tListaOrd *l, tElemento elem);
void copiarLista (tListaOrd *dest, tListaOrd orig);
void mezclar (tListaOrd *l, tListaOrd l1, tListaOrd l2);
void mostrarLista (tListaOrd l);

#endif //LISTAORDENADA_H
