#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


int main(int argc ,char *argv[])
{
	perso p;
	map m;
	input in;
	SDL_Surface *ecran;
	int running=1;

	ecran=SDL_SetVideoMode (1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

	initperso(&p);
	initmap(&m);


	while(running)
	{
	afficher(m,ecran);
	afficher_perso(&p,ecran);

	getinput(&in);

	deplacer_perso(&in,&p);
	animer_player(&p);

	SDL_Flip(ecran);
	}

//liberer
return 0;
}
