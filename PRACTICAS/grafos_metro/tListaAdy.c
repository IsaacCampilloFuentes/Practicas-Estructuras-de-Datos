//
// Created by i.campillo.2025 on 07/05/2026.
//

#include "tListaAdy.h"
#include <stdlib.h>

void crearListaVacia(tListaAdy *l) {
    *l = NULL;
}
void construir(tListaAdy *l, tElemento e) {
    tNodoAdy *nuevo = (tNodoAdy *) malloc(sizeof(tNodoAdy));
    asignarElemento(&(nuevo->info), e);

    nuevo->sig = *l;
    *l = nuevo;
}
int pertenece(tListaAdy l, tElemento e) {
    if (l != NULL) {
        tNodoAdy *aux = l;
        while (aux != NULL && !esIgualElemento(aux->info, e)) {
            aux = aux->sig;
        }
        return aux != NULL;
    }
}
void copiarLista(tListaAdy *dest, tListaAdy orig) {
    crearListaVacia(dest);
    tNodoAdy *aux = orig;
    while (aux != NULL) {
        construir(dest, aux->info);
        aux = aux->sig;
    }
}