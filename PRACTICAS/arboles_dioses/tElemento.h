//
// Created by i.campillo.2025 on 18/05/2026.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define DIM 250

typedef struct {
    char nombre[DIM];
    char descripcion[DIM];
} tElemento;

void crearElemento(tElemento *e, char nombre[DIM], char descripcion[DIM]);
void asignarElemento(tElemento *dest, tElemento orig);
int esIgualElemento(tElemento e1, tElemento e2);
void mostrarNombreElemento(tElemento e);

#endif //TELEMENTO_H
