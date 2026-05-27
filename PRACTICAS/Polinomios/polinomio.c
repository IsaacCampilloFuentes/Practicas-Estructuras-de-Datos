//
// Created by i.campillo.2025 on 03/04/2026.
//

#include "polinomio.h"
#include "listaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Lee por teclado un polinomio
tPolinomio *leerPolinomio() {
    tPolinomio *p = (tPolinomio *) malloc(sizeof(tPolinomio));
    crearVacia(p);
    char respuesta;

    printf("¿Quieres añadir un término? (y/n)\n");
    scanf(" %c", &respuesta);

    while (respuesta == 'y' || respuesta == 'Y') {
        tElemento e;
        leerElemento(&e);

        insertarOrd(p, e);

        printf("¿Quieres añadir otro término? (y/n)\n");
        scanf(" %c", &respuesta);
    }

    return p;
}

// Muestra por pantalla un polinomio
void mostrar(tPolinomio p) {
    mostrarLista(p);
}

//nota a posteriori: no queda otra que romper el encapsulado en estas ultimas funciones

// Devuelve la derivada de un polinomio
void derivada(tPolinomio *pd, tPolinomio p) {
    tNodo *nuevo = NULL;
    crearVacia(*pd);
    tNodo *ant = NULL;
    for (tNodo *aux = p; aux != NULL; aux = aux->sig) {
        nuevo = (tNodo *)malloc(sizeof(tNodo));
        derivadaTermino(&(nuevo->info), aux->info);
        if (*pd == NULL) {
            *pd = nuevo;
            ant = nuevo;
        } else {
            ant->sig = nuevo;
            ant = ant->sig;
        }
        nuevo->sig = NULL;
    }
}

// Devuelve el valor de un polinomio aplicado a un valor x
float valor(tPolinomio p, float x) {
    float sum = 0.0;
    float c;
    int e;
    for (tNodo *aux = p; aux != NULL; aux = aux->sig) {
        c=getCoeficiente(aux->info);
        e=getExponente(aux->info);
        sum += c*pow(x, e);
    }
    return sum;
}
// Devuelve la suma de dos polinomios
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2) {
}