//
// Created by i.campillo.2025 on 09/05/2026.
//

#ifndef TELEMENTO_H
#define TELEMENTO_H

#define DIM 50

typedef struct {
    char nombre[DIM];
    int linea;
} tElemento;

void crearElemento(tElemento *e, char nombre[DIM], int linea);
void asignarElemento(tElemento *dest, tElemento orig);
int esIgualElemento(tElemento e1, tElemento e2);

#endif //TELEMENTO_H
