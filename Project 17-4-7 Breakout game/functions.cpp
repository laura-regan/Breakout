#include "functions.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <string>

#include "constants.h"
#include "globals.h"


bool init()
{
	bool success = true;

	if ( SDL_Init( SDL_INIT_VIDEO < 0 ) )
	{
		printf( "SDL failed to initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow( "Breakout! (The Closet)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if ( gWindow == NULL )
		{
			printf( "SDL failed to create window! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if ( gRenderer == NULL )
			{
				printf( "SDL failed to create renderer from window! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_SetRenderDrawBlendMode( gRenderer, SDL_BLENDMODE_BLEND );

				int intFlags = IMG_INIT_PNG;
				if ( !( IMG_Init( intFlags ) & intFlags ) )
				{
					printf( "SDL_image failed to initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				else
				{
					if ( TTF_Init() == -1 )
					{
						printf( "SDL_ttf failed to initialize! SDL_ttf Error: %s\n", TTF_GetError() );
						success = false;
					}
				}
			}
		}
	}

	return success;
}


bool loadMedia()
{
	bool success = true;

	SDL_Texture* texture = NULL;

	std::string path = "Media/Bricks/Bar_x";

	gBrickTextures.resize( BRICK_COLOR::TOTAL_COLORS );

	gFont = TTF_OpenFont( "Media/Fonts/OpenSans-Bold.ttf", 28 );
	if ( gFont == NULL )
	{
		printf( "Failed to open font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	


	for ( int iColor = 0; iColor < TOTAL_COLORS; iColor++ )
	{
		char lastChar = '0' + iColor;

		// Deletes last character of path name
		path.pop_back();

		// Completes path name with the file end number, e.g. File name Brick_0 has final char '0'
		path += lastChar;
		if ( !gBrickTextures[iColor].loadFromFile( path + ".png" ) )
		{
			success = false;
		}
	}

	if ( !gPaddle.loadFromFile( "Media/Bricks/Bar_white.png" ) )
	{
		success = false;
	}

	if ( !gDot.loadFromFile( "Media/Dot_white.png" ) )
	{
		success = false;
	}
	else
	{
		gDot.setColor( 255, 255, 255 );
	}

	if ( !gMenu.loadMedia() )
	{
		success = false;
	}

	if ( !gStartMenu.loadMedia() )
	{
		success = false;
	}

	if ( !player1.loadMedia() )
	{
		success = false;
	}

	return success;
}


void close()
{
	//Free textures
	for ( int i = 0; i < TOTAL_COLORS; i++ )
	{
		gBrickTextures[i].free();
	}

	gPaddle.free();
	gDot.free();
	gMenu.free();
	gStartMenu.free();
	player1.free();


	SDL_DestroyWindow( gWindow );
	SDL_DestroyRenderer( gRenderer );
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


bool checkCollision( SDL_Rect a, SDL_Rect b )
{
	int leftA, rightA, topA, bottomA;
	int leftB, rightB, topB, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if ( rightA <= leftB )
	{
		return false;
	}
	if ( rightB <= leftA )
	{
		return false;
	}
	if ( bottomA <= topB )
	{
		return false;
	}
	if ( bottomB <= topA )
	{
		return false;
	}


	return true;
}