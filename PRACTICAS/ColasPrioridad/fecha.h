//
// Created by i.campillo.2025 on 07/04/2026.
//

#ifndef FECHA_H
#define FECHA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} tFecha;

void crearFecha (tFecha *fecha, int dia, int mes, int ano);
void asignarFecha (tFecha *dest, tFecha orig);

#endif //FECHA_H
