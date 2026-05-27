//
// Created by i.campillo.2025 on 09/03/2026.
//

#include "fecha.h"
#include <stdio.h>

void crearFecha(int dia, int mes, int anyo, tFecha* fecha) {
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->anyo = anyo;
}
void imprimirFecha(tFecha fecha) {
    printf("%d %d %d", fecha.dia, fecha.mes, fecha.anyo);
}