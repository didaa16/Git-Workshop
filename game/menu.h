#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
struct image
{
SDL_Rect pos;
SDL_Surface *img;
};
typedef struct image image;

void afficher_animationt(image menu[],SDL_Surface *screen,int i);
void liberer(image *p);
void afficher(image p,SDL_Surface *ecran);
void afficher_animation(image menu[],SDL_Surface *screen,int i);
void liberer_animation(image menu[]);
void startt(SDL_Surface *ecran);
void optionn(SDL_Surface *ecran);
void creditt(SDL_Surface *ecran);
void singlee(SDL_Surface *ecran);
void multii(SDL_Surface *ecran);
void evenement(SDL_Surface *ecran);


#endif
