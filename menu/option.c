#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"
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
						case SDL_MOUSEBUTTONDOWN:
if(event.button.button==SDL_BUTTON_LEFT)
continuer=0;
break;
}    
if((event.motion.x>=full1.pos.x) && (event.motion.x<=716) && (event.motion.y>=full1.pos.y) && (event.motion.y<=657))
						{ 
						s=2;
						}
 if((event.motion.x>=m.pos.x) && (event.motion.x<=505) && (event.motion.y>=m.pos.y) && (event.motion.y<=201))
{
s=1;
}		
break;
}
switch(s)
{
case 1:
afficher(m2,ecran);
break;
case 2:
afficher(full1,ecran);
}
}
SDL_Flip(ecran);
}

}


