//
// Created by i.campillo.2025 on 07/05/2026.
//

#ifndef TGRAFO_H
#define TGRAFO_H

#include "tListaAdy.h"

typedef struct nodo {
    tElemento info;
    struct nodo *sig;
    tNodoAdy *ady;
} tNodo;

typedef tNodo *tGrafo;

void crearGrafoVacio(tGrafo* g);
void insertarOrigen(tGrafo* g, tElemento origen);
void insertarDestino(tGrafo* g, tElemento origen, tElemento destino);
int esGrafoVacio(tGrafo g);
int perteneceAOrigenes(tGrafo g, tElemento origen);
int perteneceADestinos(tGrafo g, tElemento origen, tElemento destino);
void listaAdyacencia(tGrafo g, tElemento origen, tListaAdy* adyacentes);

#endif //TGRAFO_H
