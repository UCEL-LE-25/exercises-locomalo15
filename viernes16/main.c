#include <stdio.h>
#include <stdbool.h>
#define FILAS 3
#define COLUMNAS 3
int main()
{
    typedef struct
    {
        int cantidad;
        int precio;
        int cantRepos; //Cantidad que emite alerta a reposicion
        char nombre[20];
        int id;
    }Producto;

    Producto productos[FILAS][COLUMNAS];
    int cont = 1;
    for (int i = 0; i < FILAS; i++)
    {
        printf("\n Cargando productos Fila %d", i+1);
        for (int j = 0; j < COLUMNAS; j++)
        {
            productos[i][j].id = cont;
            cont++;
            printf("\n Ingrese nombre: ");
            scanf("%s", productos[i][j].nombre);
            printf("\n Ingrese cantidad: ");
            scanf("%d", &productos[i][j].cantidad);
            printf("\n Ingrese precio: ");
            scanf("%d", &productos[i][j].precio);
            printf("\n Ingrese cantidad de reposicion: ");
            scanf("%d", &productos[i][j].cantRepos);
        }    
    }

    int op =0;
    printf("\n 1) Cargar pedido \n ");
    printf("\n 2) Actualizar stock \n ");
    printf("\n 3) Borrar producto \n ");
    do
    {
        printf("\n Ingrese una opcion: \n ");
        scanf("%d", &op);
    } while (op<1 || op>3);
    
    switch (op)
    {
    case 1:
        printf("--- CARGAR PEDIDO ---");
        for (int i = 0; i < FILAS; i++)
        {
            for (int j = 0; j < COLUMNAS; j++)
            {
                printf("\n Nombre: %s", productos[i][j].nombre);
                printf("\n Cantidad: %d", productos[i][j].cantidad);
                printf("\n Id producto: %d", productos[i][j].id);
            }    
        }
        int carrito [3][2];
        int totPedido = 0;
        bool estadoPedido = true;
        
        for (int i = 0; i < 3; i++)
        {
            printf("\n Ingrese id: ");
            scanf("%d", &carrito[i][i]);
            printf("\n Ingrese cantidad: ");
            scanf("%d", &carrito[i][i+1]);
            for (int j = 0; j < COLUMNAS; j++)
            {
                for (int k = 0; k < FILAS; k++)
                {
                    if (carrito[i][i] == productos[j][k].id)
                    {
                        printf("\n Producto encontrado.");
                        if (productos[j][k].cantidad > carrito[i][i+1])
                        {
                            totPedido += (carrito[i][i+1] * productos[j][k].precio);
                        }else
                        {
                            printf("\n No hay stock suficiente!");
                            estadoPedido = false;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        int confirm;
        if (estadoPedido)
        {
            printf("\n El pedido fue cargado con exito.");
            printf("\n Total del pedido: %d", totPedido);
            printf("Confirmar compra? 1. Si || 2. No");
            scanf("%d", &confirm);
            if (confirm == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < COLUMNAS; j++)
                    {
                        for (int k = 0; k < FILAS; k++)
                        {
                            if (carrito[i][i] == productos[j][k].id)
                            {
                            productos[j][k].cantidad -= carrito[i][i++];                        
                            }
                            
                        }                
                    }
                }
        }else{
            printf("\n Compra cancelada");
        }

        

        }
        
        
        
        break;
    
    default:
        break;
    }
    
    return 0;
}