//
// Created by i.campillo.2025 on 07/04/2026.
//

#ifndef LISTAPRIORIDADES_H
#define LISTAPRIORIDADES_H

#include "prioridad.h"
#include "colaCircular.h"

typedef struct nodoPrioridad {
    tPrioridad prioridad;
    tCola colaPrioridad;
    struct nodoPrioridad *sigPrioridad;
} tNodoPrioridad;

typedef struct {
    tNodoPrioridad *principio;
    tNodoPrioridad *fin;
} tListaPrioridad;

//esta funciona como lista ordenada
void crearListaVacia (tListaPrioridad *l);
int esListaVacia (tListaPrioridad l);
void insertarPrioridad (tListaPrioridad *l, tPrioridad pr);
//void mezclar (tListaPrioridad *l, tListaPrioridad l1, tListaPrioridad l2);
void insertarElemento (tListaPrioridad *l, tPrioridad pr, tElemento elem); //PARCIAL
void eliminarElemento (tListaPrioridad *l, tPrioridad pr); //PARCIAL
int getColaPrioridad (tCola **c, tListaPrioridad l, tPrioridad pr); //PARCIAL

#endif //LISTAPRIORIDADES_H
