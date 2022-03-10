#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include"init.h"
#include "text.h"
#include <SDL/SDL_ttf.h>

int main(int argc, char **argv[])
{	
	image backg[50],backg2,backg3,backg4,start,setting,credit,exit,multi,single;
	image start1,setting1,credit1,exit1,single1,multi1;
	SDL_Event event;
	int done=1,i=1,x,y,a=1,tap=0,curseur=0,cursor=0, ev=0,n=0;
	Text text;	
	char anim[50];
	Mix_Chunk *clickmusic;
	SDL_Surface *screen=NULL;
	
	
	screen=SDL_SetVideoMode(1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	if(screen==NULL)
	{
	printf("unable to upload img %s",SDL_GetError());
	}
	
	initmenu(backg,anim);
	
	initText(&text);
	
	//init_options(&backg3);
	init_start1(&start);
	init_setting1(&setting);
	init_credit1(&credit);
	init_exit1(&exit);
	init_start2(&start1);
	init_setting2(&setting1);
	init_credit2(&credit1);
	init_exit2(&exit1);

		



	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	    {
	    printf("%s",Mix_GetError());
	    }
	    
	    Mix_Music *music;
	    music = Mix_LoadMUS("sound.mp3");	   
	    Mix_PlayMusic(music,-1);
	    clickmusic=Mix_LoadWAV("son.wav");

	
while(done)
{
		if (n==6)
		{
		n=1;
		}
		afficher_animation(backg,screen,n);
		n++;	
		
		afficher(start,screen);
		afficher(setting,screen);
		afficher(credit,screen);
		afficher(exit,screen);
		afficher_Text(text,screen);
		SDL_Delay(50);
		
		

		
	switch (cursor)
	{
	case 1:
	if(a==1)
	{
	Mix_PlayChannel(-1,clickmusic,0);
	}
	a=0;
	afficher(start1,screen);
	break;
	case 2:
	if(a==1)
	Mix_PlayChannel(-1,clickmusic,0);
	a=0;
	afficher(setting1,screen);
	break;
	case 3:
	if(a==1)
	Mix_PlayChannel(-1,clickmusic,0);
	a=0;
	afficher(credit1,screen);
	break;
	case 4:
	if(a==1)
	Mix_PlayChannel(-1,clickmusic,0);
	a=0;
	afficher(exit1,screen);
	break;
	}
	
while(SDL_PollEvent(&event))
{
switch(event.type)
{
	
case SDL_KEYDOWN: 
                                                    
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
    done=0;
    	break;
    	case SDLK_f:
    	SDL_GetVideoSurface();
    	break;
case SDLK_UP:
	if (i==1)
		{i=4;}
	else
	        {i--;
	        Mix_PlayChannel(1,clickmusic,0);}
break;
case SDLK_DOWN:
	if(i==4)
              	{i=1;}
	else
               { i++;
                Mix_PlayChannel(1,clickmusic,0);}
break;
case SDLK_RETURN:
if(i==1)
{
startt(screen);
Mix_PlayChannel(1,clickmusic,0);
}
else if (i==2)
{
optionn(screen);
Mix_PlayChannel(1,clickmusic,0);
}
else if(i==3)
{
creditt(screen);
Mix_PlayChannel(1,clickmusic,0);
}
else
{
done=0;
}
break;
}



   	
                           	case SDL_MOUSEMOTION:


				if((event.motion.x>102) && (event.motion.x<355) && (event.motion.y>211) && (event.motion.y<289))
						{
						curseur=1;
						cursor=1;
						i=0;
						Mix_PlayChannel(1,clickmusic,0);
						}

				else if((event.motion.x>102) && (event.motion.x<355) && (event.motion.y>311) && (event.motion.y<389))
						{
						curseur=2;
						cursor=2;
						i=0;
						Mix_PlayChannel(1,clickmusic,0);
						}

				else if ((event.motion.x>102) && (event.motion.x<355) && (event.motion.y>314) && (event.motion.y<489))
						{
						curseur=3;
						cursor=3;
						i=0;
						Mix_PlayChannel(1,clickmusic,0);
						}
						
				else if ((event.motion.x>102) && (event.motion.x<355) && (event.motion.y>427) && (event.motion.y<589))
						{
						curseur=4;
						cursor=4;
						i=0;
						Mix_PlayChannel(1,clickmusic,0);
						}
						else 
						{						
						curseur=0;
						cursor=0;
						}
						break;SDL_Flip(screen);
				case SDL_QUIT:
					done=0;
					break;		
            			
            	
				case SDL_MOUSEBUTTONDOWN:
        	if (event.button.button == SDL_BUTTON_LEFT)
        	{
switch(curseur)
{
case 1:
ev=1;
break;
case 2:
ev=2;
//afficher(backg3,screen);
break;
case 3:
ev=3;
break;
case 4:
ev=4;
break;
}
switch(ev)
	{	case 1:
		startt(screen);
		break;
		case 2:
		optionn(screen);
		break;
		case 3:
		creditt(screen);
		break;
		case 4:
		done=0;
		break;
		}
}

}

}
 if (i==1)
{

afficher(start1,screen);
Mix_PlayChannel(1,clickmusic,0);
}
if (i==2)
{

afficher(setting1,screen);
Mix_PlayChannel(1,clickmusic,0);
}
if  (i==3)
{

afficher(credit1,screen);
Mix_PlayChannel(1,clickmusic,0);
}
if(i==4)
{
afficher(exit1,screen);
Mix_PlayChannel(1,clickmusic,0);
}

SDL_Flip(screen);
}
liberer_animation(backg);
//liberer(&backg3);
liberer(&start);
liberer(&start1);
liberer(&setting);
liberer(&credit);
liberer(&exit);

Mix_FreeMusic(music);
SDL_FreeSurface(screen) ;

//SDL_FreeSurface(text.surfaceTexte);
TTF_CloseFont(text.font);
TTF_Quit();

}
