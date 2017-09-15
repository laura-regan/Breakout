#include "render_functions.h"

#include <SDL.h>

#include "globals.h"
#include "Player.h"
#include "Health.h"

void renderMenu()
{
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
	SDL_RenderClear( gRenderer );

	player1.renderHealth();
	player1.renderScore();
	wall.renderWall();
	paddle.render();
	dot.render();

	gMenu.render();

}


void renderGame()
{
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
	SDL_RenderClear( gRenderer );

	paddle.move();
	dot.move();

	player1.renderHealth();
	player1.renderScore();
	wall.renderWall();
	paddle.render();
	dot.render();
	player1.renderScore();
	
}


void renderStartMenu()
{
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
	SDL_RenderClear( gRenderer );

	gStartMenu.render();
}