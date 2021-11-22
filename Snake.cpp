#include "Snake.h"
#include <Windows.h>

Snake::Snake(int x, int y, char symbol, Direction facing) {
	this->x = x;
	this->y = y;
	this->symbol = symbol;
	this->facing = facing;
	foodEaten = 0;
	body = nullptr;
	this->buttocksX = x;
	this->buttocksY = y;
}

Snake::~Snake() {
	delete body;
}

void Snake::draw(char* board, int boardWidth, int boardHeight) {
	board[y * boardWidth + x] = symbol;
	if (foodEaten > 0) {
		for (int i = 0; i < foodEaten; i++) {
			board[body[i]->y * boardWidth + body[i]->x] = symbol;
		}
	}
}

void Snake::update() {
	//Cuerpo de la snake
	if (foodEaten > 0) {
		buttocksX = body[foodEaten - 1]->x;
		buttocksY = body[foodEaten - 1]->y;
		for (int i = foodEaten - 1; i >= 1; i--) {
			body[i]->x = body[i - 1]->x;
			body[i]->y = body[i - 1]->y;
		}
		body[0]->x = x;
		body[0]->y = y;
	}
	else {
		buttocksX = x;
		buttocksY = y;
	}
	//Cabeza
	handleInput();
	move();
	//Checkear si comió
	if (x == 20) {
		addButtocks();
	}
}

void Snake::handleInput() {
	if (GetAsyncKeyState('A') & 0x8000) {
		facing = Direction::LEFT;
	}
	else if (GetAsyncKeyState('D') & 0x8000) {
		facing = Direction::RIGHT;
	}
	else if (GetAsyncKeyState('W') & 0x8000) {
		facing = Direction::UP;
	}
	else if (GetAsyncKeyState('S') & 0x8000) {
		facing = Direction::DOWN;
	}
}

void Snake::move() {
	switch (facing)
	{
	case Direction::LEFT:
		x--;
		break;
	case Direction::RIGHT:
		x++;
		break;
	case Direction::UP:
		y--;
		break;
	case Direction::DOWN:
		y++;
		break;
	default:
		break;
	}
}

void Snake::addButtocks() {
	foodEaten += 1;
	if (foodEaten > 1) {
		Body** newBody = new Body*[foodEaten];
		for (int i = 0; i < foodEaten - 1; i++) {
			newBody[i] = body[i];
		}
		newBody[foodEaten - 1] = new Body(buttocksX, buttocksY);
		/*
		for (int i = 0; i < foodEaten - 1; i++) {
			delete[] body[i];
		}
		delete[] body;
		*/
		body = newBody;
		newBody = nullptr;
	}
	else {
		body = new Body*[1];
		body[0] = new Body(buttocksX, buttocksY);
	}
}