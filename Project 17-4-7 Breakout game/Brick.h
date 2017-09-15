#ifndef BRICK_H
#define BRICK_H

#include <SDL.h>

#include "constants.h"

class Brick
{
public:

	// Brick Dimensions
	static const int BRICK_WIDTH = SCREEN_WIDTH / WALL_WIDTH * 0.7;
	static const int BRICK_HEIGHT = BRICK_WIDTH * 130 / 300 ;

	Brick();

	void setBrick(int x, int y, int color);

	void render();

	void update();
	
	int getBrickType();

	SDL_Rect getCollider();

	bool isVisible_;

private:

	int posX_;
	int posY_;

	int color_;

	int life_;

	SDL_Rect collider_;
};


#endif
