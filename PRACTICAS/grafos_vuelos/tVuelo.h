//
// Created by i.campillo.2025 on 27/04/2026.
//

#ifndef TVUELO_H
#define TVUELO_H

#define TAM 50

typedef struct {
    char compania[TAM];
    int tiempo;
    int precio;
}tVuelo;

void crearVuelo(tVuelo *v, char compania[TAM], int tiempo, int precio);
void asignarVuelo(tVuelo *dest, tVuelo orig);
void mostrarVuelo(tVuelo v);

#endif //TVUELO_H
