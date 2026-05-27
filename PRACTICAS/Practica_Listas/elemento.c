//
// Created by i.campillo.2025 on 09/03/2026.
//

#include <stdio.h>
#include <string.h>
#include "elemento.h"
#include "fecha.h"

void crearNoticia(char titulo[MAXNOMBRE], tFecha fecha, char medio[MAXNOMBRE], int visitas, tElemento* pnoticia) {
    strcpy(titulo, pnoticia->titulo);
    pnoticia->fecha = fecha;
    strcpy(medio, pnoticia->medio);
    pnoticia->visitas = visitas;
}
void asignarNoticia(tElemento noticia, tElemento *pnoticia) {
    strcpy(noticia.titulo, pnoticia->titulo);
    pnoticia->fecha = noticia.fecha;
    strcpy(noticia.medio, pnoticia->medio);
    pnoticia->visitas = noticia.visitas;
}
int igualNoticia(tElemento noticia1, tElemento noticia2) {
    int igual = 0;
    if (strcmp(noticia1.titulo, noticia2.titulo)==0) {
        igual = 1;
    }
    return igual;
}
void imprimirNoticia(tElemento noticia) {
    printf("Titulo: %s\n", noticia.titulo);
    imprimirFecha(noticia.fecha);
    printf("Medio: %s\n", noticia.medio);
    printf("Visitas: %d\n", noticia.visitas);
}