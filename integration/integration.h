/**  
* @file integration.h
*/  
#ifndef INTEGRATION_H_INCLUDED
#define INTEGRATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/**  
* @struct perso  
* @brief struct for personage  
*/  
typedef struct perso
{
	SDL_Surface *sprite;/*!<*/
	SDL_Rect pos ;/*!< la position du personnage */ 
	int etat,direction,nbr,time;/*!< l'etat,la direction et nbr de faces du personnage*/ 
	int v_saut,v_x,v_y;/*!< vecteur du saut */ 
}perso;

/**  
* @struct input  
* @brief struct for input  
*/
typedef struct input 
{
	int left,right,up,down,jump;/*!< les mouvement du personnage */ 
}input;

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

void initperso(perso *p);
void afficher_perso(perso *p,SDL_Surface *ecran);
void getinput(input *in);
void deplacer_perso(input *in , perso *p);
void animer_player(perso *p);
void liberer_perso1(perso *p);
void initBackground(Background *B);
void afficherBack(Background B, SDL_Surface * screen);
void animation (Background *B,SDL_Surface * screen) ;
void getinput_bg(input *in,int run);
void scrolling(Background *B, input *in);
int collisionPP(perso p, SDL_Surface *Masque);
void freeBackground(Background *B);


#define TIME		8
#define LEFT 		1
#define RIGHT		2
#define JUMP 		3
#define WALK_LEFT 	1
#define WALK_RIGHT	2
#define JUMP_RIGHT 	3
#define JUMP_LEFT 	4
#define JUMP_HAUTEUR 	13
#define SPEED 		5
#define MAX_FALL_SPEED  190 
#define GRAVITY_SPEED	4
#define REPOS 		0
#define LARGEUR_JOUEUR  93
#define HAUTEUR_JOUEUR  278
#define LARGEUR_ECRAN   12800
#define HAUTEUR_ECRAN   800 
#endif
