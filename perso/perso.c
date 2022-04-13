#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

void initperso(perso *p)
{
p->sprite=IMG_Load("walk_right.png");
p->pos.x=80;
p->pos.y=190;
p->etat=REPOS;
p->direction=RIGHT;
p->v_x=4;
p->v_saut=-6.5;
p->v_y=p->v_saut;
p->time=TIME;
p->nbr=0;
}
void initmap(map *m)
{
m->background=IMG_Load("backg-perso.jpg");
m->pos.x=0;
m->pos.y=0;

}

void afficher(map m,SDL_Surface *ecran)
{
SDL_BlitSurface(m.background,NULL,ecran,&m.pos);
}

void afficher_perso(perso *p,SDL_Surface *screen)
 {
 SDL_Rect pos1,pos2;
 pos1.x=p->pos.x;
 pos1.y=p->pos.y;
 pos1.h=p->pos.h;
 pos1.w=p->pos.w;
 
 pos2.x=p->nbr*125;
 pos2.y=0;
 pos2.w=125;
 pos2.h=160;
 SDL_BlitSurface(p->sprite,&pos2,screen,&pos1);
 }
void getinput(input *in)
{
SDL_Event event;
SDL_PollEvent(&event);// if

	switch(event.type)
	{	case SDL_QUIT:
		exit(0);
		break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
			exit(0);
			break;
			case SDLK_LEFT:
			in->left=1;
			break;
			case SDLK_RIGHT:
			in->right=1;
			break;
			/*case SDLK_UP:
			in->up=1;
			break;
			
			case SDLK_DOWN:
			in->down=1;
			break;*/
			
			case SDLK_SPACE:
			in->jump=1;
			break;
			default:
			break;
									
		}
		break;
		case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{

			case SDLK_LEFT:
			in->left=0;
			break;
			case SDLK_RIGHT:
			in->right=0;
			break;
			/*case SDLK_UP:
			in->up=0;
			break;
			case SDLK_DOWN:
			in->down=0;
			break;*/
			case SDLK_SPACE:
			in->jump=0;
			break;
			default:
			break;						
		}
		break;
	}
}

void deplacer_perso(input *in , perso *p)
{
	if(in->left==1)
	{
		p->pos.x-=SPEED;
		p->direction=LEFT;
		if(p->pos.x<0)
		{
			p->pos.x=0;
		}
		if(p->etat!=WALK_LEFT)
		{
			p->etat=WALK_LEFT;
			p->sprite=IMG_Load("left.png");
			p->nbr=0;
		}
	}
	else if(in->right==1)
	{
		p->pos.x+=SPEED;
		p->direction=RIGHT;
		if(p->pos.x+LARGEUR_JOUEUR>=LARGEUR_ECRAN)
		{
			p->pos.x=LARGEUR_ECRAN-LARGEUR_JOUEUR;
		}
		if(p->etat!=WALK_RIGHT)
		{
			p->etat=WALK_RIGHT;
			p->sprite=IMG_Load("right.png");
			p->nbr=0;
		}
	}
	else if((in->right==0)&&(in->left==0)&&(in->jump==0))
	{	if(p->etat!=REPOS)
		{	p->etat=REPOS;
			if(p->direction==LEFT)
			{
				p->sprite=IMG_Load("walk_left.png");
				p->nbr=0;
			}
			else
			{
				p->sprite=IMG_Load("walk_right.png");
				p->nbr=0;
			}
		}
		
	}
	/*if(in->up==1)
	{
		p->pos.y-=SPEED;
		if(p->pos.y<0)
		{
			p->pos.y=0;
		}
	}
	else if(in->down==1)
	{
		p->pos.y+=SPEED;
		if(p->pos.y+HAUTEUR_JOUEUR>=HAUTEUR_ECRAN)
		{
			p->pos.y=HAUTEUR_ECRAN-HAUTEUR_JOUEUR;
		}
	}*/
	if (in->jump==1)
	{	
		p->pos.y-=JUMP_HAUTEUR;	
		if(p->pos.y<0)
		{
			p->pos.y=0;
		}
		if((p->direction==RIGHT)&&(p->etat != JUMP_RIGHT))
		{	
			p->etat=JUMP_RIGHT;
			p->sprite=IMG_Load("right.png");
		}	
		else if ((p->direction==LEFT)&&(p->etat != JUMP_LEFT))
		{	
			p->etat=JUMP_LEFT;
			p->sprite=IMG_Load("left.png");
		}	
	}
	p->pos.y+=GRAVITY_SPEED;// a verifier
	if((p->pos.y<MAX_FALL_SPEED) &&(p->direction==RIGHT) )
	{	
		p->pos.x+=p->v_x;
		p->v_y+=GRAVITY_SPEED; 
	}
	else if((p->pos.y<MAX_FALL_SPEED) &&(p->direction==LEFT) )
	{	
		p->pos.x-=p->v_x;
		p->v_y+=GRAVITY_SPEED; 
	}	
	if(p->pos.y>=MAX_FALL_SPEED)
	{
		p->pos.y=MAX_FALL_SPEED;
	}
}
void animer_player(perso *p)
{
 

 
 if(p->time<=0)
 {
 p->nbr++;
p->time=TIME;	
 	if(p->nbr>=p->sprite->w/125)
 	{
 	p->nbr=0;
 	}
 }
 else
 {
 p->time--;
 }
 }
 


/*void init_sprite_right(perso *p)
{
 p->sprite=IMG_Load("sprite_right.png");

 p->nbr=0;
 p->time=wicked;
 p->possprite.x=0;
 p->possprite.y=0;
 p->possprite.w=163; // nbre de ligne 
 p->possprite.h=24;  //nbre de colonne  
 p->pos.x=100;
 p->pos.y=40;
 p->direction=0;
}
 
 
void afficherennemi(perso *p,SDL_Surface *screen)
 {
 SDL_Rect pos1,pos2;
 pos1.x=p->pos.x;
 pos1.y=p->pos.y;
 pos1.h=p->possprite.h;
 pos1.w=p->possprite.w;
 
 pos2.x=p->nbr*(77/12);
 pos2.y=0;
 pos2.w=77/12;
 pos2.h=24;
 SDL_BlitSurface(p->sprite,&pos2,screen,&pos1);
 }
 
void liberer(perso *p)
{
SDL_FreeSurface(p->sprite);

}
*/









