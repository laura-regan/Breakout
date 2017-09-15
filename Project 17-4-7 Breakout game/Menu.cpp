#include "Menu.h"

#include "globals.h"

Menu::Menu()
{
	buttonTextures.resize( NUM_BUTTONS );

	buttonRenderQuads.resize( NUM_BUTTONS );

	for ( int iButton = 0; iButton < NUM_BUTTONS; iButton++ )
	{
		buttonRenderQuads[iButton] = { 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT };
	}

	menuBackgroundRenderQuad = { 0,0, BACKGROUND_WIDTH, BACKGROUND_WIDTH };
}


bool Menu::loadMedia()
{
	bool success = true;

	buttonTextures[0].loadFromFile( "Media/Menu/Resume_button.png" );
	buttonTextures[1].loadFromFile( "Media/Menu/Restart_button.png" );
	buttonTextures[2].loadFromFile( "Media/Menu/Scoreboard_button.png" );
	buttonTextures[3].loadFromFile( "Media/Menu/ChangeLevel_button.png" );
	buttonTextures[4].loadFromFile( "Media/Menu/Options_button.png" );
	buttonTextures[5].loadFromFile( "Media/Menu/Quit_button.png" );

	menuBackground.loadFromFile( "Media/Menu/Menu_background.png" );


	menuBackgroundRenderQuad = { ( SCREEN_WIDTH - BACKGROUND_WIDTH ) / 2, ( SCREEN_HEIGHT - BACKGROUND_HEIGHT ) / 2, BACKGROUND_WIDTH, BACKGROUND_HEIGHT };

	for ( int iButton = 0; iButton < NUM_BUTTONS; iButton++ )
	{
		buttonRenderQuads[iButton] = { ( SCREEN_WIDTH - BUTTON_WIDTH ) / 2 , 2 * BUTTON_VERTICAL_SEPARATION + ( SCREEN_HEIGHT - BACKGROUND_HEIGHT ) / 2 + ( BUTTON_HEIGHT + BUTTON_VERTICAL_SEPARATION ) * iButton, BUTTON_WIDTH, BUTTON_HEIGHT };
	}

	return success;
}


void Menu::render()
{
	menuBackground.render(menuBackgroundRenderQuad );

	for ( int iButton = 0; iButton < NUM_BUTTONS; iButton++ )
	{
		buttonTextures[iButton].render(buttonRenderQuads[iButton] );

	}
}


void Menu::free()
{
	menuBackground.free();

	for ( int iButton = 0; iButton < NUM_BUTTONS; iButton++ )
	{
		buttonTextures[iButton].free();

	}
}