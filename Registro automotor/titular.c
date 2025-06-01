#include <stdio.h>
#include <string.h>
#include "titular.h"
#include "automotor.h"

void altaTitular() {
    FILE *archivo = fopen("titulares.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de titulares.\n");
        return;
    }

    Titular nuevo;
    getchar(); // limpia el '\n' que queda en el buffer
    printf("Ingrese nombre: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    printf("Ingrese CUIT: ");
    scanf("%d", &nuevo.cuit);
    getchar(); // limpia el '\n' que queda en el buffer

    printf("Ingrese tipo de documento (DNI, LC, LE, etc): ");
    fgets(nuevo.tipoDocumento, sizeof(nuevo.tipoDocumento), stdin);
    nuevo.tipoDocumento[strcspn(nuevo.tipoDocumento, "\n")] = '\0';

    printf("Ingrese numero de documento: ");
    scanf("%d", &nuevo.nroDocumento);
    getchar(); // limpia el '\n' que queda en el buffer

    printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
    fgets(nuevo.fechaNacimiento, sizeof(nuevo.fechaNacimiento), stdin);
    nuevo.fechaNacimiento[strcspn(nuevo.fechaNacimiento, "\n")] = '\0';


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

void listarTitularesConVehiculos() {
    FILE *ft = fopen("titulares.txt", "r");
    FILE *fa = fopen("registro.txt", "r");

    if (!ft || !fa) {
        printf("Error al abrir archivos.\n");
        return;
    }

    Titular t;
    Automotor a;

    while (fscanf(ft, "%[^;];%d;%[^;];%d;%[^;];%d,%d,%d\n",t.nombre, &t.cuit, t.tipoDocumento, &t.nroDocumento, t.fechaNacimiento, &t.idVehiculo[0], &t.idVehiculo[1], &t.idVehiculo[2]) == 8){
        printf("\n--- Titular ---\n");
        printf("Nombre: %s\n", t.nombre);
        printf("CUIT: %d\n", t.cuit);
        printf("Tipo de Documento: %s\n", t.tipoDocumento);
        printf("Numero de Documento: %d\n", t.nroDocumento);
        printf("Fecha de Nacimiento: %s\n", t.fechaNacimiento);

        // Volver al inicio de archivo de autos para buscar los de este titular
        rewind(fa);
        int tieneAutos = 0;

        while (fscanf(fa, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%[^;];%[^;];%d;%d;%d\n",
                      &a.idVehiculo, a.dominio, a.marca, a.modelo, a.chasis, a.motor,
                      &a.anioFabricacion, a.paisOrigen, a.tipoUso, &a.peso,
                      &a.nroDocTitular, &a.nroCedula) == 12) {

            if (a.nroDocTitular == t.nroDocumento) {
                if (!tieneAutos) {
                    printf("Vehiculos:\n");
                    tieneAutos = 1;
                }
                printf("  | Dominio: %s | Marca: %s | Modelo: %s | Anio: %d\n",
                       a.dominio, a.marca, a.modelo, a.anioFabricacion);
            }
        }

        if (!tieneAutos) {
            printf("No tiene vehiculos registrados.\n");
        }

        printf("---------------------------\n");
    }

    fclose(ft);
    fclose(fa);
}