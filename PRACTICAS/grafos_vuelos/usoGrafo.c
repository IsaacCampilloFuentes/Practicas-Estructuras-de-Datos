//
// Created by i.campillo.2025 on 29/04/2026.
//

#include "usoGrafo.h"
#include "stdio.h"

void mostrarVuelosDirectosCiudad(tGrafo g, tCiudad c) {
    //primero se busca la ciudad y luego se imprime
    tNodo *aux = g;
    while (aux != NULL && !esIgualCiudad(aux->ciudad, c)) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        printf("Vuelos directos desde ");
        mostrarCiudad(aux->ciudad);
        printf(":\n");
        mostrarVuelosAdy(aux->ady);
        printf("\n");
    }
}

void mostrarVuelosConUnaEscalaCiudad(tGrafo g, tCiudad c) {
    tNodo *aux = g;
    while (aux != NULL && !esIgualCiudad(aux->ciudad, c)) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        tNodoAdy *act = aux->ady; //obtener lista
        while (act != NULL){
            mostrarVuelosDirectosCiudad(g, act->ciudad); //act->ciudad =>//obtener ciudad
            act = act->sigAdy;
        }
    }
}