//
// Created by i.campillo.2025 on 02/04/2026.
//

#ifndef TFECHA_H
#define TFECHA_H

typedef struct{
    int dia;
    int mes;
    int ano;
}tFecha;

void asignarFecha(tFecha *destino, tFecha origen);
void mostrarFecha(tFecha fecha);
void crearFecha(tFecha *fecha, int dia, int mes, int ano);
#endif //TFECHA_H
