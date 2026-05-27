//
// Created by i.campillo.2025 on 07/04/2026.
//

#include "elemento.h"
#include "fecha.h"
#include <string.h>

void crearElemento (tElemento *elem, char nombre[DIM], char apellidos[DIM], int edad, char motivo[DIM], tFecha fecha) {
    strcpy(elem->nombre, nombre);
    strcpy(elem->apellidos, apellidos);
    elem->edad = edad;
    strcpy(elem->motivo, motivo);
    asignarFecha(&(elem->fecha), fecha);
}
void asignarElemento (tElemento *dest, tElemento orig) {
    strcpy(dest->nombre, orig.nombre);
    strcpy(dest->apellidos, orig.apellidos);
    dest->edad = orig.edad;
    strcpy(dest->motivo, orig.motivo);
    asignarFecha(&(dest->fecha), orig.fecha);
}