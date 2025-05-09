#include <stdio.h>
#include <stdbool.h> //Primer error utiliza bools pero no llama a la biblioteca.
int main(){
    int vida = 100; //Segundo error, debe inicializar vida en 100 para poder entrar al if.
    float escudo = 25;
    bool tienePocion = true;
//error principal del programa, mala sintaxis para el if, nunca abre y cierra llaves.
    if (vida = 100 && escudo>0)  //tercer error, En vida no esta comparando con 100, esta asignando.
    {
        printf("Jugador con vida y escudo \n");
    }
    else if (vida > 0 && tienePocion) //cuarto error, tiene que ser un AND no un OR.
    {
        printf("Jugador herido pero con posibilidad de curarse \n "); //No es error pero es mejora, falta el salto de linea.
    }
    else if (vida<0)
    {
        printf("Jugador muerto \n");
    }
    else
    {
        printf("Estado desconocido. \n", vida); //El vida esta de mas. Corre, pero no esta bien. Deberia pasarse un %d para que printee.
    }
    return 0;
}