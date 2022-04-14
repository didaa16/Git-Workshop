#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL.h>
#include"init.h"
#include"menu.h"
#include"text.h"
 void afficher(image p ,SDL_Surface *ecran)
 {	
 	SDL_BlitSurface(p.img,NULL,ecran,&p.pos);
 }
 
  void afficher_animation(image menu[],SDL_Surface *screen,int i)
{
SDL_BlitSurface(menu[i].img,NULL,screen,&menu[i].pos);
	SDL_Delay(80);
}


 void afficher_animationt(image menu[],SDL_Surface *screen,int i)
{
SDL_BlitSurface(menu[i].img,NULL,screen,&menu[i].pos);
	SDL_Delay(150);
}

 void liberer(image *p)
 {
 SDL_FreeSurface(p->img);
 }
 void liberer_animation(image menu[])
{
int i;
for (i=0; i<36; i++)
{
 SDL_FreeSurface(menu[i].img);			
}
}


