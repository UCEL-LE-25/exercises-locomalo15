#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Hola SDL2",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);
    // Dibujamos un punto de color (r,g,b) en la posicion (x,y) en la pantalla
     // Esta función está adaptada partiendo de la que aparece en el manual de SDL
    void PutPixel(SDL_Surface *pantalla, int x, int y,
    unsigned char r, unsigned char g, unsigned char b)
    {
    // Bytes que ocupa un pixel
    int bpp = pantalla->format->BytesPerPixel;
    // p es un puntero al pixel que vamos a pintar
    Uint8 *p = (Uint8*)pantalla->pixels + y*pantalla->pitch + x*bpp;
    // color contendrá el valor codificado del color con el que vamos a pintar el pixel
    // teniendo ya en cuenta la profundidad de color
    Uint32 color = SDL_MapRGB(pantalla->format,r,g,b);
    switch (bpp) {
    case 1:
    *p=color;
    break;
    case 2:
    *(Uint16*)p = color;
    break;
    case 3:
    // Dependiendo del Sistema Operativo o la arquitectura hardware de nuestro ordenador
    // podemos tener distintas representaciones de los números (que ocupan mas de un byte)
    // en la memoria. En unos casos se almacena primero el byte menos signiticativo del
    // número (los bytes que forman la representación se escriben en orden inverso) y en
    // otros casos el primer bytes es el más significativo (los bytes mantienen el orden
    // en la representación interna). Los primeros se conocen como Little-Endian y los
    // segundos como Big-Endian.
    if (SDL_BYTEORDER==SDL_BIG_ENDIAN) {
    p[0]=(color»16)&0xff;
    p[1]=(color»8)&0xff;
    p[2]=color&0xff;
    } else {
        p[0]=color&0xff;
    p[1]=(color»8)&0xff;
    p[2]=(color»16)&0xff;
    }
    break;
    case 4:
    *(Uint32*)p = color;
    break;
    }
    }


    if (!window) {
        printf("Error al crear ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(3000); // Esperar 3 segundos

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
