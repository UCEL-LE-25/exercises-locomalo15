#include <stdio.h>
#include "menu.h"
void menuShow()
{
    printf("\n\n\n ---- GESTION DE IMPRESORAS ---- \n");
    printf("1) Cargar impresion.\n");
    printf("2) Mostrar paginas impresas por sector.\n");
    printf("3) Mostrar impresoras activas por sector.\n");
    printf("4) Sector con mayor impresion.\n");
    printf("5) Informe general.\n");
    printf("0) SALIR \n");
}
int pedirOpcion() 
{
    int opcion;
    do
    {
        printf("Ingrese una opcion (0-5): \n");
        scanf("%d", &opcion);
    } while (opcion < 0 || opcion > 5);
    
    return opcion;
}