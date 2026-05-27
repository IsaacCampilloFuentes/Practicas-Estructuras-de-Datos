//
// Created by i.campillo.2025 on 02/04/2026.
//

#include "tLista.h"
#include "tElemento.h"
#include <stdio.h>
#include <stdlib.h>

int esVacia(tLista lista) {
    int vacia = 0;
    if (lista.principio == NULL) {
        vacia = 1;
    }
    return vacia;
}
void registrarNoticia(tLista *lista, tElemento noticia) {
    tNodo *nodo;
    nodo = (tNodo *) malloc (sizeof(tNodo));

    asignarElemento(&(nodo->info), noticia);
    nodo->sig = NULL;

    if (esVacia(*lista)) {
        lista->principio =  nodo;
        lista->fin = nodo;
    } else {
        lista->fin->sig = nodo;
        lista->fin = nodo;
    }
}
void mostrarNoticias(tLista lista) {
    tNodo *act = lista.principio;
    while (act != NULL) {
        mostrarNoticia(act->info);
        act = act->sig;
    }
}
int eliminarNoticia(tLista *lista, tElemento noticia) {
    tNodo *ant = NULL;
    tNodo *act = lista->principio;
    int encontrado = 0;

    // 1. Buscamos la noticia manteniendo a 'ant' un paso atrás
    while (act != NULL && !encontrado) {
        if (esIgualElemento(act->info, noticia)) {
            encontrado = 1;
        } else {
            ant = act;      // El actual ahora es el anterior
            act = act->sig; // El actual avanza
        }
    }

    // 2. Si la hemos encontrado, procedemos al puenteo
    if (encontrado) {
        if (ant == NULL) {
            // CASO A: Es el primer nodo
            lista->principio = act->sig;
        } else {
            // CASO B: Está en medio o al final
            ant->sig = act->sig;
        }

        // 3. Ajuste especial del puntero FIN
        if (act == lista->fin) {
            lista->fin = ant; // Si borramos el último, el nuevo fin es 'ant'
        }

        free(act); // Liberamos la memoria del nodo encontrado
    }

    return encontrado; // Devolvemos si hubo éxito o no
}
int numeroLectores(tLista lista) {
    tNodo *act = lista.principio;
    int sum = 0;
    while (act != NULL) {
        sum += obtenerLectores(act->info);
        act = act->sig;
    }
    return sum;
}
void crearVacia(tLista *lista) {
    lista->principio = NULL;
    lista->fin = NULL;
}

// //implementación con lista estatica (poco eficiente al borrar O(n))
//
// void registrarNoticia(tLista *lista, tElemento noticia) {
//     if (lista->posOcupada < DIM-1) {
//         lista->posOcupada++;
//         asignarElemento(&(lista->almacen[lista->posOcupada]), noticia);
//     }
// }
// void mostrarNoticias(tLista lista) {
//     int aux = 0;
//     while (aux <= lista.posOcupada) {
//         mostrarNoticia(lista.almacen[aux]);
//         aux++;
//     }
// }
// int eliminarNoticia(tLista *lista, tElemento noticia) {
//     int encontrado = 0;
//     int aux = 0;
//     while (aux <= lista->posOcupada && !encontrado) {
//         if (esIgualElemento(noticia, lista->almacen[aux])) {
//             encontrado = 1;
//             aux--;
//         }
//         aux++;
//     }
//     if (encontrado) {
//         while (aux < lista->posOcupada) {
//             asignarElemento(&(lista->almacen[aux]), lista->almacen[aux+1]);
//             aux++;
//         }
//         lista->posOcupada--;
//     }
//     return encontrado;
// }
// int numeroLectores(tLista lista) {
//     int num = 0;
//     for (int i=0; i <= lista.posOcupada; i++) {
//         num += obtenerLectores(lista.almacen[i]);
//     }
//     return num;
// }
//
// void crearVacia(tLista *lista) {
//     lista->posOcupada = -1;
// }