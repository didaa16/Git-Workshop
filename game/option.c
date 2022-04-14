#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"
#include"menu.h"
void optionn(SDL_Surface *ecran)
{
image p[6],back,back1,bare1[5],bare2[5],sound,sfx,title,full,full1,full2,pl,pl1,m,m2,plus,plus1,moin,moin1;
char anim[20],barr1[20],barr2[20];
int i=5,continuer=1,taper=0,s=0;
SDL_Event event;

initmenup(p,anim);
init_backk(&back);
init_back1(&back1);
init_sfx(&sfx);
init_sound(&sound);
init_bare1(bare1,barr1);
init_bare2(bare2,barr2);
init_title(&title);
init_full(&full);
init_full1(&full1);

init_pl(&pl);
init_pl1(&pl1);
init_m(&m);
init_m1(&m2);
init_plus(&plus);
init_plus1(&plus1);
init_moin(&moin);
init_moin1(&moin1);

while(continuer)
{
if(i==5)
i=0;
else
i++;
afficher_animation(p,ecran,i);
SDL_Delay(80);


afficher(back,ecran);
afficher(bare1[0],ecran);
afficher(bare2[0],ecran);
afficher(sfx,ecran);
afficher(sound,ecran);
afficher(title,ecran);
afficher(full,ecran);
afficher(full1,ecran);

afficher(pl,ecran);
afficher(m,ecran);
afficher(plus,ecran);
afficher(moin,ecran);
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
break;

}

case SDL_MOUSEMOTION:
if((event.motion.x>=back.pos.x) && (event.motion.x<=185) && (event.motion.y>=back.pos.y) && (event.motion.y<=760))
						{ 
						afficher(back1,ecran);
						s=0;
						} 
if((event.motion.x>=565) && (event.motion.x<=716) && (event.motion.y>=590) && (event.motion.y<=657))
						{ 
						s=2;
						}
 if((event.motion.x>=m.pos.x) && (event.motion.x<=505) && (event.motion.y>=m.pos.y) && (event.motion.y<=201))
						{
						s=1;
						}		
break;


case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
switch (s)
{
case 0:
continuer=0;
break;
case 1:
afficher(m2,ecran);
break;
case 2:
afficher(full1,ecran);
break;
}
break;

}

}
SDL_Flip(ecran);
}

}











/*
//----------------------------------------------------VOLUME

			if  ( ( x > O.pos_soundminus.x ) && ( x < O.pos_soundminus.x + O.pos_soundminus.w ) && ( y > O.pos_soundminus.y ) && ( y < O.pos_soundminus.y + O.pos_soundminus.h )&&(event.button.button==SDL_BUTTON_LEFT) )
		{if(volume>0)
     		     {volume-=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;
}

  		   if ( ( x > O.pos_soundplus.x ) && ( x < O.pos_soundplus.x + O.pos_soundplus.w ) && ( y > O.pos_soundplus.y ) && ( y < O.pos_soundplus.y + O.pos_soundplus.h )&&(event.button.button==SDL_BUTTON_LEFT) )
   		 { if(volume<100)
     		     {volume+=20;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}
		   if ( ( x > m.pos_soundon.x ) && ( x < m.pos_soundon.x + m.pos_soundon.w ) && ( y > m.pos_soundon.y ) && ( y < m.pos_soundon.y + m.pos_soundon.h )&&(event.button.button==SDL_BUTTON_LEFT) )
   		 {
		   if(volume>0)
     		     {Mix_VolumeMusic(0);
		      Vol=volume;
		      volume=0;}
		   else 
     		     {volume=Vol;
       		    Mix_VolumeMusic(volume);}
			SDL_Delay(200) ;}

//--------------------------------------------------------volume wfé




SDL_BlitSurface(O.img_soundminus,NULL,screen,&O.pos_soundminus);
	SDL_BlitSurface(O.img_soundplus,NULL,screen,&O.pos_soundplus);
	if (volume>0)
		{
		SDL_BlitSurface(m.img_soundon,NULL,screen,&m.pos_soundon);
		}
	else
		{
		SDL_BlitSurface(m.img_soundoff,NULL,screen,&m.pos_soundon);
		}
		
	SDL_Flip(screen);

//Volume
typedef struct{

SDL_Surface *img_soundminus;
SDL_Surface *img_soundplus;
SDL_Rect pos_soundminus,pos_soundplus;
}volume;

typedef struct{

SDL_Surface *img_soundon;
SDL_Surface *img_soundoff;
SDL_Rect pos_soundon;
}mute;
//-----------------------------------------------------

*/



