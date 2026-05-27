//
// Created by i.campillo.2025 on 27/04/2026.
//

#include "tGrafo.h"

#include <stdio.h>
#include <stdlib.h>

void crearGrafoVacio(tGrafo *g) {
    *g = NULL;
}

void insertarCiudad(tGrafo *g, tCiudad c) {
    //primero hay que asegurarse que la ciudad no está en el conjunto y luego insertarlo
    tNodo *aux = *g;
    while (aux != NULL && !esIgualCiudad(aux->ciudad, c)) {
        aux = aux->sig;
    }
    if (aux == NULL) {
        tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
        asignarCiudad(&(nuevo->ciudad), c);
        crearListaVacia(&(nuevo->ady));

        nuevo->sig = *g;
        *g = nuevo;
    }
}

void insertarVuelo(tGrafo *g, tCiudad dest, tCiudad orig, tVuelo vuelo) {
    //esta funcion se trata de buscar la ciudad donde queremos añadir un vuelo y luego llamar a insertarVueloAdy
    tNodo *aux = *g;

    while (aux != NULL && !esIgualCiudad(aux->ciudad, orig)) { //recorremos las ciudades del conjunto hasta encontrar la ciudad de la que se parte
        aux = aux->sig;
    }
    if (aux != NULL) { //si no ha llegado al final significa que ha encontrado la ciudad
        insertarVueloAdy(&(aux->ady), dest, vuelo);
    }
}

void mostrarGrafo(tGrafo g) {
    tNodo *aux = g;
    while (aux != NULL) {
        mostrarCiudad(aux->ciudad);
        printf(":\n");
        mostrarVuelosAdy(aux->ady);
        printf("\n");
        aux = aux->sig;
    }
}
