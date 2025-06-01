#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "automotor.h"
#include "titular.h"
#include "cedula.h"

int main() {
    int opcion;

    do {
        menuShow();
        opcion = pedirOpcion(0, 10);

        switch (opcion) {
            case 1:
                altaAutomotor();
                altaCedula();
                altaTitular();
                break;
            case 2:
                altaAutomotor();
                altaCedula();
                break;
            case 3:
                altaTitular();
                break;
            case 5:
                bajaVehiculo();
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            case 6:
                listarTodos();
                break;
            case 9:
                listarTitulares();
                break;
            default:
                printf("Opcion aun no implementada.\n");
        }

    } while (opcion != 0);

    return 0;
}
