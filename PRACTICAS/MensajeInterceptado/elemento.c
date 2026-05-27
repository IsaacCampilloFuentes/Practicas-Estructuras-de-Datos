//
// Created by i.campillo.2025 on 04/04/2026.
//

#include "elemento.h"
#include <stdio.h>

void asignarElemento(tElemento *dest, tElemento orig) {
    *dest = orig;
}
void mostrarElemento(tElemento elem) {
    printf("%c", elem);
}

int esVocal (char c) {
    int vocal = 0;
    if (c =='a' || c =='e' || c =='i' || c =='o' || c =='u' || c =='A' || c =='E' || c =='I' || c =='O' || c =='U') {
        vocal = 1;
    }
    return vocal;
}