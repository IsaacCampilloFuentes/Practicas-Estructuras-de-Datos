//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "tElemento.h"
#include <string.h>

void crearElemento(tElemento *e, char hashtag[DIM], tLista tweets) {
    strcpy(e->hashtag, hashtag);
    e->tweets = tweets;
}
void asignarElemento(tElemento *dest, tElemento orig) {
    strcpy(dest->hashtag, orig.hashtag);
    dest->tweets = orig.tweets;
}
int esIgualElemento(tElemento e1, tElemento e2) {
    return strcmp(e1.hashtag, e2.hashtag) == 0;
}
int esMayorElemento(tElemento e1, tElemento e2) {
    //=1 si e1.hashtag va despues en el alfabeto que e2.hashtag
    return strcmp(e1.hashtag, e2.hashtag) > 0;
}