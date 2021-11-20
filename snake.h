#include <conio.h>

class Snake{
public:
	
	//Varibales
	int skin;
	char skins[5];
	char cabeza;
	char cola;
	int headPos[2];
	int tailPosX[100], tailPosY[100], tailLength;
	int W, H;
	enum directionE { STOP = 0, LEFT, RIGHT, UP, DOWN };
	directionE snakeDirection;
		
	//Construcutor 
	Snake() {
		W = 20;
		H = 20;
		headPos[0] = W/2; headPos[1] = H/2;
		skins[0] = 'O'; skins[1] = '#'; skins[2] ='@'; skins[3] = '='; skins[4] = '/' ;
		skin = skin % 5;
		cabeza = skins[skin];
		cola = skins[skin];
	}

	//Métodos

	void snake_movement() 
	{
		//movimiento de serpiente
		switch (snakeDirection)
		{
		case STOP:
			break;

		case LEFT:
			headPos[0]--;
			break;

		case RIGHT:
			headPos[0]++;
			break;

		case UP:
			headPos[1]--;
			break;

		case DOWN:
			headPos[1]++;
			break;
		}
	}

};
