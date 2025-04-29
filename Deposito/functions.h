#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void inicializarDeposito(int *codigos, int *stock);
void agragarProducto(int *codigos, int *stock);
void retirarStock(int *codigos, int *stock);
void moverProducto(int *codigos, int *stock);
void buscarProducto(int *codigos, int *stock);
void mostrarReportes(int *codigos, int *stock);
void mostrarMapaDeposito(int *codigos, int *stock);
void mostrarTopProductos(int *codigos, int *stock);
void mostrarEspaciosLibresOcupados(int *codigos);
void mostrarPosicionesLibres(int *codigos);
void mostrarProductosBajoStock(int *codigos, int *stock);

#endif
