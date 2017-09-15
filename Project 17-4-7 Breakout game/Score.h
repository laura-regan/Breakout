#ifndef SCORE_H
#define SCORE_H

#include <string>

#include "LTexture.h"

class Score
{
public:

	Score();

	void updateScore(int brickType);

	void renderScore();

	void free();

private:

	LTexture scoreTexture_;

	int score_;

	std::string scoreString_;

	SDL_Rect renderQuad_;
};

#endif