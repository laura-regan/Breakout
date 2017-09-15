#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL.h>

bool init();
bool loadMedia();
void close();

bool checkCollision( SDL_Rect a, SDL_Rect b );


#endif

