//
// Created by i.campillo.2025 on 05/04/2026.
//

#ifndef ELEMENTO_H
#define ELEMENTO_H

#define DIM 50

typedef struct {
    char nombre[DIM];
    int dinero;
}tElemento;

void crearElemento (tElemento *elem, char nombre[DIM]);
void asignarElemento (tElemento *dest, tElemento orig);
void mostrarElemento (tElemento elem);
void darBillete (tElemento *elem, int billete);

#endif //ELEMENTO_H
