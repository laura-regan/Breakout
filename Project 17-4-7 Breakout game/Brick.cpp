#include "Brick.h"

#include "globals.h"


Brick::Brick()
{
	posX_ = 0;
	posY_ = 0;

	color_ = 0;

	life_ = 0;

	isVisible_ = true;

	collider_ = { 0, 0, BRICK_WIDTH, BRICK_HEIGHT };
}


void Brick::setBrick( int x, int y, int color )
{
	posX_ = x;
	posY_ = y;

	color_ = color;

	life_ = color;

	isVisible_ = true;

	collider_.x = posX_;
	collider_.y = posY_;
}


void Brick::render()
{
	if ( isVisible_ )
	{
		// Collider rect coincides with texture render quad
		SDL_RenderCopy( gRenderer, gBrickTextures[color_].getTexture(), NULL, &collider_ );
	}
}


SDL_Rect Brick::getCollider()
{
	return collider_;
}


void Brick::update()
{
	color_--;

	life_--;

	if ( life_ < 0 )
	{
		isVisible_ = false;
	}
}


int Brick::getBrickType()
{
	return color_;
}