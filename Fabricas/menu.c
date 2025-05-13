#include <stdio.h>
#include "menu.h"
void menuShow()
{
    printf("\n ----BIENVENIDO AL SISTEMA DE GESTION DE DEPOSITO---- \n");
    printf("1) Cargar informacion.\n");
    printf("2) Informe por fabrica.\n");
    printf("3) Informe por producto.\n");
    printf("4) Ranking de productos.\n");
    printf("0) SALIR \n");
}
int pedirOpcion()
{
    int opcion;
    do
    {
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion<0 || opcion>4);
   
    return opcion;
}