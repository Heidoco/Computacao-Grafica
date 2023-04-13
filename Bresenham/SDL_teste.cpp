//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include "janela.h"
#include "ponto.h"
#include <iostream>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

double angulo = 0;
int linha = 1;


int main( int argc, char* args[] )
{	
	//Eventos e loop principal
	bool quit = false;	
	SDL_Event ev;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		Window window = Window(SCREEN_WIDTH,SCREEN_HEIGHT);
		Ponto a = Ponto(400,400);
		Ponto b = Ponto(800,0);
		
		while (!quit)
		{
			//Loop principal de eventos
			while( SDL_PollEvent( &ev ) != 0 )
					{
						//Usuario aperta q para sair
						if( ev.type == SDL_KEYDOWN )
						{
							if (ev.key.keysym.sym == SDLK_q)
							{
								quit = true;
							}
							if (ev.key.keysym.sym == SDLK_b)
							{
								linha = 1;
							}
							if (ev.key.keysym.sym == SDLK_d)
							{
								linha = 0;
							}
							if (ev.key.keysym.sym == SDLK_a)
							{
								angulo += M_PI/6;
								b.x = (int)(b.x + (b.x*cos(angulo) -  b.y*sin(angulo)));
								b.y = (int)(b.y + (-b.x*sin(angulo) - b.y*cos(angulo)));
							}
						}
					};
			//cout << a.x << " "<< a.y << "\n";

			//window.dda(a, b)
			int contlinha = 0;
			if (linha)
			{
				window.bresenham(a,b);
			}
			if (!linha)
			{
				window.dda(a,b);
			}
		window.atualiza();
				window.limpar();

		}
	}

	return 0;
}