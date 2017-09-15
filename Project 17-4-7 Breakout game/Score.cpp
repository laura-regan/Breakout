#include "Score.h"

#include "constants.h"

Score::Score()
{
	score_ = 0;
}

void Score::updateScore( int brickType )
{
	score_ += ( brickType + 1 ) * 10;

	
}

void Score::renderScore()
{

	scoreString_ = "  Score: ";

	scoreString_ += std::to_string( score_ );

	SDL_Color color = { 0xFF, 0xFF, 0xFF };

	scoreTexture_.loadFromText( scoreString_, color );

	int posY = SCREEN_HEIGHT - scoreTexture_.getHeight() * 1.3;

	renderQuad_ = { 0, posY, scoreTexture_.getWidth(), scoreTexture_.getHeight() };


	scoreTexture_.render( renderQuad_ );


}

void Score::free()
{
	scoreTexture_.free();
}