#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "integration.h"


void multii(SDL_Surface *ecran)
{
	char ch[10];
	Background B, Back [20];
	perso p1,p2;
	input in;
	int running =1;
	int f;
	ennemi e;
	coin c,c2;	
	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	initperso(&p1);
	p2.pos.x=400;
	initperso(&p2);
	initBackground(&B);
	initennemi(&e);
	initcoin(&c);
	//initcoin2(&c2);

	while (running)
	{
		afficherBack(B,ecran);
		afficher_perso(&p1,ecran);
		afficher_perso(&p2,ecran);
		affichercoin(&c,ecran);
		//affichercoin(&c2,ecran);
		afficherennemi(&e,ecran);
		
		getinput_bg(&in,running);
		if(p1.pos.x>=600)
		{
			p1.pos.x=600;
		}
		if(p2.pos.x>=500)
		{
			p2.pos.x=500;
		}
		getinput(&in);
		
		scrolling(&B,&in);
		//f = collisionPP(p,B.Masque);
		
		deplacer_perso2(&in,&p1,1);
		deplacer_perso2(&in,&p2,2);
		deplacement(&e);
		deplacementcoin(&c);
		//deplacementcoin(&c2);
		
		animer_player(&p1);
		animer_player(&p2);
		animer(&e);
		animerc(&c);
		//animerc(&c2);
		animation(&B,ecran);
		
		
	
		int collisionn1=colisionBP(&e,p1.pos);
		int collisionn2=colisionBP(&e,p2.pos);

		//int collisionn=collision(pos,&e);

		if (collisionn1==1)
		{
		e.posscreen.x=0;
		e.direction=1;
		}
		else if (collisionn1==2)
		{
		e.direction=0;
		}
		
		if (collisionn2==1)
		{
		e.posscreen.x=0;
		e.direction=1;
		}
		else if (collisionn2==2)
		{
		e.direction=0;
		}
		
		SDL_Flip(ecran);	
	}
	//freeBackground(&B);
	liberer_perso1(&p1);
	liberer_perso1(&p2);
	liberer_enemi(&e);
	SDL_Quit();
}
