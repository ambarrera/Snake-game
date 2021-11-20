#pragma once
class Board
{
public:
	//Constructor y destructor
	Board(int width, int height, int x, int y);
	~Board();

	//M�todos
	void draw(char* screen, int screenWidth);

private:
	//Par�metros
	char* board;
	int width;
	int height;
	int x;
	int y;
};

