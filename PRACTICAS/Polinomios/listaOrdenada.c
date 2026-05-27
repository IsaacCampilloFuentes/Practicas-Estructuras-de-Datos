//
// Created by i.campillo.2025 on 03/04/2026.
//

#include "listaOrdenada.h"
#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>

void crearVacia (tListaOrd *l) {
    *l = NULL;
}
int esListaVacia (tListaOrd l) {
    return l == NULL;
}
// void insertarOrd (tListaOrd *l, tElemento elem) {
//     tNodo *nodo;
//     nodo = (tNodo *) malloc(sizeof(tNodo));
//
//     asignarElemento(nodo->info, elem);
//
//     if (esListaVacia(*l)) {
//         *l = nodo;
//         nodo->sig = NULL;
//     } else {
//         tNodo *ant = NULL;
//         tNodo *act = *l;
//
//         while (act != NULL && esMenor(act->info, elem)) {
//             ant = act;
//             act = act->sig;
//         }
//         if (act == NULL) {
//             ant->sig = nodo;
//             nodo->sig = NULL;
//         } else if (ant == NULL) {
//             *l = nodo;
//             nodo->sig = act;
//         } else {
//             ant->sig = nodo;
//             nodo->sig = act;
//         }
//     }
// }
void insertarOrd (tListaOrd *l, tElemento elem) {
    tNodo *nodo = (tNodo *) malloc(sizeof(tNodo));
    asignarElemento(&(nodo->info), elem);

    tNodo *ant = NULL;
    tNodo *act = *l;

    while (act != NULL && esMenor(act->info, elem)) {
        ant = act;
        act = act->sig;
    }

    // --- AQUÍ VIENE LA MAGIA DE LA SIMPLIFICACIÓN ---

    // 1. El nuevo nodo SIEMPRE apunta a 'act'
    // (Si act es NULL, apunta a NULL. Si es un nodo, apunta a ese nodo).
    nodo->sig = act;

    // 2. ¿Dónde enganchamos el nuevo nodo por detrás?
    if (ant == NULL) {
        // Si ant es NULL, el nuevo nodo es el primero
        *l = nodo;
    } else {
        // Si no, va después de ant
        ant->sig = nodo;
    }
}

void copiarLista (tListaOrd *dest, tListaOrd orig) {
    tNodo *aux = orig;
    tNodo *nuevo;
    tNodo *ant = NULL;

    crearVacia(dest); // Aseguramos que empiece en NULL

    while (aux != NULL) {
        nuevo = (tNodo *) malloc(sizeof(tNodo));
        asignarElemento(&(nuevo->info), aux->info);
        nuevo->sig = NULL; // <--- ¡FUNDAMENTAL!

        if (*dest == NULL) {
            *dest = nuevo;
        } else {
            ant->sig = nuevo;
        }
        ant = nuevo;
        aux = aux->sig;
    }
}

void mezclar(tListaOrd *l, tListaOrd l1, tListaOrd l2) {
    crearVacia(l);

    // Casos base con copiarLista (¡Muy bien pensado!)
    if (esListaVacia(l1)) {
        copiarLista(l, l2);
    } else if (esListaVacia(l2)) {
        copiarLista(l, l1);
    } else {
        tNodo *aux1 = l1;
        tNodo *aux2 = l2;
        tNodo *ant = NULL;

        // Mezclamos mientras AMBAS tengan datos
        while (aux1 != NULL && aux2 != NULL) {
            tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
            nuevo->sig = NULL; // Siempre inicializa a NULL

            if (esMenor(aux1->info, aux2->info)) {
                asignarElemento(&(nuevo->info), aux1->info);
                aux1 = aux1->sig;
            } else {
                asignarElemento(&(nuevo->info), aux2->info);
                aux2 = aux2->sig;
            }

            if (*l == NULL) {
                *l = nuevo;
            } else {
                ant->sig = nuevo;
            }
            ant = nuevo;
        }

        // --- TRATAMIENTO DE SOBRANTES ---
        // Si una lista era más larga que la otra, copiamos lo que queda
        while (aux1 != NULL) {
            tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
            asignarElemento(&(nuevo->info), aux1->info);
            nuevo->sig = NULL;
            ant->sig = nuevo;
            ant = nuevo;
            aux1 = aux1->sig;
        }
        while (aux2 != NULL) {
            tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
            asignarElemento(&(nuevo->info), aux2->info);
            nuevo->sig = NULL;
            ant->sig = nuevo;
            ant = nuevo;
            aux2 = aux2->sig;
        }
    }
}

void mostrarLista (tListaOrd l) {
    for (tNodo *aux = l; aux != NULL; aux = aux->sig) {
        mostrarElemento(aux->info);
    }
}