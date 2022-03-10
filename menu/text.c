#include "text.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void initText(Text *A)
{		

    A->position.x=230;
    A->position.y=713;
    
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont("arial",70);
    //TTF_CloseFont(A->font);
}


void afficher_Text(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "© Version 1.0 | All rights reserved", t.textColor);
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}
