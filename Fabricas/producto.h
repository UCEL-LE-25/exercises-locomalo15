#ifndef PRODUCTO_H
#define PRODUCTO_H

#define FABRICA 3
#define CANT_PRODUCTOS 4

typedef struct {
    int cantProducida;
    int costoFabricacion;
    int precioVenta;
    char nombre[20];
} Productos;

void cargarInformacion(Productos producto[FABRICA][CANT_PRODUCTOS]);
void informePorFabrica(Productos producto[FABRICA][CANT_PRODUCTOS]);
void informePorProducto(Productos producto[FABRICA][CANT_PRODUCTOS]);
void rankingDeProductos(Productos producto[FABRICA][CANT_PRODUCTOS]);

#endif