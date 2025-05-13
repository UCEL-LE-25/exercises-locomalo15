#include <stdio.h>
#include "menu.h"
#include "producto.h"

int main() {
    Productos producto[FABRICA][CANT_PRODUCTOS];
    int opcion = 0;

    do {
        menuShow();
        opcion = pedirOpcion();

        switch (opcion) {
        case 1:
            cargarInformacion(producto);
            break;
        case 2:
            informePorFabrica(producto);
            break;
        case 3:
            informePorProducto(producto);
            break;
        case 4:
            rankingDeProductos(producto);
            break;
        case 0:
            printf("\nSaliendo del programa!\n");
            break;
        default:
            printf("Opcion invalida! Ingrese un valor entre 0 y 4.\n");
        }

    } while (opcion != 0);

    return 0;
}
