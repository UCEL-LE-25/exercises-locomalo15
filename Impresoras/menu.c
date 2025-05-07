#include <stdio.h>
#include "menu.h"
void menuShow()
{
    printf("\n\n\n ---- GESTION DE IMPRESORAS ---- \n");
    printf("1) Inicializar impresoras.\n");
    printf("2) Cargar impresion.\n");
    printf("3) Mostrar paginas impresas por sector.\n");
    printf("4) Mostrar impresoras activas por sector.\n");
    printf("5) Sector con mayor impresion.\n");
    printf("6) Informe general.\n");
    printf("0) SALIR \n");
}
int pedirOpcion() 
{
    int opcion;
    do
    {
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);
    } while (opcion<0 || opcion>6);
    
    return opcion;
}