/**
* @file Background.c
* @brief background program
* @author C team
* @version 0.1
* @date April 17,2022
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "integration.h"

/**
*@brief initialisation du background
*@param B is the struct background
*@return nothing
*/

void initBackground(Background *B)
{
	
	B->PositionBg.x=0;
	B->PositionBg.y=0;
	B->positionMasque.x=0;
	B->positionMasque.y=0;
	
	B->camera.x=0;
	B->camera.y=200;
	B->camera.w = 1280;
	B->camera.h = 800;
	
	int i;
	char ch[20]; /*!< initialiser le tableau d'animation */
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
	B->music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(B->music, -1);
	Mix_AllocateChannels(10);
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

/**
*@brief animation du background
*@param B est la structure background
*@param screen est l'ecran 
*@return nothing
*/
void animation(Background *B, SDL_Surface * screen) 
{
	B->anim++;
	if(B->anim==10) /*!< limite du tableau d'animation */
	{
		B->anim=1;
	}
}

/**
*@brief affichage du background animé sur le masque
*@param B est la structure background
*@param screen est l'ecran 
*@return nothing
*/
void afficherBack (Background B,SDL_Surface *screen)
{
	SDL_BlitSurface(B.Masque,&(B.camera),screen,&(B.positionMasque));
	SDL_BlitSurface(B.BgImg,&(B.camera),screen,&(B.PositionBg));
	SDL_BlitSurface(B.anima[B.anim],&B.camera,screen,&(B.PositionBg));
}

/**
*@brief introduire l'input 
*@param in est la structure input
*@param run est l'entier du boucle du jeu
*@return nothing
*/
void getinput_bg(input *in, int run)
{
	run =1;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{	case SDL_QUIT:
		run =0;
                exit(0);
           	 break;
		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE: 
			run =0;
                       exit(0);
                    	break;
                    	/*case SDLK_UP:
			in->up=1;
			break;
			case SDLK_DOWN:
			in->down=1;
			break;*/
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
			/*case SDLK_UP:
			in->up=0;
			break;
			case SDLK_DOWN:
			in->down=0;
			break;*/
			case SDLK_RIGHT:
			in->right=0;
			break;
			default:
			break;						
		}
		break;
	}
}

/**
*@brief scrolling de l'ecran
*@param B est la structure background
*@param p est la structure personnage
*@param in est la structure input
*@return nothing
*/
void scrolling(Background *B, input *in)
{
	if(in->right==1)
	{
		B->camera.x+=8;
		if(B->camera.x >=B->BgImg->w) /*!< limite du background */
		{
			B->camera.x=B->BgImg->w;
		}
	}
	else if(in->left==1)
	{
		B->camera.x-=8;
		if (B->camera.x<= 0) /*!< limite du background */
		{
			B->camera.x=0;
		}
	}
	if(in->up==1)
	{	B->camera.y-=5;
		if (B-> camera.y <= 0) /*!< limite du background */
		{
			B->camera.y=0;
		}
	}
	else if(in->down==1)
	{
		B->camera.y+=5;
		if (B-> camera.y >= 200) /*!< limite du background */
		{
			B->camera.y=200;
		}
	}
}


/**
*@brief detecter le couleur du pixel
*@param B est le rectangle du background
*@param x est la position horizontale
*@param y est la position verticale 
*@return color of pixel
*/
SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

SDL_Color color;
	Uint32 col = 0; /*!< Determine position */

	char *pixelPosition = (char *)Background->pixels; /*!<Offset by Y*/
	pixelPosition += (Background->pitch * y); /*!<Offset by X*/
	pixelPosition += (Background->format->BytesPerPixel * x); /*!<Copy pixel data*/
	memcpy(&col, pixelPosition, Background->format->BytesPerPixel); /*!<Convert to color*/
	SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

	return (color);
}

/**
*@brief detecter la collision
*@param p est la structure du personnage
*@param Masque est le rectangle du masque 
*@return 1 si il detecte si non 0
*/
int collisionPP(perso p, SDL_Surface *Masque)
{
	SDL_Color test ;
	SDL_Rect pos[8]; /*!< positions du personnage qu'il va tester*/
	    
	pos[0].x = p.pos.x;
	pos[0].y = p.pos.y;
	pos[1].x = p.pos.x + p.pos.w / 2;
	pos[1].y = p.pos.y;
	pos[2].x = p.pos.x + p.pos.w;
	pos[2].y = p.pos.y;
	pos[3].x = p.pos.x;
	pos[3].y = p.pos.y + p.pos.h / 2;
	pos[4].x = p.pos.x;
	pos[4].y = p.pos.y + p.pos.h;
	pos[5].x = p.pos.x + p.pos.w / 2;
	pos[5].y = p.pos.y + p.pos.h;
	pos[6].x = p.pos.x + p.pos.w;
	pos[6].y = p.pos.y + p.pos.h;
	pos[7].x = p.pos.x + p.pos.w;
	pos[7].y = p.pos.y + p.pos.h / 2;
	    
	int collision = 0, x, y,i;

	for (i=0; i<8 && collision ==0; i++)
	{
		x = pos[i].x;
		y = pos[i].y;
			
		test = GetPixel(Masque, x, y);
			
		if (test.r == 255 && test.g == 255 && test.b == 255) /*!< detecte le couleur blanc du masque*/
		collision = 1;
	}
	return collision;
}

/**
*@brief liberation des elements
*@param B est la structure background
*@return nothing
*/
void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
	SDL_FreeSurface(B->Masque);
	SDL_FreeSurface(B->anima[50]);
	Mix_FreeMusic (B->music);
}
