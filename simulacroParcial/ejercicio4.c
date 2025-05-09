#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char nombre [20];
    int precio;
}Material;

int main(){
    Material tabla = {"Tabla", 50};
    Material clavo = {"Clavo", 10};
    Material soga = {"Soga", 75};

    int totalTablas = 2;
    int totalClavos = 4;
    int totalSogas = 1;
    int costoTotal = ((totalTablas * tabla.precio) + (totalClavos * clavo.precio) + (totalSogas * soga.precio));
    srand(time(NULL));
    int oro = (100 + (rand()% 201)); // Valor entre 100 y 300
    printf("Oro disponible: %d monedas \n", oro);
    if (oro >= costoTotal)
    {
        printf("Compro todos los materiales de la trampa!. \n");
        oro -= costoTotal;
    }
    else if (oro >= soga.precio)
    {
        printf("Compro solo la soga SECO!. \n");
        oro -= soga.precio;
    }
    else
    {
        printf("No alcanzo para nada, estas al horno. ANDA A LABURAR \n");
    }
    printf("Oro restante: %d monedas. \n", oro);
    return 0;
}