//
// Created by i.campillo.2025 on 23/03/2026.
//

#include "tFecha.h"

void crearFecha (int dia, int mes, int anno, tFecha *fecha) {
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->anno = anno;
}

void asignarFecha (tFecha *destino, tFecha origen) {
    destino->dia = origen.dia;
    destino->mes = origen.mes;
    destino->anno = origen.anno;
}