//
// Created by i.campillo.2025 on 18/05/2026.
//

#ifndef TLISTA_H
#define TLISTA_H

#define MAX 141

typedef struct nodoLista {
    char tweet[MAX];
    struct nodoLista *sig;
} tNodoLista;

typedef tNodoLista *tLista;

void crearListaVacia(tLista *l);
void insertarTweet(tLista *l, char tweet[MAX]);

#endif //TLISTA_H
