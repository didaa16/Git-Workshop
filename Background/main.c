#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

int main()
{
	char ch[10];
	Background B, Back [20];
	//SDL_Surface * BackgroundMasque;
	SDL_Rect Personnage;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	screen = SDL_SetVideoMode(1280, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode: %s /n",SDL_GetError());
	}
	int running =1 ;
	int f;
	input in;
	initBackground(&B);
	init (&B,screen);
	while (running)
	{	
		afficherBack (B,screen);
		affichermask (B,screen);
		animation(&B,screen); 
		
		afficherperso (B,screen);
		getinput(&in);
		scrolling(&B,&in);
		f = detectCollPP (B , B.positionperso);
		printf("%d",f);
		SDL_Flip(screen);	
	}
	freeBackground(&B);
	SDL_Quit();
	return 0;
}
