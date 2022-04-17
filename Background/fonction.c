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
	B->Masque=IMG_Load ("Mask1.jpg");
	if (B->Masque == NULL)
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
void initperso (Personne *p)
{
	p->sprite=IMG_Load ("perso.png");
	p->positionperso.x=0;
	p->positionperso.y=600;
}
void afficherBack (Background B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.BgImg,&(B.camera),screen,&(B.PositionBg));
}

void affichermask (Background B, SDL_Surface *screen)
{
	SDL_BlitSurface(B.Masque,&(B.camera),screen,&(B.positionMasque));
}

void afficherperso (Personne p , SDL_Surface *screen)
{
	SDL_BlitSurface(p.sprite,NULL,screen,&(p.positionperso));
}
void getinput(input *in)
{
	SDL_Event event;
	SDL_PollEvent(&event);
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

void scrolling(Personne *map ,Background *B, input *in)
{
	if(in->right==1)
	{
		B->camera.x+=5;
		map->positionperso.x+=3;
		if(B->camera.x >=12800-1280)
		{
			B->camera.x=0;
			
		}
	}
	else if(in->left==1)
	{
		B->camera.x-=5;
		map->positionperso.x-=3;
		if (B->camera.x<= 0)
		{
			B->camera.x=0;
		}
	}
	if(in->up==1)
	{	B->camera.y-=5;
		map->positionperso.y-=5;
		if (B-> camera.y <= 0)
		{
			B->camera.y=0;
		}
	}
	else if(in->down==1)
	{
		B->camera.y+=5;
		map->positionperso.y+=5;
		if (B-> camera.y >= 200)
		{
			B->camera.y=200;
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

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position

    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}


int collisionPP(Personne p, SDL_Surface *Masque)
{
    SDL_Color test, couleurnoir = {255, 0, 0};

    SDL_Rect pos[8];
    
    pos[0].x = p.positionperso.x;
    pos[0].y = p.positionperso.y;
    pos[1].x = p.positionperso.x + p.positionperso.w / 2;
    pos[1].y = p.positionperso.y;
    pos[2].x = p.positionperso.x + p.positionperso.w;
    pos[2].y = p.positionperso.y;
    pos[3].x = p.positionperso.x;
    pos[3].y = p.positionperso.y + p.positionperso.h / 2;
    pos[4].x = p.positionperso.x;
    pos[4].y = p.positionperso.y + p.positionperso.h;
    pos[5].x = p.positionperso.x + p.positionperso.w / 2;
    pos[5].y = p.positionperso.y + p.positionperso.h;
    pos[6].x = p.positionperso.x + p.positionperso.w;
    pos[6].y = p.positionperso.y + p.positionperso.h;
    pos[7].x = p.positionperso.x + p.positionperso.w;
    pos[7].y = p.positionperso.y + p.positionperso.h / 2;
    
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        
        test = GetPixel(Masque, x, y);
        
        if (test.r == 255 && test.g == 255 && test.b == 255)
            collision = 1;
    }
    return collision;
}

void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	SDL_FreeSurface(B->Masque);
	SDL_FreeSurface(B->anima[50]);
}
