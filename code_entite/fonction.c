#include <stdio.h>
 #include<stdlib.h>
 #include"fonction.h"
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
 #include<math.h>
 
 /*--------------------------------------------------------------------------------------------------*/
 void initennemi(ennemi *e)
 {
 e->sprite=IMG_Load("big_finn.png");
 if(e->sprite==NULL){
 return ;
 }
 e->nbr=0;
 e->time=wicked;
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=276;  
 e->possprite.h=152;   
 e->posscreen.x=500;
 e->posscreen.y=390;
 e->posscreen.w=276/6;
 e->posscreen.h=152/2;
 e->direction=0;
 }
 
  void initcoin(coin *e)
 {
 e->sprite=IMG_Load("coinf.png");
 if(e->sprite==NULL){
 return ;
 }
 e->nbr=0;
 e->time=micked;
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=288;
 e->possprite.h=43;   
 e->posscreen.x=700;
 e->posscreen.y=400;
 e->direction=0;
 }
 
   void initcoin2(coin *e)
 {
 e->sprite=IMG_Load("coinf.png");
 if(e->sprite==NULL){
 return ;
 }
 e->nbr=0;
 e->time=micked;
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=288; 
 e->possprite.h=43;   
 e->posscreen.x=400;
 e->posscreen.y=400;
 e->direction=0;
 }
 
 /*--------------------------------------------------------------------------------------------------*/
 
void afficherennemi(ennemi *e,SDL_Surface *screen)
 {

 e->pos1.x=e->posscreen.x;
 e->pos1.y=e->posscreen.y;
 e->pos1.h=e->possprite.h;
 e->pos1.w=e->possprite.w;
 
 e->pos2.x=e->nbr*(276/6);
 //e->pos2.y=76/2;
 e->pos2.w=276/6;
 e->pos2.h=152/2;
 SDL_BlitSurface(e->sprite,&e->pos2,screen,&e->pos1);
 }
 
 
 
 void affichercoin(coin *e,SDL_Surface *screen)
 {
 SDL_Rect pos1,pos2;
 pos1.x=e->posscreen.x;
 pos1.y=e->posscreen.y;
 pos1.h=e->possprite.h;
 pos1.w=e->possprite.w;
 
 pos2.x=e->nbr*(288/6);
 pos2.y=0;
 pos2.w=288/6;
 pos2.h=43;
 SDL_BlitSurface(e->sprite,&pos2,screen,&pos1);
 }
 
 /*--------------------------------------------------------------------------------------------------*/
 
 void liberer(ennemi *a)
{
SDL_FreeSurface(a->sprite);
}

/*--------------------------------------------------------------------------------------------------*/

 void animer(ennemi *e)
 {
 

 
 if(e->time<=0)
 {
 e->nbr++;
e->time=wicked;	
 	if(e->nbr>=e->possprite.w/(276/6))
 	{
 	e->nbr=0;
 	}
 }
 else
 {
 e->time--;
 
 }
 
 }
  
  void animerc(coin *e)
 {
 

 
 if(e->time<=0)
 {
 e->nbr++;
e->time=micked;	
 	if(e->nbr>=e->possprite.w/(288/6))
 	{
 	e->nbr=0;
 	}
 }
 else
 {
 e->time--;
 }
 }
 /*--------------------------------------------------------------------------------------------------*/
 
 void deplacement(ennemi *e)
 {
 	
   if(e->direction==0)
   {
   
   SDL_Delay(100);	
   e->pos2.y=76;
   
   e->posscreen.x=e->posscreen.x+5;
	if(e->posscreen.x==1500)
		{
		e->direction=1;
		
		}
		
   }	
   
  else if(e->direction==1)
   {
   SDL_Delay(100);
   e->pos2.y=0;
   e->posscreen.x=e->posscreen.x-5;
   	if (e->posscreen.x==0)
   	{
   	
   	e->direction=0;
   	}
   }
   
   
  
 
 
 }
 
  void deplacementcoin(coin *c)
 {
 	
   if(c->direction==0)
   {
   SDL_Delay(100);	
   c->pos2.y=0;
   
   c->posscreen.y=c->posscreen.y-5;
	if(c->posscreen.y==390)
		{
		c->direction=1;
		
		}
		
   }	
   
  else if(c->direction==1)
   {
   SDL_Delay(100);
   c->pos2.y=0;
   c->posscreen.y=c->posscreen.y+5;
   	if (c->posscreen.y==400)
   	{
   	
   	c->direction=0;
   	}
   	
   	
   }
  
 
 
 }
 
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
 
 
 int colisionBP(ennemi *e,SDL_Rect posp)
 {
 int w=46,a=70;
 int collision=0;
 

 
if((e->posscreen.x+w >=posp.x))

{
collision=1;
//e->direction=1;
}

 /*if((posp.x+posp.w >= e->posscreen.x))
{
collision=2;

}*/

return collision; 
}
 
 
 
/* 
 int collision(SDL_Rect rec1,ennemi *e)
{
if((rec1.x + rec1.w >= e->posscreen.x)||(e->posscreen.x +(276/6)  >= rec1.x ))
return 1;
else
return 0;
}
 
 
 */
 
 
 
 
 
 
 
 
 
