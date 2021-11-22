#pragma once
#include "Snake.h"
#include <random>

class Board
{
public:
	//Constructor y destructor
	Board(int width, int height, int x, int y);
	~Board();

	//M�todos
	bool update();
	void draw(char* screen, int screenWidth);
	int getPoints();

private:
	//Par�metros
	char* board;
	int width;
	int height;
	int x;
	int y;

	//Objetos
	Snake* snake;
	Body* food;

	//M�todos
	void changeFoodPos();
};

