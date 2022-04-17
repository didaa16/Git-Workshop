/**
* @file main.c
* @brief main program
* @author C team
* @version 0.1
* @date April 17,2022
*
*/
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
	Personne p;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen=NULL;
	screen = SDL_SetVideoMode(1280, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode: %s /n",SDL_GetError());
	}
	int running =1;
	int f;
	input in;
	initBackground(&B);
	initperso (&p);

	while (running)
	{	
		afficherBack (B,screen);
		animation(&B,screen);
		afficherperso (p,screen);
		getinput(&in,running);
		scrolling(&p,&B,&in);
		f = collisionPP(p,B.Masque);
		printf("%d",f);
		SDL_Flip(screen);	
	}
	freeBackground(&B);
	SDL_Quit();
	return 0;
}
