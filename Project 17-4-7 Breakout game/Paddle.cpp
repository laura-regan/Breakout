#include "Paddle.h"

#include "constants.h"
#include "globals.h"

Paddle::Paddle()
{
	paddleWidth_ = SCREEN_WIDTH / 6;
	paddleHeight_ = paddleWidth_ * 130 / 300 * 0.7;

	posX_ = (SCREEN_WIDTH - paddleWidth_) / 2;
	posY_ = SCREEN_HEIGHT - paddleHeight_ * 1.5;

	velX_ = 0;
	//velY_ = 0;

	collider_ = { posX_, posY_, paddleWidth_, paddleHeight_ };
}


void Paddle::handleEvent( SDL_Event e )
{
	if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_RIGHT:
				velX_ += PADDLE_VEL;
				break;
			case SDLK_LEFT:
				velX_ -= PADDLE_VEL;
				break;
		}
	}
	else if ( e.type == SDL_KEYUP && e.key.repeat == 0 )
	{
		switch ( e.key.keysym.sym )
		{
			case SDLK_RIGHT:
				velX_ -= PADDLE_VEL;
				break;
			case SDLK_LEFT:
				velX_ += PADDLE_VEL;
				break;
		}
	}
}


void Paddle::move()
{

	posX_ += velX_;
	collider_.x = posX_;

	if ( posX_ < 0 )
	{
		posX_ = 0;
		collider_.x = posX_;
	}
	if ( posX_ > ( SCREEN_WIDTH - paddleWidth_ ) )
	{
		posX_ = SCREEN_WIDTH - paddleWidth_;
		collider_.x = posX_;
	}
	

	/*...Y position...*/

}


void Paddle::render()
{
	SDL_RenderCopy( gRenderer, gPaddle.getTexture(), NULL, &collider_ );
}


SDL_Rect Paddle::getCollider()
{
	return collider_;
}


int Paddle::getWidth()
{
	return paddleWidth_;
}