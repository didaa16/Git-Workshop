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
	SDL_Surface *BgImg, *BgImg1; /*!< image du background */
	SDL_Surface *Masque,  *Masque1 ;/*!< image du masque */
	SDL_Rect positionMasque, positionMasque1 ; /*!< position du masque */
	SDL_Rect PositionBg, PositionBg1 ;/*!< position du background */
	SDL_Rect camera, camera1 ; /*!< position de l'ecran */
	int anim,anim1;
	SDL_Surface *anima[50],*anima1[50]; /* !< tableau d'animation */
	SDL_Rect posanim , posanim1; ;/* !< position de l'animation */
	Mix_Music *music; /* !< chargement du musique */
}Background;
/**
* @strcut input
* @brief Input keys 
*/
typedef struct 
{
	int left,right,up,down,left1,right1,up1,down1;
}input;

typedef struct
{
	SDL_Rect positionperso;
	SDL_Surface *sprite;
} Personne;

void initBackground(Background *B);
//void initperso (Personne *p);
void afficherBack(Background B, SDL_Surface * screen);
void afficherPartage (Background B,SDL_Surface *screen);
//void afficherperso (Personne p , SDL_Surface *screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput(input *in,int run);
void scrolling(Personne *map ,Background *B, input *in);
void scrolling1(Personne *p ,Background *B, input *in);
int collisionPP(Personne p, SDL_Surface *Masque);
void freeBackground(Background *B);

#endif
