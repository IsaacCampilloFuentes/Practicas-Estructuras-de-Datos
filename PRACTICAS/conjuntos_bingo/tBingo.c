//
// Created by i.campillo.2025 on 16/05/2026.
//

#include "tBingo.h"

#include <stdlib.h>
#include <time.h>

/* La entrada al problema es un listado con las bolas (los números) disponibles
 * y la salida será el conjunto formado por todas las posibles restas
 * que se puedan hacer con estos números. */

void inicializar(tBingo *b) {
    crearConjuntoVacio(b);

    //se disponen de las bolas 5 6 7 8 9 12 14 15 26 72 75 82 90 91 92
    poner(b, 5);
    poner(b, 6);
    poner(b, 7);
    poner(b, 8);
    poner(b, 9);
    poner(b, 12);
    poner(b, 14);
    poner(b, 15);
    poner(b, 26);
    poner(b, 72);
    poner(b, 75);
    poner(b, 82);
    poner(b, 90);
    poner(b, 91);
    poner(b, 92);

    srand(time(NULL));
}

//se sacan dos bolas y la salida es la mayor menos la menor
void sacarDosBolas(tBingo *b, int *restaResultado) {
    int n1, n2;
    sacar(b, &n1);
    sacar(b, &n2);

    if (n1 > n2) {
        *restaResultado = n1 - n2;
    } else {
        *restaResultado = n2 - n1;
    }

    //se reinsertar las dos bolas quitadas para que generen nuevas restas
    poner(b, n1);
    poner(b, n2);
}

/*...se pueden incluir en los cartones todos estos números...
1 2 3 4 5 6 7 8 9 10 11 12 14 15 16 17 18 19 20 21 46 49 56 57 58 60 61 63 64
65 66 67 68 69 70 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87*/