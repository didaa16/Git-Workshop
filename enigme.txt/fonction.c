#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

//INIT MUSIC
void initmusic()
{
Mix_Music *music;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)

	{printf("NO AUDIO %s\n",Mix_GetError());}

music = Mix_LoadMUS("resource/menu son.mp3"); //load the music 

Mix_PlayMusic(music,-1); //play music 
}
void init_animation(enigme *e)
{
	int i;
	char num[43];
	for(i=0;i<25;i++)
	{
		sprintf(num,"RES/Animationgameover/%d.png",i);
		e->anim[i] = IMG_Load(filename);
	}
	e->anim_Pos.x=600;
	e->anim_Pos.y=400;
    	e->anim_Pos.w=440;
    	e->anim_Pos.h=100;
}
void generer (enigme *e)
{
	char qst[40];
  //charger la question
          int question,i=1; // nombre de la question a afficher
 
        srand(time(NULL));
        question=(rand()%4)+1; //changer 3 avec le numbero des questions
 

 	e->choix=0;

        (*e).police=TTF_OpenFont("Roman.ttf",30);
	(*e).color.r=255;
	(*e).color.g=255;
	(*e).color.b=255;

         FILE* qt=fopen("resource/question.txt","r");
         if (qt==NULL)
         {
             printf("\n ERREUR FICHIER");
         }
         else
         {
          i=1;
        while((fgets(qst,60,qt)!=NULL)&&(question!=i))
         {
 
 
             i++;
         }
         }
        fclose(qt);
  //charger les reponses
         FILE* rp=fopen("resource/rep.txt","r");
         if (rp==NULL)
         {
             printf("\n ERREUR FICHIER");
         }
         else
         {
         i=1;
 
          while((fscanf(rp,"%s %s %s",e->rep1,e->rep2,e->rep3)!=EOF)&&(question!=i))
         {
             i++;
         }
         }
         fclose(rp);

  //charger solution
         FILE* sol=fopen("resource/sol.txt","r");
         if (sol==NULL)
         {
             printf("\n ERREUR FICHIER");
         }
         else
         {
         i=1;
 
          while((fscanf(sol,"%d \n",&e->sol)!=EOF)&&(question!=i))
         {
             i++;
         }
         }
         fclose(sol);
         //SDL SURFACE
 
    // question
   
 
 
	(*e).posQ.x=0;
	(*e).posQ.y=0;
 
	//rep1
    
 
	(*e).posR1.x=0;
	(*e).posR1.y=250;

    	//rep2
   
 
	(*e).posR2.x=250;
	(*e).posR2.y=250;
 
       //rep3
    
 
	(*e).posR3.x=500;
	(*e).posR3.y=250;

	e->q= TTF_RenderText_Blended(e->police,qst,e->color);
	e->r1= TTF_RenderText_Blended(e->police,e->rep1,e->color);
  	e->r2= TTF_RenderText_Blended(e->police,e->rep2,e->color);
   	e->r3= TTF_RenderText_Blended(e->police,e->rep3,e->color);

(*e).image=IMG_Load("background.png");
	//position de l'image
	(*e).pos_image.x=0;
    	(*e).pos_image.y=0;

	e->resolu=0;

}
	      
void afficherEnigme(enigme *e, SDL_Surface * screen)
{
    
    SDL_BlitSurface(e->image,NULL,screen,&e->pos_image);
    SDL_BlitSurface(e->q,NULL,screen,&e->posQ);
    SDL_BlitSurface(e->r1,NULL,screen,&e->posR1);
    SDL_BlitSurface(e->r2,NULL,screen,&e->posR2);
    SDL_BlitSurface(e->r3,NULL,screen,&e->posR3);
	if(e->resolu=2)
		{/*affichege animation*/}
}
int get_input_rep(int *state,SDL_Event event,enigme *e)
{
int x,y;
	if(SDL_PollEvent(&event))
		{switch(event.type)
		{
			case SDL_QUIT:
            			*state=0;
           		 break;	
			case SDL_KEYDOWN:
		if(e->choix==0)//il peut repondre qu'une seul foi
		{
		switch (event.key.keysym.sym)
              {case SDLK_a: 
          	{e->choix=1;}
           	break;
		case SDLK_b: 
          	{e->choix=2;}
           	break;
		case SDLK_c: 
          	{e->choix=3;}
           	break;}

}
}
}
return e->choix;
}
void resolution(enigme *e, SDL_Surface *screen,int input)
{
//input = 0;
int Vol;
if(input != 0)
{
	if ( e->sol == input )
         {
       		
        	printf("\n FOUND \n");
		(*e).color.r=0;
		(*e).color.g=255;
		(*e).color.b=0;
            	e->resolu=1;
         }
        else 
         {
		printf("\n WRONG \n");
		(*e).color.r=255;
		(*e).color.g=0;
		(*e).color.b=0;
		e->resolu=2;
	 }
	if(input==1)
		e->r1= TTF_RenderText_Blended(e->police,e->rep1,e->color);
	if(input==2)
		e->r2= TTF_RenderText_Blended(e->police,e->rep2,e->color);
	if(input==3)
		e->r3= TTF_RenderText_Blended(e->police,e->rep3,e->color);
	
}
}
void free_enig( enigme *e )
{
    SDL_FreeSurface(e->image);
    SDL_FreeSurface(e->r1);
    SDL_FreeSurface(e->r2);
    SDL_FreeSurface(e->r3);
    SDL_FreeSurface(e->q);
    TTF_CloseFont(e->police);
    for(i=0;i<15;i++)
	{
		SDL_FreeSurface(en->anim[i]);
	}
}
