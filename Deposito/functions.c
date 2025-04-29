#include <stdio.h>
#include "functions.h"
#include <string.h>

#define FILAS 10
#define COLUMNAS 10

void inicializarDeposito(int *codigos, int *stock)
{
    memset(codigos, 0, sizeof(int) * FILAS * COLUMNAS);
    memset(stock, 0, sizeof(int) * FILAS * COLUMNAS);
    printf("\n Deposito inicializado correctamente! \n");
}

void agragarProducto(int *codigos, int *stock)
{
    int fila, columna;
    int codigoNuevo, stockNuevo;
   
    printf("Ingrese la fila (0 a 9) \n");
    scanf("%d", &fila);
    printf("Ingrese la columna (0 a 9) \n");
    scanf("%d", &columna);

    if (fila<0 || fila >= FILAS || columna >= COLUMNAS)
    {
        printf("La posicion esta fuera de rango \n");
        return;
    }

    if (*(codigos + fila * COLUMNAS + columna) != 0)
    {
        printf("ERROR: La posicion ya esta ocupada \n");
        return;
    }

    do
    {
        printf("Ingrese el codigo del nuevo producto \n");
        scanf("%d", &codigoNuevo);
        if (codigoNuevo <= 0 )
        {
            printf("Por favor ingrese un codigo de producto valido (Mayor a 0) \n");
        }      
    } while (codigoNuevo<0);

    do
    {
        printf("Ingrese el stock del nuevo producto \n");
        scanf("%d", &stockNuevo);
        if (stockNuevo <= 0 )
        {
            printf("Por favor ingrese un stock de producto valido (Mayor a 0) \n");
        }      
    } while (stockNuevo<0);

    *(codigos + fila * COLUMNAS + columna) = codigoNuevo;
    *(stock + fila * COLUMNAS + columna) = stockNuevo;

    printf("Producto agregado con exito en las posiciones [%d][%d] \n", fila, columna);
   
   
}

void retirarStock(int *codigos, int *stock)
{
    int fila, columna, cantidad;
   
    printf("Ingrese la fila (0 a 9) \n");
    scanf("%d", &fila);
    printf("Ingrese la columna (0 a 9) \n");
    scanf("%d", &columna);

    if (fila<0 || fila >= FILAS || columna >= COLUMNAS)
    {
        printf("La posicion esta fuera de rango \n");
        return;
    }

    if ((*(codigos + fila * COLUMNAS + columna) == 0))
    {
        printf("No existe producto en esa posicion. \n");
        return;
    }

    printf("Stock actual del producto: %d \n", *(stock + fila * COLUMNAS + columna));
    printf("Ingrese la cantidad a retirar: ");
    scanf("%d", &cantidad);
   
    if (cantidad <= 0 || cantidad > *(stock + fila * COLUMNAS + columna))
    {
        printf("Cantidad invalida. \n");
        return;
    }
   
    *(stock + fila * COLUMNAS + columna) -= columna;

    if (*(stock + fila * COLUMNAS + columna) == 0)
    {
        *(codigos + fila * COLUMNAS + columna) = 0;
        printf("Producto dado de baja por falta de stock! \n");
    } else
    {
        printf("Stock actualizado correctamente. \n");
        if (*(stock + fila * COLUMNAS + columna) < 5)
        {
            printf("CUIDADO, stock del producto muy bajo. Contactar proveedor \n");
        }      
    }
}

void moverProducto(int *codigos, int *stock)
{
    int filaOrigen, columnaOrigen, filaDestino, columnaDestino;
    printf("\n Ingrese la fila de origen: ");
    scanf("%d", &filaOrigen);
    printf("\n Ingrese la columna de origen: ");
    scanf("%d", &columnaOrigen);
    printf("\n Ingrese la fila de destino: ");
    scanf("%d", &filaDestino);
    printf("\n Ingrese la columna de destino: ");
    scanf("%d", &columnaDestino);

    if (filaOrigen < 0 || filaOrigen >= FILAS || columnaOrigen < 0 || columnaOrigen >= COLUMNAS)
    {
        printf("Posicion original fuera de rango.\n");
        return;
    }
   
    if (filaDestino < 0 || filaDestino >= FILAS || columnaDestino < 0 || columnaDestino >= COLUMNAS)
    {
        printf("Posicion destino fuera de rango.\n");
        return;
    }

    if (*(codigos + filaOrigen * COLUMNAS + columnaOrigen) == 0)
    {
        printf("No hay producto en la posicion original.\n");
        return;
    }

    if (*(codigos + filaDestino * COLUMNAS + columnaDestino) != 0)
    {
        printf("La posicion nueva ya esta ocupada. \n");
        return;
    }

    *(codigos + filaDestino * COLUMNAS + columnaDestino) = *(codigos + filaOrigen * COLUMNAS + columnaOrigen);
    *(stock + filaDestino * COLUMNAS + columnaDestino) = *(stock + filaOrigen * COLUMNAS + columnaOrigen);

    printf("El producto fue movido exitosamente. \n");
    printf("Ahora la posicion [%d][%d] esta libre. \n", filaOrigen, filaDestino);
   
    *(codigos + filaOrigen * COLUMNAS + columnaOrigen) = 0;
    *(stock + filaOrigen * COLUMNAS + columnaOrigen) = 0;
   
}

void buscarProducto(int *codigos, int *stock)
{
    int codigo, encontrado = 0;
    printf("\n Ingrese el codigo de producto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (*(codigos + i * COLUMNAS + j) == codigo)
            {
                printf("\n Producto encontrado en [%d][%d]", i, j);
                printf("\n Stock del producto: %d", *(stock + i * COLUMNAS + j));
                encontrado = 1;
            }            
        }
    }
    if (!encontrado)
    {
        printf("Producto codigo %d, no encontrado.", codigo);
    }
}

void mostrarReportes(int *codigos, int *stock)
{
    int opcion;

        printf("\n Que reporte esta buscando?");
        printf("\n 1. Mapa del deposito.");
        printf("\n 2. Top 3 productos con mayor stock.");
        printf("\n 3. Cantidad total de espacios libres y ocupados.");
        printf("\n 4. Mostrar posiciones libres.");
        printf("\n 5. Mostrar productos que se estan por quedar sin stock.");
        printf("\n 0. Volver al menu");
        scanf("%d", opcion);


    switch (opcion)
    {
    case 1:
        mostrarMapaDeposito(codigos, stock);
        break;
    case 2:
        mostrarTopProductos(codigos, stock);
        break;
    case 3:
        mostrarEspaciosLibresOcupados(codigos);
        break;
    case 4:
        mostrarPosicionesLibres(codigos);
        break;
    case 5:
        mostrarProductosBajoStock(codigos, stock);
        break;    
    default:
        printf("\n Volviendo al menu \n");
        break;
    }
   
}

void mostrarMapaDeposito(int *codigos, int *stock)
{
    printf("\n --- Mapa del deposito --- \n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("[%d] ", *(codigos + i * COLUMNAS + j));
        }
        printf("\n");
    }    
}

void mostrarTopProductos(int *codigos, int *stock) // Lo hice con chatGPT no sabia como encararlo.
{
    printf("\n--- Top 3 productos con mayor stock ---\n");

    int topCodigos[3] = {0, 0, 0};  // Códigos de productos
    int topStocks[3] = {0, 0, 0};   // Sus respectivos stocks

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int codigoActual = *(codigos + i * COLUMNAS + j);
            int stockActual = *(stock + i * COLUMNAS + j);

            if (codigoActual != 0) { // Solo productos válidos
                // ¿Es mejor que el mejor actual?
                if (stockActual > topStocks[0]) {
                    // Desplazar los anteriores
                    topStocks[2] = topStocks[1];
                    topCodigos[2] = topCodigos[1];
                   
                    topStocks[1] = topStocks[0];
                    topCodigos[1] = topCodigos[0];
                   
                    // Guardar el nuevo mejor
                    topStocks[0] = stockActual;
                    topCodigos[0] = codigoActual;
                }
                // ¿Es mejor que el segundo mejor?
                else if (stockActual > topStocks[1]) {
                    topStocks[2] = topStocks[1];
                    topCodigos[2] = topCodigos[1];
                   
                    topStocks[1] = stockActual;
                    topCodigos[1] = codigoActual;
                }
                // ¿Es mejor que el tercer mejor?
                else if (stockActual > topStocks[2]) {
                    topStocks[2] = stockActual;
                    topCodigos[2] = codigoActual;
                }
            }
        }
    }

    // Mostrar resultados
    for (int k = 0; k < 3; k++) {
        if (topCodigos[k] != 0)
            printf("Puesto %d: Código %d con %d unidades en stock.\n", k+1, topCodigos[k], topStocks[k]);
    }
}

void mostrarEspaciosLibresOcupados(int *codigos)
{
    int libres = 0;
    int ocupados = 0;
    printf("\n --- Cantiadad de espacios libres y ocupados --- \n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; i < COLUMNAS; j++)
        {
            if (*(codigos + i * COLUMNAS + j) == 0)
            {
                libres++;
            }
            else
            {
                ocupados++;
            }            
        }        
    }
    printf("\n Espacios libres: %d", libres);
    printf("\n Espacios ocupados: %d", ocupados);
}

void mostrarPosicionesLibres(int *codigos)
{
    printf("\n --- Posiciones libres en desposito --- \n");
    for(int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (*(codigos + i * COLUMNAS + j) == 0)
            {
                printf("\n -> [%d][%d] ", i ,j);
            }
           
        }
       
    }
   
}

void mostrarProductosBajoStock(int *codigos, int *stock)
{
    printf("\n --- Productos bajo stock --- \n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (*(stock + i * COLUMNAS + j) <= 5)
            {
                printf("\n Posicion [%d][%d] \n \t Codigo %d \n \t Stock %d", i, j, *(codigos + i * COLUMNAS + j), *(stock + i * COLUMNAS + j));
            }            
        }        
    }    
}