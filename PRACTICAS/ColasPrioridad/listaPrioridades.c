//
// Created by i.campillo.2025 on 07/04/2026.
//

#include "listaPrioridades.h"
#include <stdlib.h>

void crearListaVacia (tListaPrioridad *l) {
    l->principio = NULL;
    l->fin = NULL;
}
int esListaVacia (tListaPrioridad l) {
    return l.principio == NULL;
}
void insertarPrioridad (tListaPrioridad *l, tPrioridad pr) {
    tNodoPrioridad *nuevo = (tNodoPrioridad *) malloc(sizeof(tNodoPrioridad));
    asignarPrioridad(&(nuevo->prioridad), pr);
    crearColaVacia(&(nuevo->colaPrioridad));

    if (esListaVacia(*l)) {
        nuevo->sigPrioridad = NULL;
        l->principio = nuevo;
        l->fin = nuevo;
    } else {
        tNodoPrioridad *ant = NULL;
        tNodoPrioridad *act = l->principio;

        while (act != NULL && esMenorPrioridad(nuevo->prioridad, act->prioridad)) {
            ant = act;
            act = act->sigPrioridad;
        }
        if (act == l->principio) {
            nuevo->sigPrioridad = l->principio;
            l->principio = nuevo;
        } else if (act == NULL) {
            nuevo->sigPrioridad = act;
            ant->sigPrioridad = nuevo;
            l->fin = nuevo;
        } else {
            nuevo->sigPrioridad = act;
            ant->sigPrioridad = nuevo;
        }
    }
}
//void mezclar (tListaPrioridad *l, tListaPrioridad l1, tListaPrioridad l2);

//FUNCION PARCIAL
//no se puede haber accedido a insertar Elemento sin insertarPrioridad con el mismo pr y por tanto tampoco si es vacia y por tanto tampoco si no se ha inicializado a vacia
void insertarElemento (tListaPrioridad *l, tPrioridad pr, tElemento elem) {
    tNodoPrioridad *aux = l->principio;

    while (esMenorPrioridad(pr, aux->prioridad) || esMenorPrioridad(aux->prioridad, pr)) {
        //si A no es menor que B y B no es menor que A, entonces A es igual a B i.e) si !(A<B) y !(B<A) -> A=B
        aux = aux->sigPrioridad;
    }
    insertar(&(aux->colaPrioridad), elem);
}
//FUNCION PARCIAL
void eliminarElemento (tListaPrioridad *l, tPrioridad pr) {
    tNodoPrioridad *aux = l->principio;

    while (esMenorPrioridad(pr, aux->prioridad) || esMenorPrioridad(aux->prioridad, pr)) {
        //si A no es menor que B y B no es menor que A, entonces A es igual a B i.e) si !(A<B) y !(B<A) -> A=B
        aux = aux->sigPrioridad;
    }
    eliminar(&(aux->colaPrioridad));
}
//FUNCION PARCIAL
//devuelve 1 si se ha encontrado una cola de prioridad coincidente y 0 si no
int getColaPrioridad (tCola **c, tListaPrioridad l, tPrioridad pr) {
    int valorRetorno = 0;
    if (!esListaVacia(l)) {
        tNodoPrioridad *aux = l.principio;
        while (aux->prioridad != pr) {
            aux = aux->sigPrioridad;
        }
        if (aux->prioridad == pr) {
            *c = &(aux->colaPrioridad);
            valorRetorno = 1;
        }
    }
    return valorRetorno;
}