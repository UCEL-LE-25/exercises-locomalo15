#include <stdio.h>
#include "cedula.h"

void altaCedula() {
    FILE *archivo = fopen("cedulas.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de cédulas.\n");
        return;
    }

    Cedula nueva;

    printf("Ingrese número de cédula: ");
    scanf("%d", &nueva.nroCedula);

    printf("Ingrese fecha de emisión (dd/mm/aaaa): ");
    scanf("%s", nueva.fechaEmision);

    printf("Ingrese fecha de vencimiento (dd/mm/aaaa): ");
    scanf("%s", nueva.fechaVencimiento);

    printf("Ingrese dominio del vehículo: ");
    scanf("%s", nueva.dominioVehiculo);

    printf("Ingrese DNI del titular: ");
    scanf("%d", &nueva.dniTitular);

    fprintf(archivo, "%d;%s;%s;%s;%d\n",
        nueva.nroCedula,
        nueva.fechaEmision,
        nueva.fechaVencimiento,
        nueva.dominioVehiculo,
        nueva.dniTitular
    );

    fclose(archivo);
    printf("Cédula guardada exitosamente.\n");
}
