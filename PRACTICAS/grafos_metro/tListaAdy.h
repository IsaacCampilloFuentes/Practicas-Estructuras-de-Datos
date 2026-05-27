//
// Created by i.campillo.2025 on 07/05/2026.
//

#ifndef TLISTAADY_H
#define TLISTAADY_H

#include "tElemento.h"

typedef struct nodoAdy {
    tElemento info;
    struct nodoAdy *sig;
} tNodoAdy;

typedef tNodoAdy *tListaAdy;

void crearListaVacia(tListaAdy *l);
void construir(tListaAdy *l, tElemento e);
int pertenece(tListaAdy l, tElemento e);
void copiarLista(tListaAdy *dest, tListaAdy orig);

#endif //TLISTAADY_H
