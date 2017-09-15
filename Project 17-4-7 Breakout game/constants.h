#ifndef CONSTANTS_H
#define CONSTANTS_H

// 800x600, 1280x960
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


const enum BRICK_COLOR
{
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	TOTAL_COLORS
};

const int WALL_WIDTH = 8;
const int WALL_HEIGHT = TOTAL_COLORS;


const int PI = 3.14159265;

#endif

