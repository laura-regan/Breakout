#ifndef MENU_H
#define MENU_H

#include <SDL.h>

#include <vector>

#include "constants.h"
#include "LTexture.h"

class Menu
{
public:

	static const int NUM_BUTTONS = 6;

	Menu();

	bool loadMedia();

	void render();

	void free();
	
	// Button dimensions
	static const int BUTTON_WIDTH = SCREEN_WIDTH / 4;
	static const int BUTTON_HEIGHT = BUTTON_WIDTH / 5;
	static const int BUTTON_VERTICAL_SEPARATION = BUTTON_HEIGHT * 0.3;

	std::vector<LTexture> buttonTextures;
	std::vector<SDL_Rect> buttonRenderQuads;

	// Background dimensions
	static const int BACKGROUND_WIDTH = BUTTON_WIDTH * 1.3;
	static const int BACKGROUND_HEIGHT = BUTTON_HEIGHT * NUM_BUTTONS + BUTTON_VERTICAL_SEPARATION * ( NUM_BUTTONS + 4 );

	LTexture menuBackground;
	
	SDL_Rect menuBackgroundRenderQuad;

	
};

#endif
