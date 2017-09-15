#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include <SDL_ttf.h>

#include <vector>

#include "Wall.h"
#include "Paddle.h"
#include "Dot.h"
#include "LTexture.h"
#include "Menu.h"
#include "StartMenu.h"
#include "Player.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

// Textures 
extern std::vector<LTexture> gBrickTextures;
extern LTexture gPaddle;
extern LTexture gDot;

// Objects: Wall, paddle & dot
extern Wall wall;
extern Paddle paddle;
extern Dot dot;

// Declaring manu
extern Menu gMenu;
extern StartMenu gStartMenu;


extern Player player1;

// Font for use in timer
extern TTF_Font* gFont;

#endif
