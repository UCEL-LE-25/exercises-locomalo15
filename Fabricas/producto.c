#include <stdio.h>
#include "producto.h"
#include <string.h>

void cargarInformacion(Productos producto[FABRICA][CANT_PRODUCTOS]) {
    for (int i = 0; i < FABRICA; i++) {
        printf("\nFABRICA %d\n", i + 1);
        for (int j = 0; j < CANT_PRODUCTOS; j++) {
            printf("Producto %d:\n", j + 1);
            printf("  Cantidad producida: ");
            scanf("%d", &producto[i][j].cantProducida);

            printf("  Costo de fabricacion: ");
            scanf("%d", &producto[i][j].costoFabricacion);

            printf("  Precio de venta: ");
            scanf("%d", &producto[i][j].precioVenta);

            printf("  Nombre: ");
            scanf("%s", producto[i][j].nombre);
        }
    }
}

void informePorFabrica(Productos producto[FABRICA][CANT_PRODUCTOS]) {
    for (int i = 0; i < FABRICA; i++) {
        int gananciaTotal = 0;
        printf("\n--- Fabrica %d ---\n", i + 1);
        for (int j = 0; j < CANT_PRODUCTOS; j++) {
            int margen = producto[i][j].precioVenta - producto[i][j].costoFabricacion;
            printf("Producto %d: %s\n", j + 1, producto[i][j].nombre);
            printf("  Cantidad producida: %d\n", producto[i][j].cantProducida);
            printf("  Margen de ganancia: %d\n", margen);
            gananciaTotal += margen * producto[i][j].cantProducida;
        }
        printf("Ganancia total de la fabrica: %d\n", gananciaTotal);
    }
}

void informePorProducto(Productos producto[FABRICA][CANT_PRODUCTOS]) {
    int fab, prod;
    printf("Ingrese numero de fabrica (1 a %d): ", FABRICA);
    scanf("%d", &fab);
    printf("Ingrese numero de producto (1 a %d): ", CANT_PRODUCTOS);
    scanf("%d", &prod);
    fab--; prod--;

    if (fab >= 0 && fab < FABRICA && prod >= 0 && prod < CANT_PRODUCTOS) {
        Productos p = producto[fab][prod];
        int margen = p.precioVenta - p.costoFabricacion;
        printf("\n--- Informe del Producto ---\n");
        printf("Nombre: %s\n", p.nombre);
        printf("Cantidad producida: %d\n", p.cantProducida);
        printf("Costo de fabricacion: %d\n", p.costoFabricacion);
        printf("Precio de venta: %d\n", p.precioVenta);
        printf("Margen de ganancia: %d\n", margen);
    } else {
        printf("Fabrica o producto invalido.\n");
    }
}

void rankingDeProductos(Productos producto[FABRICA][CANT_PRODUCTOS]) {
    int total = FABRICA * CANT_PRODUCTOS;
    int indices[total];
    int cantidades[total];
    int ganancias[total];

    int k = 0;
    for (int i = 0; i < FABRICA; i++) {
        for (int j = 0; j < CANT_PRODUCTOS; j++) {
            indices[k] = k;
            cantidades[k] = producto[i][j].cantProducida;
            int margen = producto[i][j].precioVenta - producto[i][j].costoFabricacion;
            ganancias[k] = margen * producto[i][j].cantProducida;
            k++;
        }
    }

    // Ordenar por cantidad producida
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (cantidades[indices[j]] > cantidades[indices[i]]) {
                int aux = indices[i];
                indices[i] = indices[j];
                indices[j] = aux;
            }
        }
    }

    printf("\n--- Ranking por cantidad producida ---\n");
    for (int i = 0; i < total; i++) {
        int idx = indices[i];
        int f = idx / CANT_PRODUCTOS;
        int p = idx % CANT_PRODUCTOS;
        printf("%d. Fabrica %d - Producto: %s | Cantidad: %d\n",
               i + 1, f + 1, producto[f][p].nombre, producto[f][p].cantProducida);
    }

    // Ordenar por ganancia
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (ganancias[indices[j]] > ganancias[indices[i]]) {
                int aux = indices[i];
                indices[i] = indices[j];
                indices[j] = aux;
            }
        }
    }

    printf("\n--- Ranking por ganancia total ---\n");
    for (int i = 0; i < total; i++) {
        int idx = indices[i];
        int f = idx / CANT_PRODUCTOS;
        int p = idx % CANT_PRODUCTOS;
        printf("%d. Fabrica %d - Producto: %s | Ganancia: %d\n",
               i + 1, f + 1, producto[f][p].nombre, ganancias[idx]);
    }
}
