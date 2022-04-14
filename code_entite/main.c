#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"

int main (int argc , char** argv)
{


/*--------------------------------------------------------------------------------------------------*/
SDL_Surface *screen=NULL;

int continuer=3;

SDL_Surface *bg=NULL;
SDL_Rect posbg;

//position map
posbg.x=0;
posbg.y=0;

//variables
ennemi e;
coin c,c2;

SDL_Surface *p=NULL;

p=IMG_Load("perso1.png");

SDL_Rect posp;

posp.x=300;
posp.y=400;
posp.w=41;
posp.h=70;

//some variables
SDL_Event event;

SDL_Rect camera;

camera.h=100;
camera.w=250;
camera.x=0;
camera.y=154;


/*--------------------------------------------------------------------------------------------------*/
SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(2000,512,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);
	
	SDL_WM_SetCaption("entite 2nd",NULL);

if(!screen)
{
 printf ("Unable to set video: %s\n" ,SDL_GetError());
 return 1;
}
/*--------------------------------------------------------------------------------------------------*/

bg=IMG_Load("big_map.png");
initennemi(&e);
initcoin(&c);
initcoin2(&c2);

SDL_Event ev;
//boucle infinie !
while (continuer)
{
SDL_BlitSurface(bg,NULL,screen,&posbg);
SDL_BlitSurface(p,NULL,screen,&posp);
affichercoin(&c,screen);
//affichercoin(&c2,screen);
afficherennemi(&e,screen);



SDL_PollEvent (&event);
animer(&e);
animerc(&c);
//animerc(&c2);
deplacement(&e);
deplacementcoin(&c);
//deplacementcoin(&c2);

int collisionn=colisionBP(&e,posp);


//int collisionn=collision(posp,&e);

if (collisionn==1)
{
//e.posscreen.x=0;
e.direction=1;
}
else if (collisionn==2)
{
e.direction=0;

}


 	
 
 
 switch(event.type)
{
	 case SDL_QUIT:
 		continuer=0;
 	 break;
 	 
 	switch(ev.type)
{

case SDL_KEYDOWN:
 {
	switch (ev.key.keysym.sym)
 {
	
   	case SDLK_RIGHT:
   		posp.x+=10;
   		SDL_BlitSurface(p,NULL,screen,&posp);
   		
  		break;
 	case SDLK_LEFT:
   		posp.x-=10;
   		SDL_BlitSurface(p,NULL,screen,&posp);
   		
  		break;
 	
}
}
}}
SDL_Flip(screen);
}
liberer(&e); 
}
