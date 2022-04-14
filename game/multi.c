#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "init.h"

void multii(SDL_Surface *ecran)
{
perso p,p1;
map m;
input in,inn;
SDL_Event event;
int running=1;
ecran=SDL_SetVideoMode(1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

//initmap(&m);
while(running)
{
//afficher_map(m,ecran);
persoo(ecran);
persoo2(ecran);


SDL_PollEvent(&event);

switch(event.type)
{	case SDL_QUIT:
	running=0;
	break;
	case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{	 
	case SDLK_ESCAPE:
	running=0;
	break;
	case SDLK_f:
    	SDL_WM_ToggleFullScreen(ecran);
    	break;
	}
	break;
}

SDL_Flip(ecran);
}
liberer_perso1(&p);
liberer_perso2(&p1);
}
