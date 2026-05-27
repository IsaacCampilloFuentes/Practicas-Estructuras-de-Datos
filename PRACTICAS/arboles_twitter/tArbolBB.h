//
// Created by i.campillo.2025 on 18/05/2026.
//

#ifndef TARBOLBB_H
#define TARBOLBB_H

#include "tElemento.h"

typedef struct nodo {
    tElemento info;
    struct nodo *izq, *der;
} tNodo;

typedef tNodo *tArbolBB;

void crearArbolBBVacio(tArbolBB *a);
int esArbolBBVacio(tArbolBB a);
void raiz(tArbolBB a, tElemento *r);
void hijoIzq(tArbolBB a, tArbolBB *i);
void hijDer(tArbolBB a, tArbolBB *d);
void construirArbolBB(tArbolBB *a, tArbolBB i, tElemento r, tArbolBB d);
void insertarArbolBB(tArbolBB *a, tElemento e);

#endif //TARBOLBB_H
