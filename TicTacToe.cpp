#include <iostream>
#include <random>
#include "MyLibHeader.h"


int main()
{
	MyLib::Game game;
	MyLib::defineSymbols(game);
	MyLib::defineFieldSize(game, 3, 3);
	MyLib::defineRowLength(game, 3);
	MyLib::createGameField(game);
	MyLib::drawField(game);
	MyLib::defineTurn(game);

	do 
	{
		if (game.turn % 2 == 0)
		{
			MyLib::Coord c = getCoordHuman(game);
			game.field[c.x][c.y] = game.symbolHuman;
		}
		else
		{
			MyLib::Coord c = getCoordAI(game);
			game.field[c.x][c.y] = game.symbolAI;
		}
		game.turn++;
		game.progress = isWon(game);
		MyLib::clearScreen();
		MyLib::drawField(game);
	} while (game.progress == MyLib::IN_PROGRESS);

	MyLib::Conclude(game);
	MyLib::deleteGameField(game);

}


