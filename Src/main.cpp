#include <iostream>
#include "game.hpp"


const int SCREEN_WIDTH = 2400;
const int SCREEN_HEIGHT = 1400;
const int FRAMERATE = 120;
const std::string TITLE = "Pong";

int main()
{
	Game pongGame { SCREEN_WIDTH, SCREEN_HEIGHT, FRAMERATE, TITLE };
	pongGame.Run();

	return 0;
}
