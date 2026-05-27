//
// Created by i.campillo.2025 on 09/05/2026.
//

#include "tElemento.h"
#include <string.h>

void crearElemento(tElemento *e, char nombre[DIM], int linea) {
    strcpy(e->nombre, nombre);
    e->linea = linea;
}
void asignarElemento(tElemento *dest, tElemento orig) {
    strcpy(dest->nombre, orig.nombre);
    dest->linea = orig.linea;

}
int esIgualElemento(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0;
}