#include <stdio.h>
#include "tGrafo.h"

#define MAX 50

void limpiarSaltoLinea(char *cadena);

int main(void) {
    FILE *pFichero;
    char filename[20]; // Buffer suficiente para "L12.txt" + '\0'
    char estacion[MAX];
    tGrafo redMetro;
    tElemento eIni, eAnt, eAct;

    crearGrafoVacio(&redMetro);

    //se trata de reconstruir la red de metro de Madrid

    for (int i = 1; i <= 12; i++) {
        // Genera el nombre del archivo: L1.txt, L2.txt ... hasta L12.txt
        sprintf(filename, "L%d.txt", i);

        pFichero = fopen(filename, "r");

        if (pFichero == NULL) {
            printf("No se pudo abrir el archivo: %s\n", filename);
            continue; // Pasa al siguiente archivo si este falla
        }

        //lectura fichero
        //punto importante: en el fichero las estaciones estan en orden
        if (fgets(estacion, sizeof(estacion), pFichero) != NULL) {
            limpiarSaltoLinea(estacion);
            crearElemento(eIni, estacion, i);
            insertarOrigen(&redMetro, eIni);
            asignarElemento(&eAnt, eIni);      // Guardamos para la siguiente conexión

            // 2. EL RESTO CONECTAN CON LA ANTERIOR
            while (fgets(estacion, sizeof(estacion), pFichero) != NULL) {
                limpiarSaltoLinea(estacion);
                crearElemento(eAct, estacion, i);
                insertarOrigen(&redMetro, eAct);
                insertarDestino(&redMetro, eAnt, eAct);
                asignarElemento(&eAnt, eAct);
            }

            // 3. TRATAR LA ÚLTIMA LÍNEA (Cerrar el ciclo o no)
            if ((i == 6) || (i == 12)) { //al ser la L6 y L12 las únicas circulares de Madrid
                insertarDestino(&redMetro, eAct, eIni);
            }
        }
        fclose(pFichero);
    }

    return 0;
}

void limpiarSaltoLinea(char *cadena) {
    size_t longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
}