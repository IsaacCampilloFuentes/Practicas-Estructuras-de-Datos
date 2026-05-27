//
// Created by i.campillo.2025 on 18/05/2026.
//

#include "UArbolBB.h"
#include <stdio.h>
#include <string.h>

#define LIM 50

void recopilarHashtags(tArbolBB *twitter){
    FILE *pFichero;
    char hashtag[LIM];
    tElemento tweetsUnderHashtag;
    tLista vacia;
    int i;

    crearListaVacia(&vacia);
    crearArbolBBVacio(twitter);

    pFichero = fopen("hashtags.txt", "r");
    if(pFichero != NULL) {
        while (fgets(hashtag, LIM, pFichero) != NULL) {
            //quitar el salto de linea al final de cada hashtag
            i = strlen(hashtag);
            hashtag[i-1] = '\0';

            crearElemento(&tweetsUnderHashtag, hashtag, vacia);

            insertarArbolBB(twitter, tweetsUnderHashtag);
        }
    }
}

void insertarTweetEnHashtag(tArbolBB *a, char hashtag[DIM], char tweet[MAX]) {
    if (!esArbolBBVacio(*a)) {
        tElemento r;
        tArbolBB i, d;
        tElemento buscado;
        tLista vacia;

        raiz(*a, &r);
        hijoIzq(*a, &i);
        hijDer(*a, &d);

        crearListaVacia(&vacia);
        crearElemento(&buscado, hashtag, vacia);

        if (esIgualElemento(r, buscado)) {
            insertarTweet(&(r.tweets), tweet);
            construirArbolBB(a, i, r, d);
        } else if (esMayorElemento(buscado, r)) {
            insertarTweetEnHashtag(&d, hashtag, tweet);
            construirArbolBB(a, i, r, d);
        } else {
            insertarTweetEnHashtag(&i, hashtag, tweet);
            construirArbolBB(a, i, r, d);
        }
    }
}
int esFinHashtag(char c) {
    return c == '\n' || c == '\0' || c == '.' || c == ',' ||
           c == ' '  || c == '?'  || c == '!' || c == ':' || c == ';';
}
void procesarTweet(tArbolBB *a, char tweet[MAX]) {
    int i = 0;

    while (tweet[i] != '\0') {
        if (tweet[i] == '#') {
            char hashtag[DIM];
            int inicio = i;
            int longitud = 0;

            while (!esFinHashtag(tweet[i]) && tweet[i] != '\0') {
                longitud++;
                i++;
            }

            strncpy(hashtag, tweet + inicio, longitud);
            hashtag[longitud] = '\0';

            insertarTweetEnHashtag(a, hashtag, tweet);
        } else {
            i++;
        }
    }
}
void recopilarTweetsBajoHashtags(tArbolBB *a) {
    FILE *pFichero;
    char tweet[MAX];

    pFichero = fopen("tweets.txt", "r");

    if (pFichero != NULL) {
        while (fgets(tweet, MAX, pFichero) != NULL) {
            procesarTweet(a, tweet);
        }

        fclose(pFichero);
    }
}