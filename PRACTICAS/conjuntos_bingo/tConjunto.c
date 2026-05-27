//
// Created by i.campillo.2025 on 16/05/2026.
//

#include "tConjunto.h"
#include <stdlib.h>

void crearConjuntoVacio(tConjunto *c) {
    *c = NULL;
}
void poner(tConjunto *c, int n) {
    tNodo *aux = *c;
    while(aux != NULL && aux->num != n) {
        aux = aux->sig;
    }
    if(aux == NULL) {
        tNodo *nuevo = (tNodo *) malloc (sizeof(tNodo));
        nuevo->num = n;

        nuevo->sig = *c;
        *c = nuevo;
    }
}

void sacar(tConjunto *c, int *n) {
    if (*c != NULL) {
        tNodo *aux = *c;
        int contadorElementos = 0;

        // 1. Contar elementos
        while (aux != NULL) {
            aux = aux->sig;
            contadorElementos++;
        }

        // 2. Elegir índice aleatorio
        int elementoASacar = rand() % contadorElementos;

        // 3. Ir al nodo
        aux = *c;
        tNodo *ant = NULL;

        for (int i = 0; i < elementoASacar; i++) {
            ant = aux;
            aux = aux->sig;
        }

        // 4. Guardar valor
        *n = aux->num;

        // 5. Eliminar nodo
        if (ant == NULL) {
            // borrar el primero
            *c = aux->sig;
        } else {
            ant->sig = aux->sig;
        }

        free(aux);
    }
}