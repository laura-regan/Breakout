#include "Health.h"

#include "constants.h"
Health::Health()
{
	health_ = 3;

	isAlive_ = true;

	renderQuads.resize( MAX_HEALTH );


	renderQuads[0] = { static_cast<int>( SCREEN_WIDTH - HEART_WIDTH * 1.3 ) , static_cast<int>( HEART_WIDTH * 0.3 ), HEART_WIDTH, HEART_WIDTH };
	renderQuads[1] = { static_cast<int>( SCREEN_WIDTH - HEART_WIDTH * 1.3 * 2 ), static_cast<int>( HEART_WIDTH * 0.3 ), HEART_WIDTH, HEART_WIDTH };
	renderQuads[2] = { static_cast<int>( SCREEN_WIDTH - HEART_WIDTH * 1.3 * 3 ), static_cast<int>( HEART_WIDTH * 0.3 ), HEART_WIDTH, HEART_WIDTH };
}

void Health::renderHealth()
{

	if ( health_ == 3 )
	{
		heartFull_.render( renderQuads[0] );
		heartFull_.render( renderQuads[1] );
		heartFull_.render( renderQuads[2] );
	}
	if ( health_ == 2 )
	{
		heartEmpty_.render( renderQuads[0] );
		heartFull_.render( renderQuads[1] );
		heartFull_.render( renderQuads[2] );
	}
	if ( health_ == 1 )
	{
		heartEmpty_.render( renderQuads[0] );
		heartEmpty_.render( renderQuads[1] );
		heartFull_.render( renderQuads[2] );
	}
	if ( health_ == 0 )
	{
		heartEmpty_.render( renderQuads[0] );
		heartEmpty_.render( renderQuads[1] );
		heartEmpty_.render( renderQuads[2] );
	}

	if ( health_ < 0 )
	{
		resetHealth();
	}

}


void Health::lowerHealth()
{
	health_--;

	if ( health_ < 0 )
	{
		isAlive_ = false;
	}
}


bool Health::loadMedia()
{
	heartFull_.loadFromFile( "Media/UI/Heart_full.png" );
	heartEmpty_.loadFromFile( "Media/UI/Heart_empty.png" );

	return true;
}


void Health::resetHealth()
{
	health_ = 3;

	isAlive_ = true;
}