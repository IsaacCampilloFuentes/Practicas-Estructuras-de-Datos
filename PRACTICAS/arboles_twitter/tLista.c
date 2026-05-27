//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "tLista.h"
#include <stdlib.h>
#include <string.h>

void crearListaVacia(tLista *l) {
    *l = NULL;
}
void insertarTweet(tLista *l, char tweet[MAX]) {
    tNodoLista *nuevo = (tNodoLista *) malloc(sizeof(tNodoLista));
    strcpy(nuevo->tweet, tweet);

    nuevo->sig = *l;
    *l = nuevo;
}