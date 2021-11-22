#include <iostream>
#include "Game.h"
#include <random>


int main() {
	srand(time(NULL));
	int Width = 120;
	int Height = 30;
	int boardWidth;
	int boardHeight;
	std::cout << "SNAKE - GAME\n";
	std::cout << "Ingrese ancho y alto (max " << Width  << " x " << Height - 5 << "): ";
	std::cin >> boardWidth;
	std::cin >> boardHeight;
	while (boardWidth > Width || boardHeight > Height - 5) {
		std::cout << "Ingrese otros datos: ";
		std::cin >> boardWidth;
		std::cin >> boardHeight;
	}
	Game game(Width, Height, boardWidth, boardHeight);
	game.run();

	return 0;
}
