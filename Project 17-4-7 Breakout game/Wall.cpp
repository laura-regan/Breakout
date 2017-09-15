#include "Wall.h"

#include <vector>

#include "Brick.h"

Wall::Wall()
{
	wall.resize( WALL_HEIGHT, std::vector<Brick>( WALL_WIDTH ) );
}


void Wall::setWall()
{
	for ( int iRow = 0; iRow < WALL_HEIGHT; iRow++ )
	{
		for ( int iColumn = 0; iColumn < WALL_WIDTH; iColumn++ )
		{
			wall[iRow][iColumn].setBrick( borderWidth + iColumn * brickWidth + brickSeparationWidth * iColumn, borderHeight + iRow * brickHeight + brickSeparationHeight * iRow, BRICK_COLOR::PURPLE - iRow );
		}
	}
}


void Wall::renderWall()
{
	for ( int iColumn = 0; iColumn < WALL_WIDTH; iColumn++ )
	{
		for ( int iRow = 0; iRow < WALL_HEIGHT; iRow++ )
		{
			wall[iRow][iColumn].render();
		}
	}
}