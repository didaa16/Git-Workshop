#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

struct image
{
SDL_Rect pos;
SDL_Surface *img;
};
typedef struct image image;

void initmenu(image menu[],char anim[]);
void initmenus(image menu[],char anim[]);
void initmenup(image menu[],char anim[]);
void initmenuc(image menu[],char anim[]);
void init_options(image *background);
void initbutton(image menu[],char anim[]);
void init_start1(image *start1);
void init_start2(image *start2);
void init_setting1(image *setting1);
void init_setting2(image *setting2);
void init_credit1(image *credit1);
void init_credit2(image *credit2);
void init_exit1(image *exit1);
void init_exit2(image *exit2);
void init_single(image *single);
void init_single1(image *single1);
void init_multi(image *multi);
void init_multi1(image *multi1);
void init_backk(image *back);
void init_back1(image *back1);
void init_bare1(image bare1[],char barr[]);
void init_bare2(image bare2[],char barr[]);
void init_sfx(image *sfx);
void init_sound(image *sound1);
void init_title(image *title);
void init_full(image *full);
void init_full1(image *full);
void init_full2(image *full);
void init_pl(image *pl);
void init_pl1(image *pl);
void init_m(image *pl);
void init_m1(image *pl);
void init_plus(image *pl);
void init_plus1(image *pl);
void init_moin(image *pl);
void init_moin1(image *pl);

 
