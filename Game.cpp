#include "Game.h"
#include <iostream>
#include <Windows.h>

Game::Game(int width, int height, int boardWidth, int boardHeight) {
	this->width = width;
	this->height = height;
	screen = new char[width * height];
	for (int i = 0; i < width * height; i++) {
		screen[i] = ' ';
	}
	//Tablero
	int boardX = (width / 2) - (boardWidth / 2);
	int boardY = 3;
	board = new Board(boardWidth, boardHeight, boardX, boardY);

	running = true;
}

Game::~Game() {
	delete screen;
}

void Game::run() {
	while (running) {
		updateAllObjects();
		updateScreen();
		renderScreen();
	}
	drawGameOver();
}

void Game::updateAllObjects() {
	//update all objects
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
		running = false;
	}
	running = (board->update());
}

void Game::updateScreen() {
	board->draw(screen, width);
	drawPoints(3, 1, board->getPoints());
}

void Game::renderScreen() {
	system("CLS");
	for (int i = 0; i < width * height; i++) {
		std::cout << screen[i];
	}
}

void Game::drawGameOver() {
	system("CLS");
	std::cout << "GAME OVER\nPoints: " << board->getPoints();
}

void Game::drawPoints(int x, int y, int points) {
	char text[9] = "Points: ";
	char nums[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < 8; i++) {
		screen[y * width + x + i] = text[i];
	}
	if (points >= 100) {
		screen[y * width + x + 8] = nums[points / 100];
		screen[y * width + x + 8 + 1] = nums[(points % 100) / 10];
		screen[y * width + x + 8 + 2] = nums[(points % 100) % 10];
	}
	else if (points >= 10) {
		screen[y * width + x + 8] = nums[points / 10];
		screen[y * width + x + 8 + 1] = nums[points % 10];
	}
	else {
		screen[y * width + x + 8] = nums[points];
	}
}