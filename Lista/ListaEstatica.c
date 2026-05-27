//
// Created by i.campillo.2025 on 25/02/2026.
//

#include "ListaEstatica.h"

void crearListaVacia(tListaEstatica *l) {
    l->posOcupada = -1;
}
void construir(tListaEstatica *l, tElemento elem) {
    if (l->posOcupada < DIM) {
        l->posOcupada++;
        *(l->elemento + l->posOcupada) = elem;
    }
}

void obtenerPrimeroLista(tListaEstatica l, tElemento* elem){
    if (esListaVacia(l) == 0) {
        *elem = *(l->elemento);
    }
}
void obtenerRestoLista (tListaEstatica *res, tListaEstatica l) {
    
}
void obtenerUltimoLista(tListaEstatica l, tElemento* elem) {
    if (esListaVacia(l) == 0) {
        *elem = *(l->elemento + l->posOcupada);
    }
}

int esListaVacia(tListaEstatica l) {
    return l->posOcupada == -1;
}
int longitudLista (tListaEstatica l) {
    return l->posOcupada;
}
int perteneceLista (tElemento e, tListaEstatica l);

void insertarListaFinal(tListaEstatica *l, tElemento elem) {

}
int eliminarElementoLista(tListaEstatica *l, tElemento elem) {

}
void concatenarLista (tListaEstatica *l1, tListaEstatica l2) {

}
int igualLista (tListaEstatica l1, tListaEstatica l2) {

}
void asignarLista (tListaEstatica original, tListaEstatica *copia) {

}
void destruirLista(tListaEstatica *l) {

}
void mostrarLista(tListaEstatica l) {

}
