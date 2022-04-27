#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
/**
* @strcut Background
* @brief Struct of Background 
*/
typedef struct
{
	SDL_Surface *BgImg; /*!< image du background */
	SDL_Surface *Masque; /*!< image du masque */
	SDL_Rect positionMasque; /*!< position du masque */
	SDL_Rect PositionBg; /*!< position du background */
	SDL_Rect camera; /*!< position de l'ecran */
	int anim;
	SDL_Surface *anima[50]; /* !< tableau d'animation */
	SDL_Rect posanim; /* !< position de l'animation */
	Mix_Music *music; /* !< chargement du musique */
}Background;
/**
* @strcut input
* @brief Input keys 
*/
/*typedef struct 
{
	int left,right,up,down;
}input;*/
/*typedef struct
{
	SDL_Rect pos;
	SDL_Surface *sprite;
} perso;*/


void initBackground(Background *B);
void initperso (perso *p);
void afficherBack(Background B, SDL_Surface * screen);
void afficherperso (perso p , SDL_Surface *screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput_bg(input *in,int run);
void scrolling(perso *map ,Background *B, input *in);
int collisionPP(perso p, SDL_Surface *Masque);
void freeBackground(Background *B);
#define Finimg 12800
#endif
