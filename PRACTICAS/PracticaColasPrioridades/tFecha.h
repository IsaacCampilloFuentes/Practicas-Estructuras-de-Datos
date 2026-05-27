//
// Created by i.campillo.2025 on 23/03/2026.
//

#ifndef TFECHA_H
#define TFECHA_H

typedef struct tFecha {
    int dia;
    int mes;
    int anno;
} tFecha;

void crearFecha (int dia, int mes, int anno, tFecha *fecha);
void asignarFecha (tFecha *destino, tFecha origen);

#endif //TFECHA_H
