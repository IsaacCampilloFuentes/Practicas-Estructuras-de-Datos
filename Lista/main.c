#include <stdio.h>
#include "ListaEstatica.h"

int main(void) {
    tListaEstatica lista;
    tElemento e1, e2, e3, e4, e5;

    crearVacia(&lista);
    crearElemento(1, e1);
    crearElemento(2, e2);
    crearElemento(3, e3);
    crearElemento(4, e4);
    crearElemento(5, e5);

    insertarInicio(&lista, e1);
    insertarInicio(&lista, e2);
    insertarInicio(&lista, e3);
    insertarInicio(&lista, e4);
    insertarInicio(&lista, e5);

    printf("Longitud: %d\n", crearVacia(&lista));
    return 0;
}