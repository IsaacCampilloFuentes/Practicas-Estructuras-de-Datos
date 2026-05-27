//
// Created by i.campillo.2025 on 07/04/2026.
//

#include "fecha.h"

void crearFecha (tFecha *fecha, int dia, int mes, int ano) {
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->ano = ano;
}
void asignarFecha (tFecha *dest, tFecha orig) {
    dest->dia = orig.dia;
    dest->mes = orig.mes;
    dest->ano = orig.ano;
}