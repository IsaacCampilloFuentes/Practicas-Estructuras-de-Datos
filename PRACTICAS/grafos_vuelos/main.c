#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tGrafo.h"

#define DIM 100

//void quitarCaracteresFinales(char cadena[DIM]);

int main(void) {
    tGrafo g;
    crearGrafoVacio(&g);
    char compania[DIM], norig[MAX], ndest[MAX];
    tCiudad orig, dest;
    int tiempo, precio;
    tVuelo vuelo;
    int fcontrol = 0;

    FILE *listadoVuelos = fopen("vuelos.txt", "r");
    char linea[DIM];
    int contadorLinea = 1;

    if (listadoVuelos == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    //la estructura del fichero es:
    //  1ºLínea: Ciudad Origen
    //  2ªLínea: Ciudad Destino
    //  3ªLínea: Compañia
    //  4ªLínea: Tiempo (en minutos)
    //  5ªLínea: Precio (sin decimales)

    /*while no sea fin de fichero
     *  leer una linea
     *  crear ciudad A
     *  insertar Ciudad A en grafo g
     *  leer una linea
     *  crear ciudad B
     *  leer tres lineas siguientes
     *  crear vuelo v
     *  insertarVuelo(&g, A, B, vuelo); //es un insertar arista del grafo que a su vez llama a insertarCiudadAdy en ListaAdy
     */

    /*while (fgets(linea, DIM, listadoVuelos) != NULL) {
        if (contadorLinea == 1) {
            quitarCaracteresFinales(linea);
            insertarCiudad(&g, linea);
            asignarCiudad(&orig, linea);
        } else if (contadorLinea == 2) {
            quitarCaracteresFinales(linea);
            insertarCiudad(&g, linea);
            asignarCiudad(&dest, linea);
        } else if (contadorLinea == 3) {
            quitarCaracteresFinales(linea);
            strcpy (compania, linea);
        } else if (contadorLinea == 4) {
            tiempo = atoi (linea);
        } else if (contadorLinea == 5) {
            precio = atoi (linea);

            contadorLinea = 0;

            crearVuelo(&vuelo, compania, tiempo, precio);
            insertarVuelo(&g, dest, orig, vuelo);
        }
        contadorLinea++;
    }*/

    while (fcontrol != EOF) {
        fcontrol = fscanf(listadoVuelos, "%s", norig);
        crearCiudad(&orig, norig);
        insertarCiudad(&g, orig);

        fcontrol = fscanf(listadoVuelos, "%s", ndest);
        crearCiudad(&dest, ndest);
        insertarCiudad(&g, dest);

        fcontrol = fscanf(listadoVuelos, "%s", compania);
        fcontrol = fscanf(listadoVuelos, "%d", &tiempo);
        fcontrol = fscanf(listadoVuelos, "%d", &precio);
        crearVuelo(&vuelo, compania, tiempo, precio);
        insertarVuelo(&g, dest, orig, vuelo);
    }

    tCiudad madrid;
    char mad[DIM] = "Madrid";
    crearCiudad(&madrid, mad);
    mostrarVuelosDirectosCiudad(g, madrid);
    mostrarVuelosConUnaEscalaCiudad(g, madrid);

    return 0;
}

/*void quitarCaracteresFinales(char cadena[DIM]) {
    cadena[strlen(cadena) - 1] = '\0';
}*/