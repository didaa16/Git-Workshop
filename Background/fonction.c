#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

void initBackground(Background *B)
{
	
	B->PositionBg.x=0;
	B->PositionBg.y=0;

	B->positionperso.x=0;
	B->positionperso.y=600;
	
	//B->positionMask.x=0;
	//B->positionMask.y=0;
	
	B->camera.x=0;
	B->camera.y=200;
	B->camera.w = 1280;
	B->camera.h = 800;
	
	int i;
	char ch[20];
	for(i=1;i<10;i++)
	{
		sprintf(ch,"Back%d.jpg",i);
		B->anima[i] = IMG_Load(ch);
	}
	B->BgImg= IMG_Load("Backg1.jpg");
	if (B->BgImg == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
	}
	B->PersoImg=IMG_Load("perso.png");
	if (B->PersoImg == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
	}

	if(SDL_Init(SDL_INIT_AUDIO)==-1)
	{
		printf("SDL_Init: %s\n", SDL_GetError());
	}
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}
	Mix_Music *music;
	music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(music, -1);
	Mix_AllocateChannels(10);
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficherBack (Background B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.BgImg,&(B.camera),screen,&(B.PositionBg));
}

void afficherperso (Background B , SDL_Surface *screen)
{
	SDL_BlitSurface(B.PersoImg,NULL,screen,&(B.positionperso));
}
void getinput(input *in)
{
	SDL_Event event;
	while (SDL_PollEvent(&event));
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
                    	case SDLK_UP:
			in->up=1;
			break;
			case SDLK_DOWN:
			in->down=1;
			break;
			case SDLK_LEFT:
			in->left=1;
			break;
			case SDLK_RIGHT:
			in->right=1;
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
			case SDLK_UP:
			in->up=0;
			break;
			case SDLK_DOWN:
			in->down=0;
			break;
			case SDLK_RIGHT:
			in->right=0;
			break;
			default:
			break;						
		}
		break;
	}
}

void scrolling(Background *map , input *in)
{
	if(in->right==1)
	{
		map->camera.x+=5;
		map->positionperso.x+=5;
		map->positionMask.x = map->camera.x ;
		if(map->camera.x >=12800-1280)
		{
			map->camera.x=0;
			
		}
	}
	else if(in->left==1)
	{
		map->camera.x-=5;
		map->positionperso.x-=5;
		map->positionMask.x = map->camera.x ;
		if (map->camera.x<= 0)
		{
			map->camera.x=0;
		}
	}
	if(in->up==1)
	{	map->camera.y-=5;
		map->positionperso.y-=5;
		map->positionMask.y = map->camera.y ;
		if (map-> camera.y <= 0)
		{
			map->camera.y=0;
		}
	}
	else if(in->down==1)
	{
		
		if (map-> camera.y <= 200)
		{
			map->camera.y+=5;
			map->positionperso.y+=5;
			map->positionMask.y = map->camera.y ;
		}
	}
}

void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==10)
	{
		B->anim=1;
	}
	SDL_BlitSurface(B->anima[B->anim],&B->camera,screen,&(B->PositionBg));
}

void init (Background *B , SDL_Surface * screen)
{
	B->Mask = IMG_Load("Mask1.jpg");
	B->positionMask.x=0;
	B->positionMask.y=0;
}

void affichermask (Background B, SDL_Surface *screen)
{
	SDL_BlitSurface(B.Mask,NULL,screen,&(B.positionMask));
}
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y)
{
	SDL_Color color;
	Uint32 col = 0;
	char *pPosition = (char*) pSurface -> pixels;
	pPosition += (pSurface -> pitch * y);
	pPosition += (pSurface->format->BytesPerPixel * x);
	memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
	SDL_GetRGB (col, pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}

int detectCollPP (Background B, SDL_Rect Personnage)
{
	SDL_Color colobs ={255,255,255} ;
	SDL_Color colgotten;
	positionPers Pos [8];
	int collision = 0, i = 0;
	Pos[0].x = Personnage.x ;
	Pos[0].y = Personnage.y;
	Pos[1].x = Personnage.x + (Personnage.w /2);
	Pos[1].y = Personnage.y;
	Pos[2].x = Personnage.x + Personnage.w;
	Pos[2].y = Personnage.y;
	Pos[3].x = Personnage.x;
	Pos[3].y = Personnage.y + (Personnage.h/2);
	Pos[4].x = Personnage.x;
	Pos[4].y = Personnage.y + Personnage.h;
	Pos[5].x = Personnage.x + (Personnage.w /2);
	Pos[5].y = Personnage.y + Personnage.h;
	Pos[6].x = Personnage.x + Personnage.w;
	Pos[6].y = Personnage.y + Personnage.h;
	Pos[7].x = Personnage.x + Personnage.w;
	Pos[7].y = Personnage.y + (Personnage.h/2);
	colgotten = GetPixel(B.Mask, Pos[i].x, Pos[i].y);
	while ((i<=7) && (collision == 0)) 
	{
		if (colobs.r == colgotten.r && colobs.b == colgotten.b && colobs.g == colgotten.g)
		{
			collision = 1;
		}
		else
		{
			i++;
		}
	}
	return collision;
}


void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	SDL_FreeSurface(B->PersoImg);
	//SDL_FreeSurface(B->Mask);
	SDL_FreeSurface(B->anima[50]);
}
