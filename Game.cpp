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
	int boardX = (width / 2) - (boardWidth / 2);
	int boardY = 0;
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
}

void Game::updateAllObjects() {
	//update all objects
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
		running = false;
	}
}

void Game::updateScreen() {
	board->draw(screen, width);
}

void Game::renderScreen() {
	system("CLS");
	for (int i = 0; i < width * height; i++) {
		std::cout << screen[i];
	}
}