#include<conio.h>
#include "snake.h"
#include "comida.h"

class Game {
public:

	//Variables
	int vidas;
	int score;
	bool finished;
	int speed[5];

	Snake* snake;
	Comida* comida;

	//Constructor
	Game() {
		vidas = 3;
		score = 0;
		speed[0] = 85; speed[1] = 50; speed[2] = 35; speed[3] = 25; speed[5] = 5;
		finished = false;
	}

	//Métodos
	void input()
	{
		if (_kbhit()) //revisa una tecla por si esta disponible
		{
			switch (_getch()) //obtiene la ultima letra presionada
			{
			case 'a':
				snake->snakeDirection = snake->LEFT;
				break;
			case 'd':
				snake->snakeDirection = snake->RIGHT;
				break;
			case 'w':
				snake->snakeDirection = snake->UP;
				break;
			case 's':
				snake->snakeDirection = snake->DOWN;
				break;
			case 'q':
				finished = true;
				break;
			case 'f':
				snake->skin++;

			}
		}
	}

	void gameLogic()
	{
		//movimiento de la cola
		int prevTailPosX = snake->tailPosX[0];
		int prevTailPosY = snake->tailPosY[0];
		int prevTailPos2X, prevTailPos2Y;

		snake->tailPosX[0] = snake->headPos[0];
		snake->tailPosY[0] = snake->headPos[1];

		for (int i = 1; i < snake->tailLength; i++)
		{
			prevTailPos2X = snake->tailPosX[i];
			prevTailPos2Y = snake->tailPosY[i];

			snake->tailPosX[i] = prevTailPosX;
			snake->tailPosY[i] = prevTailPosY;

			prevTailPosX = prevTailPos2X;
			prevTailPosY = prevTailPos2Y;
		}

		//revisar los choques en la pared
		if (snake->headPos[0] >= snake->W || snake->headPos[0] < 0 || snake->headPos[1] >= snake->H || snake->headPos[1] < 0)
			vidas = vidas - 1;

		//revisar los choques en la pared con la cola
		for (int i = 0; i < snake->tailLength; i++)
		{
			if (snake->tailPosX[i] == snake->headPos[0] && snake->tailPosY[i] == snake->headPos[1])
				vidas = vidas - 1;
		}

		if (vidas == 0) {
			finished = true;
		}

		//compruebe si come
		if (snake->headPos[0] == comida->foodPos[0] && snake->headPos[1] == comida->foodPos[1])
		{
			score += 10;
			comida->foodPos[0] = rand() % snake->W;
			comida->foodPos[1] = rand() % snake->H;

			snake->tailLength++;
		}
	}

};
