//
// Created by i.campillo.2025 on 02/04/2026.
//

#include "tFecha.h"
#include <stdio.h>

void asignarFecha(tFecha *destino, tFecha origen) {
    destino->dia = origen.dia;
    destino->mes = origen.mes;
    destino->ano = origen.ano;
}
void mostrarFecha(tFecha fecha) {
    printf("%2d/%2d/%4d", fecha.dia, fecha.mes, fecha.ano);
}
void crearFecha(tFecha *fecha, int dia, int mes, int ano) {
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->ano = ano;
}