#include <stdio.h>
#include "automotor.h"

int idVehiculoExiste(int idBuscado) {
    FILE *archivo = fopen("registro.txt", "r");
    if (archivo == NULL) {
        return 0; // Si no existe el archivo, no hay IDs registrados aún
    }

    Automotor temp;

    while (fscanf(archivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%[^;];%[^;];%d;%d;%d\n",
            &temp.idVehiculo,
            temp.dominio,
            temp.marca,
            temp.modelo,
            temp.chasis,
            temp.motor,
            &temp.anioFabricacion,
            temp.paisOrigen,
            temp.tipoUso,
            &temp.peso,
            &temp.nroDocTitular,
            &temp.nroCedula) == 12)
    {
        if (temp.idVehiculo == idBuscado) {
            fclose(archivo);
            return 1; // Ya existe
        }
    }

    fclose(archivo);
    return 0; // No existe
}

void altaAutomotor() {
    FILE *archivo = fopen("registro.txt", "a"); // modo append
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Automotor autoNuevo;

    int id;
    do {
        printf("Ingrese ID del vehículo: ");
        scanf("%d", &id);
        if (idVehiculoExiste(id)) {
            printf("Ese ID ya existe. Intente con otro.\n");
        }
    } while (idVehiculoExiste(id));

    autoNuevo.idVehiculo = id;

    printf("Ingrese dominio: ");
    scanf("%s", autoNuevo.dominio);

    printf("Ingrese marca: ");
    scanf("%s", autoNuevo.marca);

    printf("Ingrese modelo: ");
    scanf("%s", autoNuevo.modelo);

    printf("Ingrese número de chasis: ");
    scanf("%s", autoNuevo.chasis);

    printf("Ingrese número de motor: ");
    scanf("%s", autoNuevo.motor);

    printf("Ingrese año de fabricación: ");
    scanf("%d", &autoNuevo.anioFabricacion);

    printf("Ingrese país de origen: ");
    scanf("%s", autoNuevo.paisOrigen);

    printf("Ingrese tipo de uso: ");
    scanf("%s", autoNuevo.tipoUso);

    printf("Ingrese peso (kg): ");
    scanf("%d", &autoNuevo.peso);

    printf("Ingrese Nro. Documento del titular: ");
    scanf("%d", &autoNuevo.nroDocTitular);

    printf("Ingrese Nro. de cédula: ");
    scanf("%d", &autoNuevo.nroCedula);

    // Escribir en el archivo (formato de texto plano)
    fprintf(archivo, "%d;%s;%s;%s;%s;%s;%d;%s;%s;%d;%d;%d\n",
        autoNuevo.idVehiculo,
        autoNuevo.dominio,
        autoNuevo.marca,
        autoNuevo.modelo,
        autoNuevo.chasis,
        autoNuevo.motor,
        autoNuevo.anioFabricacion,
        autoNuevo.paisOrigen,
        autoNuevo.tipoUso,
        autoNuevo.peso,
        autoNuevo.nroDocTitular,
        autoNuevo.nroCedula
    );

    fclose(archivo);
    printf("Automotor guardado exitosamente.\n");
}