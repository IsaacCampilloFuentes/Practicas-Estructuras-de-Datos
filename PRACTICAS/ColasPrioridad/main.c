#include <stdio.h>
#include "hospital.h"

//MAIN HECHO POR CHATGPT PARA PROBAR LA CORRECTA FUNCIONALIDAD DEL CODIGO

// Función auxiliar exclusiva para el main para ver qué pasa por dentro
void imprimirEstadoHospital(tUrgencias l) {
    tNodoPrioridad *auxP = l.principio;
    printf("\n=== ESTADO ACTUAL DE URGENCIAS ===\n");

    while (auxP != NULL) {
        printf("Nivel %d: ", auxP->prioridad);
        if (esColaVacia(auxP->colaPrioridad)) {
            printf("[Vacio]\n");
        } else {
            // Recorremos la cola circular (el puntero apunta al último)
            tNodo *primero = auxP->colaPrioridad->sig;
            tNodo *actual = primero;
            do {
                printf("(%s %s) -> ", actual->info.nombre, actual->info.apellidos);
                actual = actual->sig;
            } while (actual != primero);
            printf("FIN\n");
        }
        auxP = auxP->sigPrioridad;
    }
    printf("==================================\n\n");
}

int main() {
    tUrgencias miHospital;
    tPaciente p; // Variable temporal para ir creando pacientes
    tFecha hoy;

    // 1. Inicializamos el hospital y la fecha
    crearFecha(&hoy, 7, 4, 2026);
    inicializarSalasUrgencias(&miHospital);

    printf("Hospital inicializado con 5 niveles de urgencia.\n");
    imprimirEstadoHospital(miHospital);

    // 2. Llegada de pacientes (Triage)
    printf("--> Llegan pacientes a Urgencias...\n");

    // Llega Luis (Prioridad 3 - Amarillo)
    encolarPaciente(&miHospital, &p, 3, "Luis", "Garcia", 34, "Fiebre", hoy);

    // Llega Ana (Prioridad 1 - Rojo)
    encolarPaciente(&miHospital, &p, 1, "Ana", "Lopez", 28, "Traumatismo", hoy);

    // Llega Carlos (Prioridad 1 - Rojo) -> Debe ir DETRAS de Ana
    encolarPaciente(&miHospital, &p, 1, "Carlos", "Ruiz", 50, "Infarto", hoy);

    // Llega Marta (Prioridad 5 - Azul)
    encolarPaciente(&miHospital, &p, 5, "Marta", "Diaz", 19, "Dolor leve", hoy);

    // Verificamos que se han ordenado bien
    imprimirEstadoHospital(miHospital);

    // 3. Los médicos empiezan a llamar
    printf("--> El medico llama al siguiente paciente...\n");
    atenderPaciente(&miHospital); // Debería salir Ana (Prioridad 1)
    imprimirEstadoHospital(miHospital);

    printf("--> El medico llama al siguiente paciente...\n");
    atenderPaciente(&miHospital); // Debería salir Carlos (Prioridad 1)
    imprimirEstadoHospital(miHospital);

    printf("--> El medico llama al siguiente paciente...\n");
    atenderPaciente(&miHospital); // Debería saltar al nivel 3 y sacar a Luis
    imprimirEstadoHospital(miHospital);

    return 0;
}