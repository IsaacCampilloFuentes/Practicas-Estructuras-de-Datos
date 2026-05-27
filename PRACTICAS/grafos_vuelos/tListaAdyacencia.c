//
// Created by i.campillo.2025 on 27/04/2026.
//

#include "tListaAdyacencia.h"
#include <stdlib.h>
#include <stdio.h>

void crearListaVacia(tListaAdy *l) {
    *l = NULL;
}

void insertarVueloAdy(tListaAdy *l, tCiudad ciudad, tVuelo vuelo) {
    //Es insertar un nodo en la lista de adyacencia
    tNodoAdy *nuevo = (tNodoAdy *)malloc(sizeof(tNodoAdy));
    asignarCiudad(&(nuevo->ciudad), ciudad);
    asignarVuelo(&(nuevo->vuelo), vuelo);

    nuevo->sigAdy = *l;
    *l = nuevo;
}
void mostrarVuelosAdy(tListaAdy l) {
    tNodoAdy *aux = l;
    while (aux != NULL) {
        printf(" ->");
        mostrarCiudad(aux->ciudad);
        printf(" ");
        mostrarVuelo(aux->vuelo);
        printf("\n");
        aux = aux->sigAdy;
    }
}