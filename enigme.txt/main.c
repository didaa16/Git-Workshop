#include "fonction.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#define SCREEN_W 1360
#define SCREEN_H 760

int main()
{ 

	
	enigme e;
	SDL_Event event;
	int x,y,state=1;
	Mix_Music* music;
	int input=0;
	TTF_Init();
	SDL_Surface *screen;
	atexit(SDL_Quit);

        
       



	//Mix_VolumeMusic(MIX_MAX_VOLUME);// volume au max 
	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	
//initanimation(anime);
generer (&e);
initmusic();
//GAME LOOP
	while(state==1)
	{
		afficherEnigme(&e, screen);
		input=get_input_rep(&state,event, &e);
		resolution(&e,screen,input);
		printf("choix:%d sol:%d resolu:%d \n",e.choix,e.sol,e.resolu);
		SDL_Flip(screen);
	}



free_enig(&e);
//libereranimation(anime);
//Mix_FreeMusic(music);
TTF_Quit();
SDL_Quit();


return 0 ;
}
