#include <stdio.h>
#include "menu.h"
#include "functions.h"

#define COLUMNAS 10
#define FILAS 10

int main()
{
    int codigos[FILAS][COLUMNAS];
    int stock[FILAS][COLUMNAS];
    int opcion;

    inicializarDeposito((int *)codigos, (int *)stock);

    do
    {
        menuShow();
        opcion = pedirOpcion();

        switch (opcion)
        {
        case 1:
            inicializarDeposito((int *)codigos, (int *)stock);
            break;

        case 2:
            agragarProducto((int *)codigos, (int *)stock);
            break;
       
        case 3:
            retirarStock((int *)codigos, (int *)stock);
            break;

        case 4:
            moverProducto((int *)codigos, (int *)stock);
            break;

        case 5:
            buscarProducto((int *)codigos, (int *)stock);
            break;

        case 6:
            mostrarReportes((int *)codigos, (int *)stock);
            break;

        case 0:
            printf("\n Saliendo del programa!\n");
            break;
       
            default:
            printf("Opcion invalida!\n Ingrese nuevamente un valor entre 0 y 6\n");
            break;
        }
    } while (opcion != 0);
}
