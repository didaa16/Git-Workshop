#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"
void creditt(SDL_Surface *ecran)
{
image t[36],back,back1;
image c[6];
char anim[20],anim1[36];
int i=5,continuer=1,j=36;

initmenuc(c,anim);
initbutton(t,anim1);
init_backk(&back);
init_back1(&back1);
SDL_Event event;

while(continuer)
{
if(i==5)
i=0;
else
i++;

 if(j<36)
j++;	
 	
  else
  j=0;
afficher_animation(c,ecran,i);
afficher_animationt(t,ecran,j);
afficher(back,ecran);

while(SDL_PollEvent(&event))
{
switch(event.type)
{	case SDL_QUIT:
		continuer=0;
	break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{ case SDLK_ESCAPE:
continuer=0;
}
break;
case SDL_MOUSEMOTION:
if((event.motion.x>=back.pos.x) && (event.motion.x<=185) && (event.motion.y>=back.pos.y) && (event.motion.y<=761) )
						{ 
						afficher(back1,ecran);
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
continuer=0;
break;
						}           
break;
}
}
SDL_Flip(ecran);
}
}

