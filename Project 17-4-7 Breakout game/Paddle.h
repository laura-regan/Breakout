#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>

class Paddle
{
public:

	static const int PADDLE_VEL = 20;

	Paddle();

	void handleEvent(SDL_Event e);

	void move();

	void render();

	SDL_Rect getCollider();

	int getWidth();

private:

	int paddleWidth_;
	int paddleHeight_;

	int posX_;
	int posY_;

	int velX_;
	//int velY_;

	

	SDL_Rect collider_;
};


#endif

