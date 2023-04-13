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
 * @brief Método para desenhar uma linha do ponto p1 até p2
 * 
 * @param p1 ponto p1
 * @param p2 ponto p2
 */
void Window::desenha(Ponto p1, Ponto p2)
{
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, p1.x,p1.x,p2.x,p2.y);
    cout<< p1 << " " << p2 << endl;
    
}

void Window::dda(Ponto a, Ponto b)
{
	int steps, k;
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	float xIncr, yIncr;
    float x = a.x;
    float y = a.y;
    SDL_SetRenderDrawColor(renderer,255,0,255,SDL_ALPHA_OPAQUE);

	if (abs(dx) > abs(dy)){
		steps = abs(dy);
	} 
	else{
		steps = abs(dy);
	}
	xIncr = dx/ (float) steps;
	yIncr = dy/ (float) steps;

	SDL_RenderDrawPoint(renderer,round(x), round(y));

    for (k = 0; k < steps; k++)
    {
        x+= xIncr;
        y+= yIncr;
        SDL_RenderDrawPoint(renderer, round(x),round(y));
    }
}

void Window::bresenham(Ponto a, Ponto b)
{
    SDL_SetRenderDrawColor(renderer,255,255,0,SDL_ALPHA_OPAQUE);
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    //P0 é igual a 2*deltay - deltax
    int p = 2*dy - dx;

    //Se abaixo do ponto médio
    int twoDy = 2*dy;

    //Se acima do ponto médio
    int twoDyDx = 2*(dy-dx);

    int x,y,xfinal;
    if (a.x > b.x)
    {
        x = b.x;
        y = b.y;
        xfinal = a.x;
    }
    else
    {
        x = a.x;
        y = a.y;
        xfinal = b.x;
    }
    //cout << "x = " << x << " y = " << y << "\n";
    SDL_RenderDrawPoint(renderer, x, y);

    while (x < xfinal)
    {
        x++;
        //Se o p for negativo, o ponto é (xk+1,yk)
        if (p < 0)
        {
            p+= twoDy;
        }
        else
        {
            y++;
            p += twoDyDx;
        }
        //cout << "x = " << x << " y = " << y << "\n";
        SDL_RenderDrawPoint(renderer, x, y);
    }
    cout << "Linha de  "<< a << "-"<<b<< "\n";
}

Window::~Window()
{
    SDL_DestroyWindow(window);
}

