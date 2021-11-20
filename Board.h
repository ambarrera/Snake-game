#pragma once
class Board
{
public:
	//Constructor y destructor
	Board(int width, int height, int x, int y);
	~Board();

	//Métodos
	void draw(char* screen, int screenWidth);

private:
	//Parámetros
	char* board;
	int width;
	int height;
	int x;
	int y;
};

