//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "tArbolBB.h"
#include <stdlib.h>

void crearArbolBBVacio(tArbolBB *a) {
    *a = NULL;
}
int esArbolBBVacio(tArbolBB a) {
    return a == NULL;
}
void raiz(tArbolBB a, tElemento *r) {
    asignarElemento(r, a->info);
}
void hijoIzq(tArbolBB a, tArbolBB *i) {
    *i = a->izq;
}
void hijDer(tArbolBB a, tArbolBB *d) {
    *d = a->der;
}

void construirArbolBB(tArbolBB *a, tArbolBB i, tElemento r, tArbolBB d) {
    *a = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&((*a)->info), r);
    (*a)->izq = i;
    (*a)->der = d;
}
void insertarArbolBB(tArbolBB *a, tElemento e) {
    if (esArbolBBVacio(*a)) {
        tArbolBB vacio;
        crearArbolBBVacio(&vacio);

        construirArbolBB(a, vacio, e, vacio);
    } else {
        tElemento r;
        tArbolBB i, d;

        raiz(*a, &r);
        hijoIzq(*a, &i);
        hijDer(*a, &d);

        if (esIgualElemento(e, r)) {
            //se deja el arbol como estaba
        } else if (esMayorElemento(e, r)) {
            insertarArbolBB(&d, e);
            construirArbolBB(a, i, r, d);
        } else {
            insertarArbolBB(&i, e);
            construirArbolBB(a, i, r, d);
        }
    }
}