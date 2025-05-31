#include <stdio.h>
#include "menu.h"
#include "automotor.h"
#include "titular.h"
#include "cedula.h"

int main() {
    int opcion;

    do {
        menuShow();
        opcion = pedirOpcion(0, 8);

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
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no implementada aún.\n");
        }

    } while (opcion != 0);

    return 0;
}
