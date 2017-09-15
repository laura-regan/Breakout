#ifndef DOT_H
#define DOT_H

#include <SDL.h>

#include "constants.h"
#include "Brick.h"
#include "LTexture.h"

class Dot
{
public:

	static const int DOT_WIDTH = Brick::BRICK_WIDTH * 0.15;
	static const int DOT_VEL = 8;

	Dot();

	void move();

	void dotReset();

	void render();

private:

	int posX_;
	int posY_;

	int velX_;
	int velY_;

	SDL_Rect collider_;
};

#endif
