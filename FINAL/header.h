#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
	SDL_Surface *BgImg;
	SDL_Surface *Mask;
	SDL_Surface *PersoImg;
	SDL_Rect positionMask;
	SDL_Rect PositionBg;
	SDL_Rect positionperso;
	SDL_Rect camera;
	int anim;
	SDL_Surface *anima[50];
	SDL_Rect posanim;
}Background;
typedef struct 
{
	int left,right,up,down;
}input;
typedef struct 
{
	SDL_Rect Personnage;
}Personne;
typedef struct 
{
	int x;
	int y;
}positionPers;

void initBackground(Background *B);
void init (Background *B , SDL_Surface * screen);
void afficherBack(Background B, SDL_Surface * screen);
void afficherperso (Background B , SDL_Surface *screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput(input *in);
void scrolling(Background *map , input *in);
void affichermask (Background B, SDL_Surface *screen);
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y);
int detectCollPP (Background B, SDL_Rect Personnage);
void freeBackground(Background *B);

#endif
