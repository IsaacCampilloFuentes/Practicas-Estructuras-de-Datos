#include <stdio.h>
#include "tArbolBin.h"

//Se ha de implementar:
/*
• Crear el árbol genealógico mostrado en la figura anterior.
• Un método que dado el nombre de un dios te diga si existe en el árbol o no.
• Crear un método que dados el nombre de dos dioses te diga si el primero es padre/madre del segundo.
• Un método que imprima la información del árbol de manera que primero se imprima la raíz, luego la información del subárbol izquierdo y luego la del subárbol derecho. En el árbol que nos ocupa la secuencia de salida
de este método debería ser: Cronos, Zeus, Atenea, Dédalo, Apolo, Orfeo, Aristeo, Hera, Hefeso, Ares.
*/

void inicializarArbolDioses(tArbolBin *a);
int pertenece(tArbolBin a, tElemento r);
int esPadre(tArbolBin a, tElemento rDest, tElemento rOrig);
void imprimirNombres(tArbolBin a);

int main(void) {
    //el main es un test bench de lo que hemos creado para ver si funciona
    tArbolBin a;
    inicializarArbolDioses(&a);

    //obtendremos a Hera para usar como ejemplo, debería ser hija derecha de Cronos (la raíz)
    tElemento Hera;
    tArbolBin aux;
    hijoDer(a, &aux);
    raiz(aux, &Hera);

    mostrarNombreElemento(Hera);
    printf("\n");

    //creamos a un ares con la misma info que el del grafo para ver si consigue identificar que Hera es padre(madre) de Ares
    tElemento Ares;
    crearElemento(&Ares, "Ares", "dios de la guerra, de la brutalidad y los horrores de las batallas.");

    printf("Pertenece: %d\n", pertenece(a, Ares));
    printf("Es padre: %d\n", esPadre(a, Hera, Ares));
    //ambos deberían devolver 1

    tElemento inventado;
    crearElemento(&inventado, "notReal", "very epic");
    printf("Pertenece: %d\n", pertenece(a, inventado));
    printf("Es padre: %d\n", esPadre(a, Ares, Hera));
    //ambos deberían devolver 0

    imprimirNombres(a);
    return 0;
}
//Se inicializará con estos dioses y estas descripciones:
/*• Cronos: dios del tiempo.
• Zeus: dios supremo, líder de los 12 dioses olímpicos.
• Hera: diosa del matrimonio, las mujeres, el cielo y las estrellas.
• Ares: dios de la guerra, de la brutalidad y los horrores de las batallas.
• Hefeso: dios de la forja y del fuego, de los herreros, de los artesanos y los escultores.
• Apolo: dios del sol.
• Atenea: diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate.
• Orfeo: músico y poeta legendario, considerado uno de los músicos más talentosos de la mitología griega.
• Aristeo: semidiós asociado con la agricultura, la apicultura y la cría de animales.
• Teseo: fundador de Atenas.*/
void inicializarArbolDioses(tArbolBin *a) {
    tElemento Cronos, Zeus, Hera, Ares, Hefeso, Apolo, Atenea, Orfeo, Aristeo, Dedalo;

    // Subárboles auxiliares para ir entrelazando los nodos
    tArbolBin aZeus, aHera, aAres, aHefeso, aApolo, aAtenea, aOrfeo, aAristeo, aDedalo;
    tArbolBin vacio;

    // Inicializar el árbol vacío de referencia para las ramas sin hijos
    crearArbolBinVacio(&vacio);

    // Creación de los elementos con sus descripciones
    crearElemento(&Cronos, "Cronos", "dios del tiempo.");
    crearElemento(&Zeus, "Zeus", "dios supremo, líder de los 12 dioses olímpicos.");
    crearElemento(&Hera, "Hera", "diosa del matrimonio, las mujeres, el cielo y las estrellas.");
    crearElemento(&Ares, "Ares", "dios de la guerra, de la brutalidad y los horrores de las batallas.");
    crearElemento(&Hefeso, "Hefeso", "dios de la forja y del fuego, de los herreros, de los artesanos y los escultores.");
    crearElemento(&Apolo, "Apolo", "dios del sol.");
    crearElemento(&Atenea, "Atenea", "diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate.");
    crearElemento(&Orfeo, "Orfeo", "músico y poeta legendario, considerado uno de los músicos más talentosos de la mitología griega.");
    crearElemento(&Aristeo, "Aristeo", "semidiós asociado con la agricultura, la apicultura y la cría de animales.");
    crearElemento(&Dedalo, "Dedalo", "arquitecto y artesano legendario.");

    // CONSTRUCCIÓN DEL ÁRBOL DESDE LAS HOJAS HASTA LA RAÍZ

    // 1. Nodos hoja (sin hijos izquierdo ni derecho)
    construirArbolBin(&aDedalo, vacio, Dedalo, vacio);
    construirArbolBin(&aOrfeo, vacio, Orfeo, vacio);
    construirArbolBin(&aAristeo, vacio, Aristeo, vacio);
    construirArbolBin(&aHefeso, vacio, Hefeso, vacio);
    construirArbolBin(&aAres, vacio, Ares, vacio);

    // 2. Nivel de Atenea y Apolo
    // Atenea tiene a Dédalo a la izquierda y nada a la derecha
    construirArbolBin(&aAtenea, aDedalo, Atenea, vacio);
    // Apolo tiene a Orfeo a la izquierda y Aristeo a la derecha
    construirArbolBin(&aApolo, aOrfeo, Apolo, aAristeo);

    // 3. Nivel de Zeus y Hera
    // Zeus tiene a Atenea a la izquierda y Apolo a la derecha
    construirArbolBin(&aZeus, aAtenea, Zeus, aApolo);
    // Hera tiene a Hefeso a la izquierda y Ares a la derecha
    construirArbolBin(&aHera, aHefeso, Hera, aAres);

    // 4. Raíz principal (Cronos)
    // Cronos tiene a Zeus a la izquierda y Hera a la derecha
    construirArbolBin(a, aZeus, Cronos, aHera);
}


int pertenece(tArbolBin a, tElemento e) {
    int si;
    if (esArbolBinVacio(a)) {
        si = 0;
    } else {
        tArbolBin i, d;
        tElemento r;

        hijoIzq(a, &i);
        hijoDer(a, &d);
        raiz(a, &r);

        if (esIgualElemento(r, e) || pertenece(i, e) || pertenece(d, e)) {
            si = 1;
        } else {
            si = 0;
        }
    }
    return si;
}


int esPadre(tArbolBin a, tElemento rDest, tElemento rOrig) {
    int si;

    if (esArbolBinVacio(a)) {
        si = 0;
    } else {
        tArbolBin i, d;
        tElemento r;

        hijoIzq(a, &i);
        hijoDer(a, &d);
        raiz(a, &r);

        if (esIgualElemento(r, rDest)) {
            tElemento r2;
            int encontrado = 0;

            // comprobar hijo izquierdo
            if (!esArbolBinVacio(i)) {
                raiz(i, &r2);
                if (esIgualElemento(r2, rOrig)) {
                    encontrado = 1;
                }
            }

            // comprobar hijo derecho
            if (!esArbolBinVacio(d)) {
                raiz(d, &r2);
                if (esIgualElemento(r2, rOrig)) {
                    encontrado = 1;
                }
            }

            si = encontrado;
        } else {
            si = esPadre(i, rDest, rOrig) || esPadre(d, rDest, rOrig);
        }
    }

    return si;
}


void imprimirNombres(tArbolBin a) {
    if (!esArbolBinVacio(a)) {
        tArbolBin i, d;
        tElemento r;
        hijoIzq(a, &i);
        hijoDer(a, &d);
        raiz(a, &r);

        //mostramos en preorden r->izq->der
        mostrarNombreElemento(r);
        printf(", ");
        imprimirNombres(i);
        imprimirNombres(d);
    }
}