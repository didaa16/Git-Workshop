#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct
{char qst[50],rep1[50],rep2[50],rep3[50];
SDL_Surface *q,*r1,*r2,*r3;
SDL_Rect posQ,posR1,posR2,posR3;
int sol;

TTF_Font *police;
SDL_Color color;

SDL_Surface *image;
SDL_Rect pos_image;
int choix,resolu;
SDL_Surface *anim[25];
SDL_Rect anim_Pos;
}enigme;

void init_txt(enigme *t);
void initmusic();
void generer (enigme* e);
void afficherEnigme(enigme *e, SDL_Surface * screen);
int get_input_rep(int *state,SDL_Event event,enigme *e);
void resolution(enigme *e, SDL_Surface *screen,int input);
void free_enig( enigme *e );

#endif//FONCTION_H_INCLUDED

