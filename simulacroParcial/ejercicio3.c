#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int flechas[10];
    int aciertos = 0, fallos = 0;

    srand(time(NULL)); // le pasamos el time null para que no repita siempre la misma secuencia.

    for (int i = 0; i < 10; i++) {
        // 60% de probabilidad de impactar: números menores a 60 (0-59)
        int impacto;
        if (rand() % 100 < 60) { //rand() % 100 reduce el rango a 0-99
            impacto = 1; 
        } else {
            impacto = 0;
        }
        flechas[i] = impacto;

        if (impacto)
            aciertos++;
        else
            fallos++;
    }

    
    printf("Resultado de las flechas: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", flechas[i]);
        if (i < 9) printf(", ");
    }

    printf("\nAciertos: %d\n", aciertos);
    printf("Fallos: %d\n", fallos);

    return 0;
}
