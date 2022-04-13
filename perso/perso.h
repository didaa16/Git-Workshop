#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct perso
{
SDL_Surface *sprite;
SDL_Rect pos ;// tableau calculé une seule fois dans init
//SDL_Rect possprite;
int etat,direction,nbr,time;
int v_saut,v_x,v_y;

}perso;
typedef struct map 
{
SDL_Surface *background;
SDL_Rect pos;
}map;
typedef struct input 
{
int left,right,up,down,jump;
}input;


void initperso(perso *p);
void initmap(map *m);
void afficher(map m,SDL_Surface *ecran);
void afficher_perso(perso *p,SDL_Surface *ecran);
void getinput(input *in);
void deplacer_perso(input *in , perso *p);
void animer_player(perso *p);
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
#define MAX_FALL_SPEED  190 // ajouter la signification de chaque constante
#define GRAVITY_SPEED	4
#define REPOS 		0
#define LARGEUR_JOUEUR  93
#define HAUTEUR_JOUEUR  278
#define LARGEUR_ECRAN   1280
#define HAUTEUR_ECRAN   800 
#endif
