//
// Created by i.campillo.2025 on 23/03/2026.
//

#include "tElemento.h"
#include  <string.h>

void crearElemento(char nombre[MAX], char apellidos[MAX], int edad, char motivo[MAX], tFecha fecha, tElemento *elemento) {
    strcpy (elemento->nombre, nombre);
    strcpy (elemento->apellidos, apellidos);
    elemento->edad = edad;
    strcpy (elemento->motivo, motivo);
    asignarFecha(&(elemento->fecha), fecha);
}