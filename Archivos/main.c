#include <stdio.h>

int main()
{
    printf("\n Manejo de archivos \n");
    FILE *archivo = fopen("escritura.txt", "r");
    if(archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char linea[100];

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}