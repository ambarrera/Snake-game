#include <iostream>
#include "Game.h"

int main() {
	int width;
	int height;
	std::cout << "Ingrese ancho y alto: ";
	std::cin >> width;
	std::cin >> height;
	Game game(120, 30, width, height);
	game.run();

	return 0;
}
