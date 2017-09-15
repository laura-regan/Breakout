#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>

#include <string>

class LTexture
{
public:

	LTexture();

	~LTexture();

	void free();

	bool loadFromFile( std::string path );

	bool loadFromText( std::string text, SDL_Color );

	void setColor( Uint8 red, Uint8 green, Uint8 blue );

	SDL_Texture* getTexture();

	void render( SDL_Rect renderQuad );

	int getWidth();

	int getHeight();

private:

	SDL_Texture* texture_;

	int width_;
	int height_;
};

#endif

