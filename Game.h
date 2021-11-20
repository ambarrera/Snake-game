#pragma once
#include "Board.h"

class Game
{
public:
	//Constructor y destructor
	Game(int width, int height, int boardWidth, int boardHeight);
	~Game();

	//Método principal
	void run();

private:
	//Parámetros
	char *screen;
	int width;
	int height;
	bool running;
	Board *board;

	//Métodos
	void updateAllObjects();
	void updateScreen();
	void renderScreen();
};
