#include <stdio.h>
#include <string.h>
#include "titular.h"

void altaTitular() {
    FILE *archivo = fopen("titulares.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de titulares.\n");
        return;
    }

    Titular nuevo;

    printf("Ingrese nombre: ");
    scanf("%s", nuevo.nombre);

    printf("Ingrese CUIT: ");
    scanf("%d", &nuevo.cuit);

    printf("Ingrese tipo de documento (DNI, LC, LE, etc): ");
    scanf("%s", nuevo.tipoDocumento);

    printf("Ingrese numero de documento: ");
    scanf("%d", &nuevo.nroDocumento);

    printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
    scanf("%s", nuevo.fechaNacimiento);

    // Inicializamos los ID de vehículo en -1 (para indicar que están vacíos)
    for (int i = 0; i < 3; i++) {
        nuevo.idVehiculo[i] = -1;
    }

    fprintf(archivo, "%s;%d;%s;%d;%s;%d,%d,%d\n",
        nuevo.nombre,
        nuevo.cuit,
        nuevo.tipoDocumento,
        nuevo.nroDocumento,
        nuevo.fechaNacimiento,
        nuevo.idVehiculo[0],
        nuevo.idVehiculo[1],
        nuevo.idVehiculo[2]
    );

    fclose(archivo);
    printf("Titular guardado exitosamente.\n");
}

void listarTitulares() {
    FILE *archivo = fopen("titulares.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de titulares.\n");
        return;
    }

    Titular t;
    printf("\n--- Lista de Titulares ---\n");
    while (fscanf(archivo, "%[^;];%d;%[^;];%d;%[^\n]\n",
                  t.nombre,
                  &t.cuit,
                  t.tipoDocumento,
                  &t.nroDocumento,
                  t.fechaNacimiento) == 5) {

        printf("Nombre: %s\n", t.nombre);
        printf("CUIT: %d\n", t.cuit);
        printf("Tipo de Documento: %s\n", t.tipoDocumento);
        printf("Numero de Documento: %d\n", t.nroDocumento);
        printf("Fecha de Nacimiento: %s\n", t.fechaNacimiento);
        printf("-----------------------------\n");
    }

    fclose(archivo);
}