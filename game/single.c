#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "integration.h"
#include "init.h"

void singlee(SDL_Surface *ecran)
{
	char ch[10];
	Background B, Back [20];
	perso p;
	input in;
	int running =1;
	int f;
	
	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	
	screen = SDL_SetVideoMode(1280, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	initperso(&p);
	initBackground(&B);
	

	while (running)
	{	
		afficherBack (B,screen);
		afficher_perso(&p,screen);
		
		animation(&B,screen);
		
		getinput_bg(&in,running);
		if(p.pos.x>=600)
		{
			p.pos.x=600;
		}
		getinput(&in);
		scrolling(&B,&in);
		f = collisionPP(p,B.Masque);
		
		deplacer_perso(&in,&p);
		animer_player(&p);

		
		SDL_Flip(screen);	
	}
	freeBackground(&B);
	liberer_perso1(&p);
	SDL_Quit();
}
