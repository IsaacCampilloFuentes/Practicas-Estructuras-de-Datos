#include <stdio.h>
#include "tLista.h"
#include "tElemento.h"
#include "tFecha.h"

int main() {
    // 1. Declaración e Inicialización
    tLista miLista;
    tElemento n1, n2, n3;
    tFecha f1, f2, f3;

    crearVacia(&miLista);
    printf("--- Lista inicializada ---\n\n");

    // 2. Creación de Fechas (Capa baja)
    crearFecha(&f1, 12, 5, 2026);
    crearFecha(&f2, 1, 1, 2026);
    crearFecha(&f3, 25, 12, 2025);

    // 3. Creación de Noticias (Capa media)
    crearNoticia(&n1, "Descubren agua en Marte", f1, "Ciencia Hoy", 1500);
    crearNoticia(&n2, "Final de la Champions", f2, "Deportes 24", 3000);
    crearNoticia(&n3, "Nueva receta de tortilla", f3, "Cocina Facil", 500);

    // 4. Registro en la Lista (Capa alta)
    printf("Registrando noticias...\n");
    registrarNoticia(&miLista, n1);
    registrarNoticia(&miLista, n2);
    registrarNoticia(&miLista, n3);

    // 5. Mostrar todas las noticias
    printf("\n--- Listado de Noticias ---\n");
    mostrarNoticias(miLista);

    // 6. Probar el contador de lectores
    printf("\nTotal de lectores en la lista: %d\n", numeroLectores(miLista));

    // 7. Probar la eliminación
    printf("\nEliminando: 'Final de la Champions'...\n");
    if (eliminarNoticia(&miLista, n2)) {
        printf("Noticia eliminada con exito.\n");
    } else {
        printf("Error: No se pudo eliminar la noticia.\n");
    }

    // 8. Ver resultado final
    printf("\n--- Lista tras la eliminacion ---\n");
    mostrarNoticias(miLista);
    printf("Nuevo total de lectores: %d\n", numeroLectores(miLista));

    return 0;
}