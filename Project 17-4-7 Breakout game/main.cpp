/*
 * Author:			Laura Isabel
 * Date:			7/4/2017
 * Code:			Breakout/Arkenoide style game
 */

#include <SDL.h>

#include <stdio.h>
#include <time.h>

#include "globals.h"
#include "functions.h"
#include "render_functions.h"


int main( int argc, char *args[] )
{
	if ( !init() )
	{
		printf( "Failed to initialize SDL!\n" );
	}
	else
	{
		if ( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			wall.setWall();

			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

			SDL_Event e;

			SDL_Rect mainMenu = {(SCREEN_WIDTH - 200) / 2, SCREEN_HEIGHT * 0.3, 200, 400};
			SDL_Color color = { 255, 255, 255, 150 };

			srand( time( NULL ) );

			bool paused = false;
			bool openMainMenu = true;

			bool quit = false;
			while ( !quit )
			{
				while ( SDL_PollEvent( &e ) )
				{
					if ( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE )
					{
						paused = !paused;
					}
					else if ( e.type == SDL_MOUSEBUTTONDOWN && openMainMenu )
					{

						int X, Y;
						SDL_GetMouseState( &X, &Y );
						SDL_Point mousePointer = { X, Y };

						if ( SDL_PointInRect( &mousePointer, &gStartMenu.buttonRenderQuads[0] ) )
						{
							openMainMenu = !openMainMenu;
						}
						if ( SDL_PointInRect( &mousePointer, &gStartMenu.buttonRenderQuads[4] ) )
						{
							quit = true;
						}
					}
					else if ( e.type == SDL_MOUSEBUTTONDOWN && paused)
					{

						int X, Y;
						SDL_GetMouseState( &X, &Y );
						SDL_Point mousePointer = { X, Y };

						if ( SDL_PointInRect( &mousePointer, &gMenu.buttonRenderQuads[0] ) )
						{
							paused = !paused;
						}
						if ( SDL_PointInRect( &mousePointer, &gMenu.buttonRenderQuads[1] ) )
						{
							dot.dotReset();
							wall.setWall();
							paused = !paused;
						}
						if ( SDL_PointInRect( &mousePointer, &gMenu.buttonRenderQuads[5] ) )
						{
							quit = true;
						}
					}
					else
					{
						paddle.handleEvent( e );
					}
				}

				if ( openMainMenu )
				{
					//
					renderStartMenu();
				}
				else if ( paused )
				{
					// If paused render menu
					renderMenu();
				}
				else if (!paused )
				{
					// If unpaused render game
					renderGame();
				}


				SDL_RenderPresent( gRenderer );
			}

		}
	}

	
	close();

	return 0;
}