#ifndef HEALTH_H
#define HEALTH_H

#include <vector>

#include "constants.h"
#include "LTexture.h"


class Health
{
public:
	static const int HEART_WIDTH = SCREEN_WIDTH * 0.03;
	static const int MAX_HEALTH = 3;

	Health();

	bool loadMedia();

	void lowerHealth();

	void renderHealth();

	void resetHealth();

	bool isAlive_;

private:

	int health_;

	LTexture heartFull_;
	LTexture heartEmpty_;

	std::vector<SDL_Rect> renderQuads;
};


#endif