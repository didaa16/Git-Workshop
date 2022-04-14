#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include"init.h"

  void init_start1(image *start1)
 {	
 	start1->img=IMG_Load("bouton/start1.png");
 	start1->pos.x=230;
 	start1->pos.y=211;
 }
 
  void init_start2(image *start2)
 {	
 	start2->img=IMG_Load("bouton/start2.png");
 	start2->pos.x=230;
 	start2->pos.y=211;
 }
  void init_setting1(image *setting1)
 {	
 	setting1->img=IMG_Load("bouton/setting1.png");
 	setting1->pos.x=230;
 	setting1->pos.y=311;
 }
  void init_setting2(image *setting2)
 {	
 	setting2->img=IMG_Load("bouton/setting2.png");
 	setting2->pos.x=230;
 	setting2->pos.y=311;
 }
  void init_credit1(image *credit1)
 {	
 	credit1->img=IMG_Load("bouton/credit1.png");
 	credit1->pos.x=230;
 	credit1->pos.y=411;
 }
  void init_credit2(image *credit2)
 {	
 	credit2->img=IMG_Load("bouton/credit2.png");
 	credit2->pos.x=230;
 	credit2->pos.y=411;
 }
  void init_exit1(image *exit1)
 {	
 	exit1->img=IMG_Load("bouton/exxit1.png");
 	exit1->pos.x=230;
 	exit1->pos.y=511;
 }
 void init_exit2(image *exit2)
 {	
 	exit2->img=IMG_Load("bouton/exit2.png");
 	exit2->pos.x=230;
 	exit2->pos.y=511;
 }

 void initmenu(image menu[],char anim[])
{
int i;
for (i=1; i<6; i++)
{
sprintf(anim,"anim-backg/backg%d.jpg",i);
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
sprintf(anim,"anim-start/start%d.jpg",i+1);
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
sprintf(anim,"anim-text/%d.png",i);
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
sprintf(anim,"anim-credit/%d.jpg",i+2);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}
void initmenup(image menu[],char anim[])
{
int i;
for (i=0; i<4; i++)
{
sprintf(anim,"anim-option/options%d.jpg",i);
menu[i].img=IMG_Load(anim);  
menu[i].pos.x=0;
menu[i].pos.y=0;			
}
}


 void init_single(image *single)
 {	
 	single->img=IMG_Load("bouton/single0.png");
 	single->pos.x=500;
 	single->pos.y=300;
 }
 void init_single1(image *single1)
 {	
 	single1->img=IMG_Load("bouton/single1.png");
 	single1->pos.x=500;
 	single1->pos.y=300;
 }
 
 void init_multi(image *multi)
 {	
 	multi->img=IMG_Load("bouton/multi0.png");
 	multi->pos.x=500;
 	multi->pos.y=450;
 }
 void init_multi1(image *multi1)
 {	
 	multi1->img=IMG_Load("bouton/multi1.png");
 	multi1->pos.x=500;
 	multi1->pos.y=450;
 }
 
 
 
 void init_backk(image *back)
 {	
 	back->img=IMG_Load("bouton/back0.png");
 	back->pos.x=50;
 	back->pos.y=680;
 }
  void init_back1(image *back1)
 {	
 	back1->img=IMG_Load("bouton/back1.png");
 	back1->pos.x=50;
 	back1->pos.y=680;
 }
 
   void init_title(image *title)
 {	
 	title->img=IMG_Load("bouton/title.png");
 	title->pos.x=480;
 	title->pos.y=50;
 }
 
  void init_sound(image *sound1)
 {	
 	sound1->img=IMG_Load("bouton/sound.png");
 	sound1->pos.x=566;
 	sound1->pos.y=162;
 }
 void init_sfx(image *sfx)
 {	
 	sfx->img=IMG_Load("bouton/sfx.png");
 	sfx->pos.x=565;
 	sfx->pos.y=346;
 }
 
 void init_bare1(image bare1[],char barr[])
{
int i;
for (i=0; i<5; i++)
{
sprintf(barr,"sound/sound%d.png",i);
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
sprintf(barr,"sfx/sfx%d.png",i);
bare2[i].img=IMG_Load(barr);  
bare2[i].pos.x=455;
bare2[i].pos.y=405;			
}
}
 void init_full(image *full)
 {	
 	full->img=IMG_Load("bouton/fullscreen.png");
 	full->pos.x=475;
 	full->pos.y=530;
 }
 
  void init_full1(image *full)
 {	
 	full->img=IMG_Load("bouton/fullno.png");
 	full->pos.x=565;
 	full->pos.y=590;
 }
   void init_full2(image *full)
 {	
 	full->img=IMG_Load("bouton/fullyes.png");
 	full->pos.x=565;
 	full->pos.y=590;
 }
 
 void init_pl(image *pl)
 {	
 	pl->img=IMG_Load("bouton/soundplus.png");
 	pl->pos.x=770;
 	pl->pos.y=181;
 }
  void init_pl1(image *pl)
 {	
 	pl->img=IMG_Load("bouton/soundplusred.png");
 	pl->pos.x=770;
 	pl->pos.y=181;
 }
  void init_m(image *pl)
 {	
 	pl->img=IMG_Load("bouton/soundmoin.png");
 	pl->pos.x=475;
 	pl->pos.y=196;
 }
  void init_m1(image *pl)
 {	
 	pl->img=IMG_Load("bouton/soundmoinred.png");
 	pl->pos.x=475;
 	pl->pos.y=196;
 }
 
 
 void init_plus(image *pl)
 {	
 	pl->img=IMG_Load("bouton/sfxplus.png");
 	pl->pos.x=770;
 	pl->pos.y=356;
 }
  void init_plus1(image *pl)
 {	
 	pl->img=IMG_Load("bouton/sfxplusred.png");
 	pl->pos.x=770;
 	pl->pos.y=356;
 }
  void init_moin(image *pl)
 {	
 	pl->img=IMG_Load("bouton/sfxmoin.png");
 	pl->pos.x=475;
 	pl->pos.y=373;
 }
  void init_moin1(image *pl)
 {	
 	pl->img=IMG_Load("bouton/sfxmoinred.png");
 	pl->pos.x=475;
 	pl->pos.y=373;
 }
