//
// Created by i.campillo.2025 on 27/04/2026.
//

#ifndef TCIUDAD_H
#define TCIUDAD_H

#define MAX 100

typedef char tCiudad[MAX];

void crearCiudad(tCiudad *c, char nombreCiudad[MAX]);
void asignarCiudad(tCiudad *dest, tCiudad orig);
int esIgualCiudad(tCiudad c1, tCiudad c2);
void mostrarCiudad(tCiudad c);

#endif //TCIUDAD_H
