//
// Created by i.campillo.2025 on 25/02/2026.
//

#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include "tElemento.h"
#define DIM 50

typedef struct {
    tElemento elemento[DIM];
    int posOcupada;
} tListaEstatica;

void crearListaVacia(tListaEstatica *l);
void construir(tListaEstatica *l, tElemento elem);

void obtenerPrimeroLista(tListaEstatica l, tElemento* elem);
void obtenerRestoLista (tListaEstatica *res, tListaEstatica l);
void obtenerUltimoLista(tElemento *e, tListaEstatica l);

int esListaVacia(tListaEstatica l);
int longitudLista (tListaEstatica l);
int perteneceLista (tElemento e, tListaEstatica l);

void insertarListaFinal(tListaEstatica *l, tElemento elem);
int eliminarElementoLista(tListaEstatica *l, tElemento elem);
void concatenarLista (tListaEstatica *l1, tListaEstatica l2);
int igualLista (tListaEstatica l1, tListaEstatica l2);
void asignarLista (tListaEstatica original, tListaEstatica *copia);
void destruirLista(tListaEstatica *l);
void mostrarLista(tListaEstatica l);

#endif //LISTAESTATICA_H
