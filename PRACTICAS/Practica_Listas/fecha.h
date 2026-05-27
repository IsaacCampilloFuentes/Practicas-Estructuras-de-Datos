//
// Created by i.campillo.2025 on 09/03/2026.
//

#ifndef FECHA_H
#define FECHA_H

typedef struct {
    int dia;
    int mes;
    int anyo;
}tFecha;

void crearFecha(int dia, int mes, int anyo, tFecha* fecha);
void imprimirFecha(tFecha fecha);

#endif //FECHA_H
