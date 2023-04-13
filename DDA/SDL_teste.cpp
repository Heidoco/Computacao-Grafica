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
		Ponto a = Ponto(0,0);
		Ponto b = Ponto(320,240);
		
		while (!quit)
		{
			window.limpar();
			

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
							if (ev.key.keysym.sym == SDLK_a)
							{
								angulo += M_PI/6;
								b.x = (int)(a.x + (a.x*cos(angulo) -  a.y*sin(angulo)));
								b.y = (int)(a.y + (-a.x*sin(angulo) - a.y*cos(angulo)));
							}
						}
					};
			//cout << a.x << " "<< a.y << "\n";

			window.dda(a, b);


			window.atualiza();			
		}
	}

	return 0;
}