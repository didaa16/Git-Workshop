#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
#include "fonction.h"
#include "init.h"

void singlee(SDL_Surface *ecran)
{
perso p;
map m;
input in;
SDL_Event event;
int running=1;
ennemi e;
coin c,c2;

ecran=SDL_SetVideoMode(1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);


//initperso1(&p);
//initmap(&m);
initennemi(&e);
initcoin(&c);
initcoin2(&c2);



while(running)
{
//afficher_map(m,ecran);
persoo(ecran);
affichercoin(&c,ecran);
afficherennemi(&e,ecran);
//afficher_perso(&p,ecran);
//getinput1(&in);
//deplacer_perso(&in,&p);
animer(&e);
animerc(&c);
deplacement(&e);
deplacementcoin(&c);

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

liberer_entite(&e);
liberer_perso1(&p);
}
