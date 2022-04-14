#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


void persoo2(SDL_Surface *ecran)
{
	perso p,p1;
	map m;
	input in,inn;
	int running=1;

	ecran=SDL_SetVideoMode (1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	initperso2(&p1);
	//initmap(&m);


	while(running)
	{
	//afficher_map(m,ecran);
	afficher_perso2(&p1,ecran);

	getinput2(&inn);

	deplacer_perso2(&inn,&p1);
	animer_player2(&p1);

	SDL_Flip(ecran);
	}
liberer_perso2(&p1);
}
