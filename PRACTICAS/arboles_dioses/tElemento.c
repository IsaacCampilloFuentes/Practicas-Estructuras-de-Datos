//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "tElemento.h"
#include <string.h>
#include <stdio.h>

void crearElemento(tElemento *e, char nombre[DIM], char descripcion[DIM]) {
    strcpy(e->nombre, nombre);
    strcpy(e->descripcion, descripcion);
}
void asignarElemento(tElemento *dest, tElemento orig) {
    strcpy(dest->nombre, orig.nombre);
    strcpy(dest->descripcion, orig.descripcion);
}
int esIgualElemento(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0;
}
void mostrarNombreElemento(tElemento e) {
    printf("%s", e.nombre);
}