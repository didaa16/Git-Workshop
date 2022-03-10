#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

void initBack(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void animerBackground( Background * e);
int collisionPP( Personne p, SDL_Surface * Masque);
void scrolling (background * b, int direction, int pasAvancement);

#endif //BACKGROUND_H_INCLUDED
