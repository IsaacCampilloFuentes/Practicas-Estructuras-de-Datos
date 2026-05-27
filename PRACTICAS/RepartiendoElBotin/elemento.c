//
// Created by i.campillo.2025 on 05/04/2026.
//

#include "elemento.h"
#include <stdio.h>
#include <string.h>

void crearElemento (tElemento *elem, char nombre[DIM]) {
    strcpy (elem->nombre, nombre);
    elem->dinero = 0;
}
void asignarElemento (tElemento *dest, tElemento orig) {
    strcpy (dest->nombre, orig.nombre);
    dest->dinero = orig.dinero;
}
void mostrarElemento (tElemento elem) {
    printf ("Nombre: ");
    puts (elem.nombre);
    printf ("Dinero cobrado: %d euros\n\n", elem.dinero);
}
void darBillete (tElemento *elem, int billete) {
    elem->dinero += billete;
}