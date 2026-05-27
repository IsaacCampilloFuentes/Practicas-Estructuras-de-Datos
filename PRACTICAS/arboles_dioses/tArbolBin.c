//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "tArbolBin.h"
#include <stdlib.h>

void crearArbolBinVacio(tArbolBin *a) {
    *a = NULL;
}
void construirArbolBin(tArbolBin *a, tArbolBin i, tElemento r, tArbolBin d) {
    *a = (tNodo *) malloc(sizeof(tNodo));
    (*a)->i = i;
    asignarElemento(&((*a)->r), r);
    (*a)->d = d;

}
int esArbolBinVacio(tArbolBin a) {
    return a == NULL;
}
void raiz(tArbolBin a, tElemento *r) {
    if (!esArbolBinVacio(a)) {
        *r = a->r;
    }
}
void hijoIzq(tArbolBin a, tArbolBin *i) {
    if (!esArbolBinVacio(a)) {
        *i = a->i;
    }
}
void hijoDer(tArbolBin a, tArbolBin *d) {
    if (!esArbolBinVacio(a)) {
        *d = a->d;
    }
}