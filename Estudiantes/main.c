#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 100

typedef struct {
    char nombre[50];
    int edad;
    float notaFinal;
} Estudiante;

void agregarEstudiante(Estudiante estudiantes[], int *cantidad);

void mostrarEstudiantes(Estudiante estudiantes[], int cantidad);

void calcularPromedio(Estudiante estudiantes[], int cantidad);

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar nuevo estudiante\n");
        printf("2. Mostrar todos los registrados\n");
        printf("3. Calcular promedio de notas\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(estudiantes, &cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                calcularPromedio(estudiantes, cantidad);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
void agregarEstudiante(Estudiante estudiantes[], int *cantidad) {
    if (*cantidad >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }

    printf("Nombre: ");
    scanf(" %[^\n]", estudiantes[*cantidad].nombre); // leer con espacios
    printf("Edad: ");
    scanf("%d", &estudiantes[*cantidad].edad);
    printf("Nota final: ");
    scanf("%f", &estudiantes[*cantidad].notaFinal);

    (*cantidad)++;
    printf("Estudiante agregado exitosamente.\n");
}

void mostrarEstudiantes(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Edad: %d\n", estudiantes[i].edad);
        printf("Nota final: %.2f\n", estudiantes[i].notaFinal);
    }
}

void calcularPromedio(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay estudiantes para calcular el promedio.\n");
        return;
    }

    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += estudiantes[i].notaFinal;
    }
    printf("Promedio de notas: %.2f\n", suma / cantidad);
}

