//
// Created by i.campillo.2025 on 27/04/2026.
//

#ifndef TLISTAADYACENCIA_H
#define TLISTAADYACENCIA_H

#include "tCiudad.h"
#include "tVuelo.h"

typedef struct nodoAdy {
    tCiudad ciudad; //ciudad = info que va en el vertice
    tVuelo vuelo; //vuelo = info que va en la arista
    struct nodoAdy *sigAdy;
}tNodoAdy;

typedef tNodoAdy *tListaAdy;

void crearListaVacia(tListaAdy *l);
void constuir(tListaAdy *l, tCiudad c, tVuelo v);
void mostrarVuelosAdy(tListaAdy l);

#endif //TLISTAADYACENCIA_H
