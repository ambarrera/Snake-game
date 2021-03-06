#pragma once

enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Body {
public:
	int x, y;
	Body(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Snake
{
public:
	//Constructor y destructor
	Snake(int x, int y, char symbol, Direction facing);
	~Snake();

	//M?todos
	void draw(char* board, int boardWidth, int boardHeight);
	bool update(Body* food);
	bool checkIfSnakeDies(int width, int height);

	int foodEaten;

private:
	//Par?metros
	int x, y;
	char symbol;
	Direction facing;
	int buttocksX, buttocksY;

	//Cuerpo de la Serpiente
	Body** body;

	//M?todos
	void move();
	void handleInput();
	void addButtocks();
};
