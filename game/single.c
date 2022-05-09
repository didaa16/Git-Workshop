#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "integration.h"
#include "menu.h"

void singlee(SDL_Surface *ecran)
{
	char ch[10];
	Background B, Back [20];
	perso p;
	input in;
	int running =1;
	int f;
	ennemi e;
	coin c,c2;	
	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	initperso(&p);
	initBackground(&B);
	initennemi(&e);
	initcoin(&c);
	//initcoin2(&c2);

	while (running)
	{
		afficherBack (B,ecran);
		afficher_perso(&p,ecran);
		affichercoin(&c,ecran);
		//affichercoin(&c2,ecran);
		afficherennemi(&e,ecran);
		
		getinput_bg(&in,running);
		if(p.pos.x>=600)
		{
			p.pos.x=600;
		}
		getinput(&in);
		scrolling(&B,&in);
		f = collisionPP(p,B.Masque);
		
		deplacement(&e);
		deplacementcoin(&c);
		deplacer_perso(&in,&p);
		//deplacementcoin(&c2);
		
		animation(&B,ecran);
		animer_player(&p);
		animer(&e);
		animerc(&c);
		//animerc(&c2);
		
		
		int collisionn=colisionBP(&e,p.pos);


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
		SDL_Flip(ecran);	
	}
	freeBackground(&B);
	liberer_perso1(&p);
	liberer_enemi(&e);
	SDL_Quit();
}
