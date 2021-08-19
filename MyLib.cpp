#include <iostream>



namespace MyLib
{
	
	enum Cell {
		ZERO = '0',
		CROSS = 'X',
		NONE = '_'
	};

	enum Progress {
		IN_PROGRESS,
		AI_VICTORY,
		HUMAN_VICTORY
	};

	struct Coord {
		int y = 0;
		int x = 0;
	};

	struct Game {
		Cell** field = nullptr;
		int fieldSizeX = 3;
		int fieldSizeY = 3;
		int rowLengthToWin = 3;
		Progress progress = IN_PROGRESS;
		int turn = 0;
		Cell symbolAI = ZERO;
		Cell symbolHuman = CROSS;
	};

	//__________________________________________________________________________________________________________________________

	void inline clearScreen()
	{
		system("cls");
	}

	void __fastcall createGameField(Game& game)
	{
		game.field = new Cell * [game.fieldSizeY];
		for (int i = 0; i < game.fieldSizeY; i++)
		{
			game.field[i] = new Cell[game.fieldSizeX];
		}

		for (int i = 0; i < game.fieldSizeY; i++)
		{
			for (int j = 0; j < game.fieldSizeX; j++)
			{
				game.field[i][j] = NONE;
			}
		}
	}

	void __fastcall deleteGameField(Game& game)
	{

		for (int i = 0; i < game.fieldSizeY; i++)
		{
			delete[] game.field[i];
		}
		delete[] game.field;
	}

	void __fastcall defineFieldSize(Game& game)
	{
		game.fieldSizeX = 3;
		game.fieldSizeY = 3;
	}

	void __fastcall defineSymbols(Game& game)
	{
		game.symbolHuman = CROSS;
		game.symbolAI = ZERO;
	}

	void __fastcall defineRowLength(Game& game)
	{

	}

	void __fastcall drawField(Game& game)
	{
		std::cout << "   ";
		for (int y = 0; y < game.fieldSizeY; y++)
		{
			std::cout << " " << (y + 1) << " ";
		}
		std::cout << "\n";

		for (int x = 0; x < game.fieldSizeX; x++)
		{
			std::cout << " " << (x + 1) << " ";
			for (int y = 0; y < game.fieldSizeY; y++)
			{
				std::cout << "|" << (char)game.field[x][y] << "|";
			}
			std::cout << "\n";
		}
	}
}