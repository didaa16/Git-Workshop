#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include"init.h"
#include"perso.h"
#include"menu.h"

void startt(SDL_Surface *ecran)
{
image s[6];
char anim[20];
int j=5,continuer=1,tap,i=1;
initmenus(s,anim);
SDL_Event event;
image single1,multi1,single,multi,back,back1;
Mix_Chunk *clickmusic;

clickmusic=Mix_LoadWAV("son.wav");

	init_single(&single);
	init_single1(&single1);
	init_multi(&multi);
	init_multi1(&multi1);
	init_backk(&back);
	init_back1(&back1);

while(continuer)
{
if(j==5)
j=0;
else
j++;
afficher_animation(s,ecran,j);
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
{ 
case SDLK_ESCAPE:
continuer=0;

case SDLK_UP:
  Mix_PlayChannel(1,clickmusic,0);
	if (i==1)
		{i=3;}
	else
	        {
	        i--;
	        }
break;
case SDLK_DOWN:
  Mix_PlayChannel(1,clickmusic,0);
	if(i==3)
              	{i=1;}
	else
              { 
              i++;
          }
break;

case SDLK_RETURN:
if(i==1)
{
singlee(ecran);
Mix_PlayChannel(1,clickmusic,0);
}
else if (i==2)
{
//multii(ecran);
Mix_PlayChannel(1,clickmusic,0);
}
else if (i==3)
{
continuer=0;
Mix_PlayChannel(1,clickmusic,0);
}
break;
}
break;
case SDL_MOUSEMOTION:
	if((event.motion.x>=single.pos.x) && (event.motion.x<=780) && (event.motion.y>=single.pos.y) && (event.motion.y<=381) )
						{
						 afficher(single1,ecran);
						 tap=1;		 
                                                 } 
        else if((event.motion.x>=multi.pos.x) && (event.motion.x<=780) && (event.motion.y>=multi.pos.y) && (event.motion.y<=531) )
						{ 
						afficher(multi1,ecran);
						//tap=2;
						}   
	else if((event.motion.x>=back.pos.x) && (event.motion.x<=185) && (event.motion.y>=back.pos.y) && (event.motion.y<=761) )
						{ 
						afficher(back1,ecran);
						tap=0;
						}           
break;
case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
switch (tap)
{
case 0:
continuer=0;
break;
case 1:
singlee(ecran);
break;
//case 2:
//multii(ecran);
//break;
}
break;

}
}
if(i==1)
{
 afficher(single1,ecran);
}
else if (i==2)
{
 afficher(multi1,ecran);
}
else if(i==3)
{
afficher(back1,ecran);
}


SDL_Flip(ecran);
}
}









