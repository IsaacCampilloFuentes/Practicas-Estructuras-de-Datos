#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "pila.h"
#include "elemento.h"

#define DIM 100

int main(void) {
    char x2[DIM] = "BnodJo s, dBneam";
    puts(x2);

    tLista x1, x1_1, x1_2;
    crearVacia(&x1);
    crearVacia(&x1_1);
    crearVacia(&x1_2);

    //dividimos en dos partes y concatenamos

    for (int i = 0; i<strlen(x2); i++) {
        if ((i % 2) == 0) {
            insertarFinal(&x1_1, x2[i]);
        }
    }
    for (int i = 0; i<strlen(x2); i++) {
        if ((i % 2) != 0) {
            construir(&x1_2, x2[i]);
        }
    }

    concatenar(&x1, x1_1, x1_2);

    mostrarLista(x1);
    printf("\n");

    tPila aux;
    crearPilaVacia(&aux);

    char x[strlen(x2)+1];
    tElemento elem, c;
    int j = 0;

    for (int i = 0; i<strlen(x2); i++) {
        primero (&elem, x1);
        resto(&x1);

        if (!esVocal(elem)) {
            push(&aux, elem);
        } else {
            while (!esPilaVacia(aux)) {
                cima(&c, aux);
                x[j] = c;
                pop(&aux);
                j++;
            }
            x[j] = elem;
            j++;
        }
    }
    while (!esPilaVacia(aux)) {
        cima(&c, aux);
        x[j] = c;
        pop(&aux);
        j++;
    }
    x[j]='\0';

    puts(x);

    return 0;
}

