//
// Created by i.campillo.2025 on 07/04/2026.
//

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "listaPrioridades.h"

typedef tListaPrioridad tUrgencias;
typedef tElemento tPaciente;

void inicializarSalasUrgencias (tUrgencias *salasUrgencias);
void encolarPaciente (tUrgencias *salasUrgencias, tPaciente *paciente, tPrioridad prioridad, char nombre[DIM], char apellidos[DIM], int edad, char motivo[DIM], tFecha fechaIngreso);
void atenderPaciente (tUrgencias *salasUrgencias);

#endif //HOSPITAL_H
