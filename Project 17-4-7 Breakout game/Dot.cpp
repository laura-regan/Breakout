#include "Dot.h"

#include <cmath>
#include <ctime>

#include "globals.h"
#include "functions.h"
#include "Paddle.h"
#include "Player.h"



Dot::Dot()
{
	srand( time( NULL ) );

	posX_ = ( SCREEN_WIDTH + DOT_WIDTH ) / 2;
	posY_ = ( SCREEN_HEIGHT + DOT_WIDTH )  / 2;

	float randAng = ( ( rand() % 120 + 30 ) / 180.0 )* PI; // between 30 and 150 deg

	velX_ = cos( randAng ) * DOT_VEL;
	velY_ = sin( randAng ) * DOT_VEL;


	collider_ = { posX_, posY_, DOT_WIDTH, DOT_WIDTH };
}


void Dot::move()
{
	bool collisionFound = false;

	SDL_Rect brickCollider;

	int intX = posX_;
	int intY = posY_;


	posX_ += velX_;
	collider_.x = posX_;

	//----- Wall Collision test -----------//

	if ( posX_ < 0 || posX_ >( SCREEN_WIDTH - DOT_WIDTH ) )	// Check for collisions with left/right walls
	{
		posX_ = intX;
		collider_.x = posX_;

		velX_ *= -1;
		collisionFound = true;
	}
	else
	{
		posY_ += velY_;
		collider_.y = posY_;

		if ( posY_ < 0 )	// Check for collisions with ceiling
		{
			posY_ = intY;
			collider_.y = posY_;

			velY_ *= -1;
			collisionFound = true;

		}
		else if ( posY_ > ( SCREEN_HEIGHT - DOT_WIDTH ) )	// Check for collisions with floor
		{
			player1.lowerHealth();

			if ( !player1.isAlive_ )
			{
				wall.setWall();
			}

			dot.dotReset();

			intX = posX_;
			intY = posY_;

			collisionFound = true;
		}
	}


	// Reset X and Y
	posX_ = intX;
	collider_.x = posX_;

	posY_ = intY;
	collider_.y = posY_;

	
	if ( !collisionFound )
	{
		//------- Paddle collision test ----------//

		// If no wall collisions were found position y of dot is reset in preparation for paddle collision test

		// Reset X and Y
		posX_ = intX;
		collider_.x = posX_;

		posY_ = intY;
		collider_.y = posY_;

		// Increment X
		posX_ += velX_;
		collider_.x = posX_;

		if ( checkCollision( collider_, paddle.getCollider() ) )
		{
			// Collision detected with only X incremented => C. with side

			posX_ = intX;
			collider_.x = posX_;

			velX_ *= -1;
			collisionFound = true;
			
		}
		else
		{

			// Reset X and Y
			posX_ = intX;
			collider_.x = posX_;

			posY_ = intY;
			collider_.y = posY_;

			// Increment Y
			posY_ += velY_;
			collider_.y = posY_;

			if ( checkCollision( collider_, paddle.getCollider() ) )
			{
				// Collision detected with only Y incremented => C. with top/bottom
				
				int paddleX = paddle.getCollider().x;
				int position = dot.posX_ - paddleX;
				float percent = ( position / ( paddle.getWidth() - DOT_WIDTH ) ) - 0.5;

				
				if ( position > paddle.getWidth() * 0.34 && position < paddle.getWidth() * 0.68)
				{
					velY_ *= -1;
				}
				else if ( position < paddle.getWidth() * 0.34 || position > paddle.getWidth() * 0.68 )
				{
					velX_ *= -1;
					velY_ *= -1;
				}
				posY_ = intY;
				collider_.y = posY_;

				//velX_ = percent * 15;
				//velY_ *= -1;

				collisionFound = true;
			}
			else
			{

				// Reset X and Y
				posX_ = intX;
				collider_.x = posX_;

				posY_ = intY;
				collider_.y = posY_;

				// Increment X and Y
				posX_ += velX_;
				collider_.x = posX_;

				posY_ += velY_;
				collider_.y = posY_;

				if ( checkCollision( collider_, paddle.getCollider() ) )
				{
					// Collision detected with X AND Y incremented  but not detected with separate increments => C. location unknown
					// Will be treated as top collision
					
					int paddleX = paddle.getCollider().x;
					int position = dot.posX_ - paddleX;
					float percent = ( position / ( paddle.getWidth() - DOT_WIDTH ) ) - 0.5;


					if ( position > paddle.getWidth() * 0.34 && position < paddle.getWidth() * 0.68 )
					{
						velY_ *= -1;
					}
					else if ( position < paddle.getWidth() * 0.34 || position > paddle.getWidth() * 0.68 )
					{

						velX_ *= -1;
						velY_ *= -1;
					}
					posY_ = intY;
					collider_.y = posY_;

					//velX_ = percent * 15;
					//velY_ *= -1;

					collisionFound = true;

				}
			}
		}
	}
	

	// Reset X and Y
	posX_ = intX;
	collider_.x = posX_;

	posY_ = intY;
	collider_.y = posY_;

	if ( !collisionFound )
	{
		//------- Brick collision test X ---------//

		// Reset X and Y

		posX_ = intX;
		collider_.x = posX_;

		posY_ = intY;
		collider_.y = posY_;


		// Increment X

		posX_ += velX_;
		collider_.x = posX_;

		// Check all bricks

		int iRow = 0;
		int iColumn = 0;
		while ( !collisionFound && iRow < WALL_HEIGHT && !collisionFound )
		{
			iColumn = 0;
			while ( !collisionFound && iColumn < WALL_WIDTH && !collisionFound )
			{

				if ( wall.wall[iRow][iColumn].isVisible_ )
				{
					brickCollider = wall.wall[iRow][iColumn].getCollider();
					collisionFound = checkCollision( collider_, brickCollider );

					if ( collisionFound )
					{
						// Reset X and change velocity
						posX_ = intX;
						collider_.x = posX_;

						velX_ *= -1;

						
						wall.wall[iRow][iColumn].update();
						player1.updateScore( wall.wall[iRow][iColumn].getBrickType() );

					}

				}



				iColumn++;
			}
			iRow++;
		}
	}

	// Reset X and Y
	posX_ = intX;
	collider_.x = posX_;

	posY_ = intY;
	collider_.y = posY_;

	

	if ( !collisionFound )
	{
		//------- Brick collision test Y ---------//

		// Reset X and Y

		posX_ = intX;
		collider_.x = posX_;

		posY_ = intY;
		collider_.y = posY_;


		// Increment Y

		posY_ += velY_;
		collider_.y = posY_;

		// Check all bricks

		int iRow = 0;
		int iColumn = 0;
		while ( !collisionFound && iRow < WALL_HEIGHT && !collisionFound )
		{
			iColumn = 0;
			while ( !collisionFound && iColumn < WALL_WIDTH && !collisionFound )
			{

				if ( wall.wall[iRow][iColumn].isVisible_ )
				{
					brickCollider = wall.wall[iRow][iColumn].getCollider();
					collisionFound = checkCollision( collider_, brickCollider );

					if ( collisionFound )
					{
						// Reset Y and change velocity
						posY_ = intY;
						collider_.y = posY_;
						velY_ *= -1;

						
						wall.wall[iRow][iColumn].update();
						player1.updateScore( wall.wall[iRow][iColumn].getBrickType() );

						//collisionFound = true;
					}

				}



				iColumn++;
			}
			iRow++;
		}
	}

	
	// Reset position X and Y
	posX_ = intX;
	posY_ = intY;
	
	if ( !collisionFound )//&& !collisionFoundBrickIncX && !collisionFoundBrickIncY )
	{
		posX_ += velX_;
		posY_ += velY_;
	}
	
}


void Dot::render()
{
	SDL_RenderCopy( gRenderer, gDot.getTexture(), NULL, &collider_ );
}


void Dot::dotReset()
{

	posX_ = ( SCREEN_WIDTH + DOT_WIDTH ) / 2;
	posY_ = ( SCREEN_HEIGHT + DOT_WIDTH ) / 2;

	float randAng = ( ( rand() % 120 + 30 ) / 180.0 )* PI; // between 30 and 150 deg												

	velX_ = cos( randAng ) * DOT_VEL;
	velY_ = sin( randAng ) * DOT_VEL;

	collider_ = { posX_, posY_, DOT_WIDTH, DOT_WIDTH };
}