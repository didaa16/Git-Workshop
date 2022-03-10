#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"

void startt(SDL_Surface *ecran)
{
image s[6];
char anim[20];
int i=5,continuer=1;
initmenus(s,anim);
SDL_Event event;
image single1,multi1,single,multi,back,back1;

	init_single(&single);
	init_single1(&single1);
	init_multi(&multi);
	init_multi1(&multi1);
	init_backk(&back);
	init_back1(&back1);

while(continuer)
{
if(i==5)
i=0;
else
i++;
afficher_animation(s,ecran,i);
SDL_Delay(50);

afficher(single,ecran);
afficher(multi,ecran);
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
	if((event.motion.x>=single.pos.x) && (event.motion.x<=780) && (event.motion.y>=single.pos.y) && (event.motion.y<=381) )
						{
						 afficher(single1,ecran);
                                                 } 
        else if((event.motion.x>=multi.pos.x) && (event.motion.x<=780) && (event.motion.y>=multi.pos.y) && (event.motion.y<=531) )
						{ 
						afficher(multi1,ecran);
						}   
	else if((event.motion.x>=back.pos.x) && (event.motion.x<=185) && (event.motion.y>=back.pos.y) && (event.motion.y<=761) )
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









