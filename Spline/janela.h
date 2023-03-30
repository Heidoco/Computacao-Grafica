#include<SDL2/SDL.h>
#include "ponto.h"

class Window
{
private:
    int width;
    int height;
    SDL_Window* window = NULL;


public:
    Window(int width,int height);
    ~Window();
    SDL_Renderer *renderer;

    
    void atualiza();
    void limpar();

    void desenha(Ponto p1, Ponto p2);
};

