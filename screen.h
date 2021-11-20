#include<Windows.h>
#include<iostream>
#include "snake.h"
#include "comida.h"
#include "game.h"

using namespace std;

class Screen {
public:

	//Variables
	char pared_v;
	char pared_h;

	Snake *snake;
	Comida *comida;
	Game *game;

	//COnstructor
	Screen() {
		pared_v = '|';
		pared_h = '-';
	}

	//Métodos

	void panel_de_controles() {

		cout << "\t CONTROLES" << endl;
		cout << "\t ---------" << endl;
		cout << "movimiento:" << endl;
		cout << "\t" "  " " W" << endl;
		cout << "\t A S D" << endl;
		cout << "cambio de skin: F" << endl;
		cout << "acabar el juego: Q" << endl;
		cout << "-----------------------" << endl << "\n";
	}

	void main2() {
		cout << "O" << "\t #" << "\t @" << "\t =" << "\t /" << endl;
		cout << "o" << "\t #" << "\t @" << "\t =" << "\t /" << endl;
		cout << "o" << "\t #" << "\t @" << "\t =" << "\t /" << endl;
		cout << "(1)" << "\t (2)" << "\t (3)" << "\t (4)" << "\t (5)" << endl;
		cout << "\n select your skin: "; cin >> snake->skin;
		snake->skin -= 1;
	}

	void renderizado_de_pantalla_1() {
		system("cls"); //limpia el sistema 

		//pared de arriba
		for (int i = 0; i < snake->W + 2; i++)
		{
			cout << pared_h;
		}
		cout << endl;


		for (int i = 0; i < snake->H; i++)
		{
			for (int j = 0; j < snake->W; j++)
			{
				if (j == 0) //pared izquierda
					cout << pared_v;

				if (j == snake->headPos[0] && i == snake->headPos[1]) //cabeza de la serpiente
					cout << snake->cabeza;

				else if (j == comida->foodPos[0] && i == comida->foodPos[1]) //Comida
					cout << comida;

				else
				{
					bool printTail = false;

					for (int k = 0; k < snake->tailLength; k++) //Cola
					{

						if (snake->tailPosX[k] == j && snake->tailPosY[k] == i)
						{
							cout << snake->cola;
							printTail = true;
						}
					}

					if (!printTail) //espacio en blanco
						cout << " ";
				}

				if (j == snake->W - 1) //pared derecha
					cout << pared_v;
			}

			cout << endl;
		}

		//pared baja
		for (int i = 0; i < snake->W + 2; i++)
		{
			cout << pared_h;
		}

		cout << endl << endl;

		cout << "Score: " << game->score << endl;
		cout << "Lives: " << game->vidas << endl;
	}

};