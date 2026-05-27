//
// Created by i.campillo.2025 on 27/04/2026.
//

#include "tCiudad.h"
#include <string.h>
#include <stdio.h>

void crearCiudad(tCiudad *c, char nombreCiudad[MAX]) {
    strcpy(*c, nombreCiudad);
}
void asignarCiudad(tCiudad *dest, tCiudad orig) {
    strcpy(*dest, orig);
}
int esIgualCiudad(tCiudad c1, tCiudad c2) {
    return (strcmp(c1, c2) == 0);
}

void mostrarCiudad(tCiudad c) {
    printf("%s", c);
}