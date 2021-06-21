#include <iostream>
#include "game.hpp"


const int SCREEN_WIDTH = 2400;
const int SCREEN_HEIGHT = 1440;
const int FRAMERATE = 400;
const std::string TITLE = "Pong";

int main()
{
	Game pong { SCREEN_WIDTH, SCREEN_HEIGHT, FRAMERATE, TITLE };
	pong.Run();

	return 0;
}
