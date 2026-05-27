//
// Created by i.campillo.2025 on 07/04/2026.
//

#include "prioridad.h"

void crearPrioridad (tPrioridad *pr, int n) {
    *pr = n;
}
void asignarPrioridad(tPrioridad *dest, tPrioridad orig) {
    *dest = orig;
}
int esMenorPrioridad (tPrioridad p1, tPrioridad p2) {
    return p1 > p2; //la prioridad 1 (rojo) es la mas alta siendo la 5 la mas baja
}