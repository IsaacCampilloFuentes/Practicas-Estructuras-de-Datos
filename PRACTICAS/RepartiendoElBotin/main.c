#include "cola.h"

#define LIM 50

int main(void) {
    int numSecuaces;

    printf ("Dime el numero de secuaces de la banda:\n");
    scanf ("%d", &numSecuaces);
    getchar();

    char nombre[LIM];
    tElemento secuaz;
    tCola banda;
    crearColaVacia (&banda);

    for (int i = 0; i<numSecuaces; i++) {
        printf ("Nombre:\n");
        gets (nombre);
        crearElemento (&secuaz, nombre);
        insertar (&banda, secuaz);
    }

    int numBilletes;

    printf ("Vamos a ver el botin\n");
    printf ("Numero de billetes:\n");
    scanf (" %d", &numBilletes);

    int billetes[numBilletes];

    for (int i = 0; i<numBilletes; i++) {
        printf ("Billete %d:\n", i+1);
        scanf ("%d", &billetes[i]);
    }

    //repartimos los billetes
    //primeroCola, luego eliminar y luego insertar
    for (int i = 0; i<numBilletes; i++) {
        primeroCola (&secuaz, banda);
        eliminar (&banda);
        darBillete (&secuaz, billetes[i]);
        insertar (&banda, secuaz);
    }

    //volvemos a la posicion inicial antes de mostrar el resultado
    int rotacionesNecesarias = (numSecuaces - (numBilletes % numSecuaces)) % numSecuaces;

    for (int i = 0; i < rotacionesNecesarias; i++) {
        primeroCola (&secuaz, banda);
        eliminar (&banda);
        insertar (&banda, secuaz);
    }

    mostrarCola (banda);

    return 0;
}