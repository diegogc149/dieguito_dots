#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    // Inicializar SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return -1;
    
    // Crear ventana
    window = SDL_CreateWindow("Mi App SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Loop principal
    int running = 1;
    SDL_Event event;
    
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = 0;
        }
        
        // Limpiar pantalla
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // Dibujar un rectángulo rojo
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = {100, 100, 200, 150};
        SDL_RenderFillRect(renderer, &rect);
        
        SDL_RenderPresent(renderer);
    }
    
    // Limpiar
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
