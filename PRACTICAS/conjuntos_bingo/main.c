#include <stdio.h>
#include "tBingo.h"

int main(void) {
    tConjunto salida;

    //la salida es todas las restas posibles

    int bolas[] = {5, 6, 7, 8, 9, 12, 14, 15, 26, 72, 75, 82, 90, 91, 92};
    int n = 15;

    crearConjuntoVacio(&salida);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int resta;
            if (bolas[i] > bolas[j]) {
                resta = bolas[i] - bolas[j];
            } else {
                resta = bolas[j] - bolas[i];
            }
            poner(&salida, resta);
        }
    }
}