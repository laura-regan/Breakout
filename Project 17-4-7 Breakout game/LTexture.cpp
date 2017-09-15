#include "LTexture.h"

#include <SDL_image.h>
#include <stdio.h>

#include "globals.h"

LTexture::LTexture()
{
	texture_ = NULL;

	width_ = 0;
	height_ = 0;
}


LTexture::~LTexture()
{
	free();
}


void LTexture::free()
{
	if ( texture_ != NULL )
	{
		SDL_DestroyTexture( texture_ );

		width_ = 0;
		height_ = 0;
	}
}


bool LTexture::loadFromFile( std::string path )
{
	free();

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if ( loadedSurface == NULL )
	{
		printf( "Failed to load surface from %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		texture_ = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

		if ( texture_ == NULL )
		{
			printf( "Failed to create texture from surface! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			width_ = loadedSurface->w;
			height_ = loadedSurface->h;
		}
	}

	SDL_FreeSurface( loadedSurface );

	return texture_ != NULL;
}


bool LTexture::loadFromText( std::string text, SDL_Color color)
{
	free();

	SDL_Surface* loadedTextSurface = TTF_RenderText_Solid( gFont, text.c_str(), color );
	if ( loadedTextSurface == NULL )
	{
		printf( "Failed to load surface from text! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		texture_ = SDL_CreateTextureFromSurface( gRenderer, loadedTextSurface );
		if ( texture_ == NULL )
		{
			printf( "Failed to create texture from surface! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			width_ = loadedTextSurface->w;
			height_ = loadedTextSurface->h;
		}
	}

	SDL_FreeSurface( loadedTextSurface );
	loadedTextSurface = NULL;


	return texture_ != NULL;
}



void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	SDL_SetTextureColorMod( texture_, red, green, blue );
}


SDL_Texture* LTexture::getTexture()
{
	return texture_;
}


void LTexture::render( SDL_Rect renderQuad )
{
	SDL_RenderCopy( gRenderer, texture_, NULL, &renderQuad );
}


int LTexture::getWidth()
{
	return width_;
}


int LTexture::getHeight()
{
	return height_;
}