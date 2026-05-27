//
// Created by i.campillo.2025 on 16/05/2026.
//

#ifndef TBINGO_H
#define TBINGO_H

#include "tConjunto.h"

typedef tConjunto tBingo;
/* La entrada al problema es un listado con las bolas (los números) disponibles
 * y la salida será el conjunto formado por todas las posibles restas
 * que se puedan hacer con estos números. */

//se disponen de las bolas 5 6 7 8 9 12 14 15 26 72 75 82 90 91 92
void inicializar(tBingo *b);
void sacarDosBolas(tBingo *b, int *restaResultado);

/* ...se pueden incluir en los cartones todos estos números...
 * 1 2 3 4 5 6 7 8 9 10 11 12 14 15 16 17 18 19 20 21 46 49 56 57 58 60 61
 * 63 64 65 66 67 68 69 70 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 */
#endif //TBINGO_H
