#include "Board.h"

Board::Board(int width, int height, int x, int y) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	board = new char[width * height];
	for (int i = 0; i < width * height; i++) {
		board[i] = '.';
	}

	snake = new Snake(0, 0, '@', Direction::RIGHT);
}

Board::~Board() {
	delete board;
}

void Board::update() {
	snake->update();
	for (int i = 0; i < width * height; i++) {
		board[i] = '.';
	}
	snake->draw(board, width, height);
}

void Board::draw(char *screen, int screenWidth) {
	for (int i = 0; i < width * height; i++) {
		screen[(i % width + x) + (i / width + y) * screenWidth] = board[i];
	}
}