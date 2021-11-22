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
	//Snake
	snake = new Snake(0, 0, '@', Direction::RIGHT);
	//Comida
	food = new Body(width / 2, height / 2);
}

Board::~Board() {
	delete board;
}

bool Board::update() {
	if (snake->update(food)) {
		changeFoodPos();
	}
	for (int i = 0; i < width * height; i++) {
		board[i] = '.';
	}
	snake->draw(board, width, height);
	board[food->y * width + food->x] = '#';
	return snake->checkIfSnakeDies(width, height);
}

void Board::draw(char *screen, int screenWidth) {
	for (int i = 0; i < width * height; i++) {
		screen[(i % width + x) + (i / width + y) * screenWidth] = board[i];
	}
}

void Board::changeFoodPos() {
	food->x = rand() % width;
	food->y = rand() % height;
}

int Board::getPoints() {
	return snake->foodEaten;
}