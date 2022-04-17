#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
	SDL_Surface *BgImg;
	SDL_Surface *Masque;
	SDL_Rect positionMasque;
	SDL_Rect PositionBg;
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
	SDL_Rect positionperso;
	SDL_Surface *sprite;
} Personne;

void initBackground(Background *B);
void initperso (Personne *p);
void afficherBack(Background B, SDL_Surface * screen);
void affichermask (Background B, SDL_Surface *screen);
void afficherperso (Personne p , SDL_Surface *screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput(input *in);
void scrolling(Personne *map ,Background *B, input *in);
int collisionPP(Personne p, SDL_Surface *Masque);
void freeBackground(Background *B);

#endif
