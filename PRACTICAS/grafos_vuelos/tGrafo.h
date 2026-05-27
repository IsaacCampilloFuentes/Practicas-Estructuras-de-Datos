//
// Created by i.campillo.2025 on 27/04/2026.
//

#ifndef TGRAFO_H
#define TGRAFO_H

#include "tCiudad.h"
#include "tVuelo.h"
#include "tListaAdyacencia.h"

typedef struct nodo {
    tCiudad ciudad;
    tNodoAdy *ady;
    struct nodo *sig;
} tNodo;

typedef tNodo *tGrafo;

void crearGrafoVacio(tGrafo *g);
void insertarCiudad(tGrafo *g, tCiudad c);
void insertarVuelo(tGrafo *g, tCiudad c1, tCiudad c2, tVuelo vuelo);
void mostrarGrafo(tGrafo g);

#endif //TGRAFO_H
