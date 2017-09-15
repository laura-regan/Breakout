#include "globals.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

std::vector<LTexture> gBrickTextures;

LTexture gPaddle;
LTexture gDot;

Wall wall;
Paddle paddle;
Dot dot;
Menu gMenu;
StartMenu gStartMenu;

Player player1;

TTF_Font* gFont = NULL;