#include<Windows.h>
#include "game.h"
#include "screen.h"
#include "snake.h"

int main()
{
	Screen *screen;
	Game *game;
	Snake *snake;

	screen->panel_de_controles();
	screen->main2();
	srand(time(0));


	while (game->finished != false)
	{	
		snake->snake_movement();
		screen->renderizado_de_pantalla_1();
		Sleep(game->speed[snake->skin]);
		game->input();
		game->gameLogic();
	}

	return 0;
}