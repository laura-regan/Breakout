#ifndef WALL_H
#define WALL_H

#include <vector>

#include "Brick.h"
#include "constants.h"


class Wall
{
public:

	// Dimensions necesasry for placement of grid
	int brickWidth = Brick::BRICK_WIDTH;
	int brickHeight = Brick::BRICK_HEIGHT;
	int brickSeparationWidth = brickWidth * 0.15;
	int brickSeparationHeight = brickWidth * 0.2;
	int borderWidth = ( SCREEN_WIDTH - ( brickWidth + brickSeparationWidth ) * WALL_WIDTH ) / 2;
	int borderHeight = SCREEN_HEIGHT * 0.08;

	//static const int BRICK_SEPARATION_WIDTH = SCREEN_WIDTH / WALL_WIDTH;

	Wall();

	void setWall();

	void renderWall();

	std::vector<std::vector<Brick>> wall;


};
#endif

