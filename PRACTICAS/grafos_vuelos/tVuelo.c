//
// Created by i.campillo.2025 on 27/04/2026.
//

#include "tVuelo.h"
#include <stdio.h>
#include <string.h>

void crearVuelo(tVuelo *v, char compania[TAM], int tiempo, int precio) {
    strcpy(v->compania, compania);
    v->tiempo = tiempo;
    v->precio = precio;
}

void asignarVuelo(tVuelo *dest, tVuelo orig) {
    strcpy(dest->compania, orig.compania);
    dest->tiempo = orig.tiempo;
    dest->precio = orig.precio;
}
void mostrarVuelo(tVuelo v) {
    printf("| %s ", v.compania);
    printf("| %d ", v.tiempo);
    printf("| %d ", v.precio);
}