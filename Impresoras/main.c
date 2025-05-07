#include <stdio.h>
#include "menu.h"
#include "impresora.h"


int main()
{
    Impresora impresora[SECTORES][IMPRESORAS];
    int opcion;
    int sector, nro;
    do
    {
        menuShow();
        opcion = pedirOpcion();
        switch (opcion)
        {
        case 1:
            inicializarOficina(impresora);
            break;
        
        case 2:
            do
            {
                printf("\n Ingrese el sector a modificar");
                scanf("%d", &sector);
                if (sector<0 || sector>3)
                {
                    printf("Esta ingresando un sector incorrecto. \n");
                }
            } while (sector<0 || sector>3);

            do
            {
                printf("\n Ingrese el numero de impresora a modificar");
                scanf("%d", &nro);
                if (nro<0 || nro>4)
                {
                    printf("Esta ingresando un numero de impresora. \n");
                }
            } while (nro<0 || nro>4);
            
            modificarImpresora(impresora, sector, nro);
            
            break;

        case 3:
            do
            {
                printf("\n Ingrese el sector que desa visualizar: ");
                scanf("%d", &sector);
                if (sector<0 || sector>3)
                {
                    printf("Esta ingresando un sector incorrecto. \n");
                }
            } while (sector<0 || sector>3);

            paginasPorSector(impresora, sector);

            break;

        case 4:
            do
            {
                printf("\n Ingrese el sector que desa visualizar: ");
                scanf("%d", &sector);
                if (sector<0 || sector>3)
                {
                    printf("Esta ingresando un sector incorrecto. \n");
                }
            } while (sector<0 || sector>3);
            printf("Numero de impresoras activas: %d", activasPorSector(impresora, sector));
            break;
        
        case 5:
            sectorMasActivo(impresora);            
            break;

        case 6:
            informeGeneral(impresora);
            break;
        }
    } while (opcion != 0);
    
    return 0;
}
