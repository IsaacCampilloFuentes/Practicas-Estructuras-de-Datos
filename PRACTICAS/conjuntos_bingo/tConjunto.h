//
// Created by i.campillo.2025 on 16/05/2026.
//

#ifndef TCONJUNTO_H
#define TCONJUNTO_H

typedef struct nodo {
    int num;
    struct nodo *sig;
} tNodo;

typedef tNodo *tConjunto;

void crearConjuntoVacio(tConjunto *c);
void poner(tConjunto *c, int n);
void sacar(tConjunto *c, int *n);

#endif //TCONJUNTO_H
