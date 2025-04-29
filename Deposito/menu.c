#include <stdio.h>
#include "menu.h"
void menuShow()
{
    printf("\n ----BIENVENIDO AL SISTEMA DE GESTION DE DEPOSITO---- \n");
    printf("1) Inicializar deposito.\n");
    printf("2) Agregar producto.\n");
    printf("3) Retirar stock.\n");
    printf("4) Mover producto.\n");
    printf("5) Buscar producto.\n");
    printf("6) Seccion reportes. \n");
    printf("0) SALIR \n");
}
int pedirOpcion()
{
    int opcion;
    do
    {
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion<0 || opcion>6);
   
    return opcion;
}