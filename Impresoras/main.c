#include <stdio.h>
#include "menu.h"
#include "impresora.h"


int main()
{
    Impresora impresora[SECTORES][IMPRESORAS];
    int opcion;
    int sector, nro;


    inicializarOficina(impresora);

    do
    {
        menuShow();
        opcion = pedirOpcion();
        switch (opcion)
        {
        case 1:
            do
            {
                printf("\n Ingrese el sector a modificar: ");
                scanf("%d", &sector);
                if (sector < 0 || sector >= SECTORES)
                {
                    printf("Está ingresando un sector incorrecto.\n");
                }
            } while (sector < 0 || sector >= SECTORES);

            do
            {
                printf("\n Ingrese el número de impresora a modificar: ");
                scanf("%d", &nro);
                if (nro < 0 || nro >= IMPRESORAS)
                {
                    printf("Está ingresando un número de impresora incorrecto.\n");
                }
            } while (nro < 0 || nro >= IMPRESORAS);

            modificarImpresora(impresora, sector, nro);
            break;

        case 2:
            do
            {
                printf("\n Ingrese el sector que desea visualizar: ");
                scanf("%d", &sector);
                if (sector < 0 || sector >= SECTORES)
                {
                    printf("Está ingresando un sector incorrecto.\n");
                }
            } while (sector < 0 || sector >= SECTORES);

            paginasPorSector(impresora, sector);
            break;

        case 3:
            do
            {
                printf("\n Ingrese el sector que desea visualizar: ");
                scanf("%d", &sector);
                if (sector < 0 || sector >= SECTORES)
                {
                    printf("Está ingresando un sector incorrecto.\n");
                }
            } while (sector < 0 || sector >= SECTORES);

            printf("Número de impresoras activas: %d\n", activasPorSector(impresora, sector));
            break;

        case 4:
            sectorMasActivo(impresora);
            break;

        case 5:
            informeGeneral(impresora);
            break;
        }
    } while (opcion != 0);

    return 0;
}

