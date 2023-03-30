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



int main()
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
		int mouseX, mouseY;
		// Ponto a = Ponto(-400,-100);
		// Ponto b = Ponto(-50,200);
		// Ponto c = Ponto(50,200);
		// Ponto d = Ponto(400,-100);
	    Ponto a = Ponto(0,0);
		Ponto b = Ponto(0,0);
		Ponto c = Ponto(0,0);
		Ponto d = Ponto(0,0);
		Ponto ab,bc,cd,abbc,bccd;
		int quantidadep = 0;
		
		while (!quit)
		{
			window.limpar();
			//Loop principal de eventos
			while(SDL_PollEvent( &ev ) != 0)
					{
						//Usuario aperta q para sair
						if( ev.type == SDL_KEYDOWN )
						{
							if (ev.key.keysym.sym == SDLK_q)
							{
								quit = true;
							}
							
						}
						if (ev.type == SDL_MOUSEBUTTONDOWN)
						{
							if(ev.button.button == SDL_BUTTON_LEFT) 
							{
								//Quantidade de pontos
								//removido -400 no x para transformar em coordenadas no plano cartesiano
								// Adicionado 400 no y invertido para transformar coordenadas sdl em cartesianas.
								if (quantidadep == 0)
								{ 
									mouseX = ev.button.x - 400;
									mouseY = -ev.button.y + 400;
									a = Ponto(mouseX, mouseY);
									quantidadep++;
								}
								else if (quantidadep == 1)
								{ 
									mouseX = ev.button.x - 400;
									mouseY = -ev.button.y + 400;
									b = Ponto(mouseX, mouseY);
									quantidadep++;
								}
								else if (quantidadep == 2)
								{ 
									mouseX = ev.button.x - 400;
									mouseY = -ev.button.y + 400;
									c = Ponto(mouseX, mouseY);
									quantidadep++;
								}
								else if (quantidadep == 3)
								{ 
									mouseX = ev.button.x - 400;
									mouseY = -ev.button.y + 400;
									d = Ponto(mouseX, mouseY);
									quantidadep = 0;
								}
							}
						};
					}

			double t = 0.01;
			while (t < 1)
			{
				
				Ponto ab = Ponto( (1-t)*a.xcart()+ t*b.xcart(), (1-t)*a.ycart() + t*b.ycart() );
				Ponto bc = Ponto( (1-t)*b.xcart() + t*c.xcart(), (1-t)*b.ycart() + t*c.ycart() );
				Ponto cd = Ponto( (1-t)*c.xcart() + t*d.xcart(), (1-t)*c.ycart() + t*d.ycart() );

				Ponto abbc = Ponto( (1-t)*ab.xcart()+ t*bc.xcart(), (1-t)*ab.ycart() + t*bc.ycart() );
				Ponto bccd = Ponto( (1-t)*bc.xcart()+ t*cd.xcart(), (1-t)*bc.ycart() + t*cd.ycart() );

				int xp = (1-t)*abbc.xcart()+ t*bccd.xcart();
				int yp = (1-t)*abbc.ycart() + t*bccd.ycart();


				Ponto p = Ponto(xp,yp);
				
				t += 0.01;
				
				SDL_SetRenderDrawColor(window.renderer,255,0,255,SDL_ALPHA_OPAQUE);
				SDL_RenderDrawPoint(window.renderer, p.x, p.y);
			}


			SDL_SetRenderDrawColor(window.renderer,255,0,255,SDL_ALPHA_OPAQUE);

			window.desenha(a,b);
			window.desenha(b,c);
			window.desenha(c,d);
			// cout << p << "\nxp:" <<p.xcart() << "\nyp:"<<p.ycart()<< "\n";
			//

			window.atualiza();
		}
	}

	return 0;
}