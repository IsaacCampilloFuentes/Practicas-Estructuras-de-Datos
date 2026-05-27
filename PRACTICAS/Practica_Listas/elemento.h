//
// Created by i.campillo.2025 on 09/03/2026.
//

#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "fecha.h"
#define MAXNOMBRE 100

typedef struct {
    char titulo[MAXNOMBRE];
    tFecha fecha;
    char medio[MAXNOMBRE];
    int visitas;
}tElemento;

void crearNoticia(char titulo[MAXNOMBRE], tFecha fecha, char medio[MAXNOMBRE], int visitas, tElemento* pnoticia);
void asignarNoticia(tElemento n1, tElemento *n2);
int igualNoticia(tElemento n1, tElemento n2);
void imprimirNoticia(tElemento n);


#endif //ELEMENTO_H
