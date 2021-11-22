#pragma once
#include "Snake.h"
#include <random>

class Board
{
public:
	//Constructor y destructor
	Board(int width, int height, int x, int y);
	~Board();

	//Métodos
	bool update();
	void draw(char* screen, int screenWidth);
	int getPoints();

private:
	//Parámetros
	char* board;
	int width;
	int height;
	int x;
	int y;

	//Objetos
	Snake* snake;
	Body* food;

	//Métodos
	void changeFoodPos();
};

