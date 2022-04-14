#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


void persoo(SDL_Surface *ecran)
{
	perso p;
	map m;
	input in;
	int running=1;

	ecran=SDL_SetVideoMode (1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	initperso1(&p);
	initmap(&m);


	while(running)
	{
	afficher_map(m,ecran);
	afficher_perso1(&p,ecran);

	getinput1(&in);

	deplacer_perso1(&in,&p);
	animer_player1(&p);

	SDL_Flip(ecran);
	}
liberer_perso1(&p);
}
