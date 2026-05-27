//
// Created by i.campillo.2025 on 07/05/2026.
//

#include "tGrafo.h"
#include <stdlib.h>

void crearGrafoVacio(tGrafo *g) {
    *g = NULL;
}

void insertarOrigen(tGrafo* g, tElemento origen) {
    tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&(nuevo->info), origen);
    crearListaVacia(&(nuevo->ady));

    nuevo->sig = *g;
    *g = nuevo;
}

void insertarDestino(tGrafo* g, tElemento origen, tElemento destino) {
    tNodo *aux = *g;
    while (aux != NULL && !esIgualElemento(aux->info, origen)) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        construir(&(aux->ady), destino);

        // al ser grafo no dirigido conectamos tambien a la inversa
        aux = *g;
        while (aux != NULL && !esIgualElemento(aux->info, destino)) {
            aux = aux->sig;
        }
        if (aux != NULL) {
            construir(&(aux->ady), origen);
        }
    }
}

int esGrafoVacio(tGrafo g) {
    return g == NULL;
}
int perteneceAOrigenes(tGrafo g, tElemento origen) {
    if (g != NULL) {
        tNodo *aux = g;
        while (aux != NULL && !esIgualElemento(aux->info, origen)) {
            aux = aux->sig;
        }
        return aux != NULL;
    }
}
int perteneceADestinos(tGrafo g, tElemento origen, tElemento destino) {
    if (g != NULL) {
        tNodo *aux = g;
        while (aux != NULL && !esIgualElemento(aux->info, origen)) {
            aux = aux->sig;
        }
        return pertenece(aux->ady, destino);
    }
}
void listaAdyacencia(tGrafo g, tElemento origen, tListaAdy* adyacentes) {
    if (g != NULL) {
        tNodo *aux = g;
        while (aux != NULL && !esIgualElemento(aux->info, origen)) {
            aux = aux->sig;
        }
        if (aux != NULL) {
            copiarLista(adyacentes, aux->ady);
        }
    }
}