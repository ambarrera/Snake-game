#pragma once
#include "Snake.h"

class Board
{
public:
	//Constructor y destructor
	Board(int width, int height, int x, int y);
	~Board();

	//M�todos
	void update();
	void draw(char* screen, int screenWidth);

private:
	//Par�metros
	char* board;
	int width;
	int height;
	int x;
	int y;

	//Objetos
	Snake* snake;
};

