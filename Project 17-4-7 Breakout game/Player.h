#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Health.h"
#include "Score.h"

class Player: public Health, public Score
{
public:

	Player();


	void inputName();

	int getScore();

private:


	std::string name_;




};


#endif

