//
// Created by i.campillo.2025 on 18/05/2026.
//

#ifndef TARBOLBIN_H
#define TARBOLBIN_H

#include "tElemento.h"

typedef struct nodo {
    struct nodo *i;
    tElemento r;
    struct nodo *d;
} tNodo;

typedef tNodo *tArbolBin;

void crearArbolBinVacio(tArbolBin *a);
void construirArbolBin(tArbolBin *a, tArbolBin i, tElemento r, tArbolBin d);
int esArbolBinVacio(tArbolBin a);
void raiz(tArbolBin a, tElemento *r);
void hijoIzq(tArbolBin a, tArbolBin *i);
void hijoDer(tArbolBin a, tArbolBin *d);

#endif //TARBOLBIN_H
