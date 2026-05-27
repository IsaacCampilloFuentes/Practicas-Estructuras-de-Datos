#include "elemento.h"

int main(void) {
    tElemento noticia;
    tFecha fecha;

    crearFecha(2,3,4, &fecha);
    crearNoticia("wd", fecha, "dw" ,23, &noticia);

    imprimirNoticia(noticia);
    return 0;
}