#include <stdio.h>
#include "impresora.h"
#include <string.h> // necesario para usar memset

void inicializarOficina(Impresora impresora[SECTORES][IMPRESORAS]) 
{
    memset(impresora, 0, sizeof(Impresora) * SECTORES * IMPRESORAS);
    printf("Todas las impresoras han sido inicializadas.");
}
void modificarImpresora(Impresora impresora[SECTORES][IMPRESORAS], int sector, int nro)
{
    int estadoActual=0;
    int impresionActual=0;
    printf("\n MODIFICANDO SECTOR %d IMPRESORA %d \n", sector, nro);

    do {
        printf("\n Ingrese nuevo estado (0. Inactiva | 1. Activa): ");
        scanf("%d", &estadoActual);
        if (estadoActual != 0 && estadoActual != 1) {
            printf("Estado invalido. Ingrese 0 o 1.\n");
        }
    } while (estadoActual != 0 && estadoActual != 1);
    
    impresora[sector][nro].estado = estadoActual;

    if (estadoActual == 1)
    {
        do {
            printf("\n Ingrese el numero de paginas a imprimir: ");
            scanf("%d", &impresionActual);
            if (impresionActual < 0) {
                printf("El numero debe ser positivo.\n");
            }
        } while (impresionActual < 0);

        impresora[sector][nro].paginas += impresionActual;
    }

    

}
void paginasPorSector(Impresora impresora[SECTORES][IMPRESORAS], int sector)
{
    int totalCopias = 0 ;
    printf("\n Informe 'Paginas por sector' \n");
    for (int i = 0; i < IMPRESORAS; i++)
    {
        printf("\n Numero de copias impresora %d: %d", i, impresora[sector][i]);
        totalCopias += impresora[sector][i].paginas;
    }
    printf("\n Numero total de impresiones: %d", totalCopias);
    
}
int activasPorSector(Impresora impresora[SECTORES][IMPRESORAS], int sector)
{
    int activas = 0;
    for (int i = 0; i < IMPRESORAS; i++)
    {
        if (impresora[sector][i].estado == 1)
        {
            activas++;
        }        
    }
    return activas;
}
void sectorMasActivo(Impresora impresora[SECTORES][IMPRESORAS])
{
    int sectorGanador = 0;
    int maxPaginas = 0;

    for (int i = 0; i < SECTORES; i++) {
        int totalSector = 0;
        for (int j = 0; j < IMPRESORAS; j++) {
            totalSector += impresora[i][j].paginas;
        }

        if (i == 0 || totalSector > maxPaginas) {
            maxPaginas = totalSector;
            sectorGanador = i;
        }
    }
    if (sectorGanador == 0)
    {
        printf("\n El sector mas activo es ADMINISTRACION.");
    }else if (sectorGanador == 1)
    {
        printf("\n El sector mas activo es TECNICA.");
    }else
    {
        printf("\n El sector mas activo es RECUSROS HUMANOS.");
    }
       
}
void informeGeneral(Impresora impresora[SECTORES][IMPRESORAS])
{   
    char* nombres[] = {"Administracion", "Tecnica", "Recursos Humanos"};
    int totalGeneral = 0;

    for (int i = 0; i < SECTORES; i++) {
        int totalSector = 0;
        printf("\nSector %d - %s\n", i, nombres[i]);
        for (int j = 0; j < IMPRESORAS; j++) {
            printf("  Impresora %d: %s, %d\n",j , impresora[i][j].estado ? "activa" : "inactiva", impresora[i][j].paginas);
            totalSector += impresora[i][j].paginas;
        }
        printf("  Total de paginas impresas en el sector: %d\n", totalSector);
        totalGeneral += totalSector;
    }

    printf("\nTOTAL GENERAL DE PAGINAS IMPRESAS EN LA OFICINA: %d\n", totalGeneral);
    
}