//
// Created by i.campillo.2025 on 23/03/2026.
//

#ifndef TPRIORIDAD_H
#define TPRIORIDAD_H

#define TAM 4

typedef struct {
    int color[TAM]; //cuanto mas bajo más prioridad
}tPrioridad;

void crearProridad(int numColor, tPrioridad *prioridad);

#endif //TPRIORIDAD_H
