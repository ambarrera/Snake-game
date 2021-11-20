#pragma once
#include "Board.h"

class Game
{
public:
	//Constructor y destructor
	Game(int width, int height, int boardWidth, int boardHeight);
	~Game();

	//M�todo principal
	void run();

private:
	//Par�metros
	char *screen;
	int width;
	int height;
	bool running;
	Board *board;

	//M�todos
	void updateAllObjects();
	void updateScreen();
	void renderScreen();
};
