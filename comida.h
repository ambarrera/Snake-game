#include <windows.h>
#include "snake.h"

class Comida {
public:

	//Variables
	char comida;
	int foodPos[2];

	Snake *snake;

	//Constructor
	Comida() {
		foodPos[0] = rand() % snake->W;
		foodPos[1] = rand() % snake->H;
		comida = '*';
	}

};
