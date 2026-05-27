//
// Created by i.campillo.2025 on 07/04/2026.
//

#include <stdio.h>
#include "hospital.h"

void inicializarSalasUrgencias (tUrgencias *salasUrgencias) {
    crearListaVacia(salasUrgencias);

    for (int i = 1; i <= 5; i++) {
        insertarPrioridad(salasUrgencias, i);
    }
}

void encolarPaciente (tUrgencias *salasUrgencias, tPaciente *paciente, tPrioridad prioridad, char nombre[DIM], char apellidos[DIM], int edad, char motivo[DIM], tFecha fechaIngreso) {
    crearElemento(paciente, nombre, apellidos, edad, motivo, fechaIngreso);

    if (esListaVacia (*salasUrgencias)) {
        inicializarSalasUrgencias(salasUrgencias);
    }

    insertarElemento(salasUrgencias, prioridad, *paciente);
}

//se cogen los pacientes por prioridad luego orden de llegada
void atenderPaciente (tUrgencias *salasUrgencias) {
    tPrioridad prioridad;
    tCola *c = NULL;
    int indicePrioridad = 1;
    int pacienteAtendido = 0;

    while (indicePrioridad <= 5 && !pacienteAtendido) {
        crearPrioridad(&prioridad, indicePrioridad);

        //si el nivel existe Y la cola no está vacía
        if (getColaPrioridad(&c, *salasUrgencias, prioridad) && !esColaVacia(*c)) {
            printf("Atendiendo a paciente de Prioridad %d\n", indicePrioridad);
            eliminar(c);
            pacienteAtendido = 1;
        }
        indicePrioridad++;
    }

    if (!pacienteAtendido) {
        printf("No hay pacientes en urgencias.\n");
    }
}