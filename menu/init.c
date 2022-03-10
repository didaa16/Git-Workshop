#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"
 

  void init_options(image *background)
 {	
 	background->img=IMG_Load("Options.jpg");
 	background->pos.x=0;
 	background->pos.y=0;
 	background->pos.w=1280;
 	background->pos.h=800;
 }
 
  void init_start1(image *start1)
 {	
 	start1->img=IMG_Load("start1.png");
 	start1->pos.x=230;
 	start1->pos.y=211;
 }
 
  void init_start2(image *start2)
 {	
 	start2->img=IMG_Load("start2.png");
 	start2->pos.x=230;
 	start2->pos.y=211;
 }
  void init_setting1(image *setting1)
 {	
 	setting1->img=IMG_Load("setting1.png");
 	setting1->pos.x=230;
 	setting1->pos.y=311;
 }
  void init_setting2(image *setting2)
 {	
 	setting2->img=IMG_Load("setting2.png");
 	setting2->pos.x=230;
 	setting2->pos.y=311;
 }
  void init_credit1(image *credit1)
 {	
 	credit1->img=IMG_Load("credit1.png");
 	credit1->pos.x=230;
 	credit1->pos.y=411;
 }
  void init_credit2(image *credit2)
 {	
 	credit2->img=IMG_Load("credit2.png");
 	credit2->pos.x=230;
 	credit2->pos.y=411;
 }
  void init_exit1(image *exit1)
 {	
 	exit1->img=IMG_Load("exxit1.png");
 	exit1->pos.x=230;
 	exit1->pos.y=511;
 }
 void init_exit2(image *exit2)
 {	
 	exit2->img=IMG_Load("exit2.png");
 	exit2->pos.x=230;
 	exit2->pos.y=511;
 }
 void liberer(image *p)
 {
 SDL_FreeSurface(p->img);
 }
 void initmenu(image menu[],char anim[])
{
int i;
for (i=0; i<6; i++)
{
sprintf(anim,"backg%d.jpg",i+1);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}
 void initmenus(image menu[],char anim[])
{
int i;
for (i=0; i<6; i++)
{
sprintf(anim,"start%d.jpg",i+1);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}
void initbutton(image menu[],char anim[])
{
int i;
for (i=0; i<36; i++)
{
sprintf(anim,"%d.png",i);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}


}
void initmenuc(image menu[],char anim[])
{
int i;
for (i=0; i<6; i++)
{
sprintf(anim,"%d.jpg",i+1);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}
void initmenup(image menu[],char anim[])
{
int i;
for (i=0; i<6; i++)
{
sprintf(anim,"options%d.jpg",i);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}
 void liberer_animation(image menu[])
{
int i;
for (i=0; i<6; i++)
{
 SDL_FreeSurface(menu[i].img);			
}

}
  void afficher(image p ,SDL_Surface *ecran)
 {	
 	SDL_BlitSurface(p.img,NULL,ecran,&p.pos);
 }
 void afficher_animation(image menu[],SDL_Surface *screen,int i)
{
SDL_BlitSurface(menu[i].img,NULL,screen,&menu[i].pos);
	SDL_Delay(80);
}
 void afficher_animationt(image menu[],SDL_Surface *screen,int i)
{
SDL_BlitSurface(menu[i].img,NULL,screen,&menu[i].pos);
	SDL_Delay(190);
}


 void init_single(image *single)
 {	
 	single->img=IMG_Load("single0.png");
 	single->pos.x=500;
 	single->pos.y=300;
 }
 void init_single1(image *single1)
 {	
 	single1->img=IMG_Load("single1.png");
 	single1->pos.x=500;
 	single1->pos.y=300;
 }
 
 void init_multi(image *multi)
 {	
 	multi->img=IMG_Load("multi0.png");
 	multi->pos.x=500;
 	multi->pos.y=450;
 }
 void init_multi1(image *multi1)
 {	
 	multi1->img=IMG_Load("multi1.png");
 	multi1->pos.x=500;
 	multi1->pos.y=450;
 }
 
 
 
 void init_backk(image *back)
 {	
 	back->img=IMG_Load("back0.png");
 	back->pos.x=50;
 	back->pos.y=680;
 }
  void init_back1(image *back1)
 {	
 	back1->img=IMG_Load("back1.png");
 	back1->pos.x=50;
 	back1->pos.y=680;
 }
 
   void init_title(image *title)
 {	
 	title->img=IMG_Load("title.png");
 	title->pos.x=480;
 	title->pos.y=50;
 }
 
  void init_sound(image *sound1)
 {	
 	sound1->img=IMG_Load("sound.png");
 	sound1->pos.x=566;
 	sound1->pos.y=162;
 }
 void init_sfx(image *sfx)
 {	
 	sfx->img=IMG_Load("sfx.png");
 	sfx->pos.x=565;
 	sfx->pos.y=346;
 }
 
 void init_bare1(image bare1[],char barr[])
{
int i;
for (i=0; i<5; i++)
{
sprintf(barr,"sound%d.png",i);
bare1[i].img=IMG_Load(barr);  
bare1[i].pos.x=455;
bare1[i].pos.y=233;			
}
}
 void init_bare2(image bare2[],char barr[])
{
int i;
for (i=0; i<5; i++)
{
sprintf(barr,"sfx%d.png",i);
bare2[i].img=IMG_Load(barr);  
bare2[i].pos.x=455;
bare2[i].pos.y=405;			
}
}
 void init_full(image *full)
 {	
 	full->img=IMG_Load("fullscreen.png");
 	full->pos.x=475;
 	full->pos.y=530;
 }
 
  void init_full1(image *full)
 {	
 	full->img=IMG_Load("fullno.png");
 	full->pos.x=565;
 	full->pos.y=590;
 }
   void init_full2(image *full)
 {	
 	full->img=IMG_Load("fullyes.png");
 	full->pos.x=565;
 	full->pos.y=590;
 }
 
 void init_pl(image *pl)
 {	
 	pl->img=IMG_Load("soundplus.png");
 	pl->pos.x=770;
 	pl->pos.y=181;
 }
  void init_pl1(image *pl)
 {	
 	pl->img=IMG_Load("soundplusred.png");
 	pl->pos.x=770;
 	pl->pos.y=181;
 }
  void init_m(image *pl)
 {	
 	pl->img=IMG_Load("soundmoin.png");
 	pl->pos.x=475;
 	pl->pos.y=196;
 }
  void init_m1(image *pl)
 {	
 	pl->img=IMG_Load("soundmoinred.png");
 	pl->pos.x=475;
 	pl->pos.y=196;
 }
 
 void init_plus(image *pl)
 {	
 	pl->img=IMG_Load("sfxplus.png");
 	pl->pos.x=770;
 	pl->pos.y=356;
 }
  void init_plus1(image *pl)
 {	
 	pl->img=IMG_Load("sfxplusred.png");
 	pl->pos.x=770;
 	pl->pos.y=356;
 }
  void init_moin(image *pl)
 {	
 	pl->img=IMG_Load("sfxmoin.png");
 	pl->pos.x=475;
 	pl->pos.y=373;
 }
  void init_moin1(image *pl)
 {	
 	pl->img=IMG_Load("sfxmoinred.png");
 	pl->pos.x=475;
 	pl->pos.y=373;
 }
