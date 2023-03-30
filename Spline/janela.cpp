#include "janela.h"

Window::Window(int width,int height)
{

    window = SDL_CreateWindow( "Window(s)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    
    
}

void Window::atualiza()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderPresent(renderer);
}

void Window::limpar()
{
    SDL_RenderClear(renderer);

}

/**
 * @brief Método para desenhar uma linha do ponto p2 até p1
 * 
 * @param p1 ponto p1
 * @param p2 ponto p2
 */
void Window::desenha(Ponto p1, Ponto p2)
{
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, p1.x,p1.y,p2.x,p2.y);
    cout<< p1 << " " << p2 << endl;
    
}


Window::~Window()
{
    SDL_DestroyWindow(window);
}

