#include <iostream>
#include <random>
#include "MyLibHeader.h"


int main()
{
	MyLib::Game game;
	MyLib::defineSymbols(game);
	MyLib::defineFieldSize(game);
	MyLib::createGameField(game);
	MyLib::drawField(game);

	MyLib::deleteGameField(game);

}


