//
// Created by i.campillo.2025 on 02/04/2026.
//

#ifndef TLISTA_H
#define TLISTA_H

#include "tElemento.h"

typedef struct nodo {
    tElemento info;
    struct nodo *sig;
}tNodo;

typedef struct {
    tNodo *principio;
    tNodo *fin;
}tLista;

int esVacia(tLista lista);
void registrarNoticia(tLista *lista, tElemento noticia);
void mostrarNoticias(tLista lista);
int eliminarNoticia(tLista *lista, tElemento noticia);
int numeroLectores(tLista lista);
void crearVacia(tLista *lista);

// //implementación con lista estatica (poco eficiente al borrar O(n))
//
// #define DIM 50
//
// typedef struct {
//     tElemento almacen[DIM];
//     int posOcupada;
// }tLista;
//
// void registrarNoticia(tLista *lista, tElemento noticia);
// void mostrarNoticias(tLista lista);
// int eliminarNoticia(tLista *lista, tElemento noticia);
// int numeroLectores(tLista lista);
// void crearVacia(tLista *lista);

#endif //TLISTA_H
