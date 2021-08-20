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
		HUMAN_VICTORY,
		DRAW
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

	void __fastcall clearScreen()
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

	void __fastcall defineFieldSize(Game& game, int x, int y)
	{
		game.fieldSizeX = x;
		game.fieldSizeY = y;
	}

	void __fastcall defineSymbols(Game& game)
	{
		game.symbolHuman = CROSS;
		game.symbolAI = ZERO;
	}

	void __fastcall defineRowLength(Game& game, int length)
	{
		game.rowLengthToWin = length;
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

	void __fastcall defineTurn(Game& game)
	{
		srand(time(0));
		game.turn = std::rand() % 2;
	}

	Progress __fastcall isWon(Game& game)
	{
		int rowLengthCountX, rowLengthCountY, rowLengthCountDiag, rowLengthCountDiag2;

		//Check rows
		for (int x = 0; x < game.fieldSizeX; x++)
		{
			rowLengthCountX = 1;
			for (int y = 0; y < game.fieldSizeY - 1; y++)
			{
					if (game.field[x][y] == game.field[x][y + 1])
					{
						rowLengthCountX++;
						if (rowLengthCountX == game.rowLengthToWin && game.field[x][y] == game.symbolHuman) return HUMAN_VICTORY;
						else if (rowLengthCountX == game.rowLengthToWin && game.field[x][y] == game.symbolAI) return AI_VICTORY;
					}
					else rowLengthCountX = 1;
			}
		}

		//Check colomns
		for (int y = 0; y < game.fieldSizeY; y++)
		{
			rowLengthCountY = 1;
			for (int x = 0; x < game.fieldSizeX - 1; x++)
			{
					if (game.field[x][y] == game.field[x + 1][y])
					{
						rowLengthCountY++;
						if (rowLengthCountY == game.rowLengthToWin && game.field[x][y] == game.symbolHuman) return HUMAN_VICTORY;
						else if (rowLengthCountY == game.rowLengthToWin && game.field[x][y] == game.symbolAI) return AI_VICTORY;
					}
					else rowLengthCountY = 1;
			}
		}

		//Check main diagonal
		rowLengthCountDiag = 1;
		for (int i = 0; i < game.fieldSizeX - 1; i++)
		{
			if (game.field[i][i] == game.field[i + 1][i + 1])
			{
				rowLengthCountDiag++;
				if (rowLengthCountDiag == game.rowLengthToWin && game.field[i][i] == game.symbolHuman) return HUMAN_VICTORY;
				else if (rowLengthCountDiag == game.rowLengthToWin && game.field[i][i] == game.symbolAI) return AI_VICTORY;
			}
			else rowLengthCountDiag = 1;
		}

		//Check second diagonal
		/*rowLengthCountDiag2 = 1;
		for (int i = game.fieldSizeX - 1; i > 0; i--)
		{
			for (int j = 0; j < game.fieldSizeY - 1; j++)
			{
				if (game.field[i][j] == game.field[i - 1][j + 1])
				{
					rowLengthCountDiag2++;
					if (rowLengthCountDiag2 == game.rowLengthToWin && game.field[i][j] == game.symbolHuman) return HUMAN_VICTORY;
					else if (rowLengthCountDiag2 == game.rowLengthToWin && game.field[i][j] == game.symbolAI) return AI_VICTORY;
				}
				else rowLengthCountDiag2 = 1;
			}
		}*/

		if (game.field[2][0] == game.field[1][1] && game.field[2][0] == game.field[0][2])
		{
			if (game.field[1][1] == game.symbolHuman) return HUMAN_VICTORY;
			if (game.field[1][1] == game.symbolAI) return AI_VICTORY;
		}

		

		bool draw = true;
		for (int x = 0; x < game.fieldSizeX; x++)
		{
			for (int y = 0; y < game.fieldSizeY; y++)
			{
				if (game.field[x][y] == NONE) draw = false;
			}
		}

		if (draw) return DRAW;

		return IN_PROGRESS;

	}

	Coord __fastcall getCoordHuman(Game& game) 
	{
		Coord c{ 0 };
		do
		{
			std::cout << "\nEnter x: ";
			std::cin >> c.x;
			std::cout << "Enter y: ";
			std::cin >> c.y;
		} while (c.x < 1 || c.y < 1 || c.x > game.fieldSizeX || c.y > game.fieldSizeY || game.field[c.x-1][c.y-1] != NONE);

		c.x--;
		c.y--;

		return c;
	}

	Coord __fastcall getCoordAI(Game& game, bool debugCheck)
	{
		Coord c{ 0 };
		do
		{
			std::cout << "\nEnter x: ";
			std::cin >> c.x;
			std::cout << "Enter y: ";
			std::cin >> c.y;
		} while (c.x < 1 || c.y < 1 || c.x > game.fieldSizeX || c.y > game.fieldSizeY || game.field[c.x - 1][c.y - 1] != NONE);

		c.x--;
		c.y--;

		return c;
	}

	Coord __fastcall getCoordAI(Game& game)
	{
		if (game.field[game.fieldSizeX / 2][game.fieldSizeY / 2] == NONE)
		{
			return { game.fieldSizeX / 2, game.fieldSizeY / 2 };
		}

		for (int x = 0; x < game.fieldSizeX; x++)
		{
			for (int y = 0; y < game.fieldSizeY; y++)
			{
				if (game.field[x][y] == NONE)
				{
					game.field[x][y] = game.symbolAI;
					if (isWon(game) == AI_VICTORY)
					{
						game.field[x][y] = NONE;
						return { y, x };
					}
					game.field[x][y] = NONE;
				}
			}
		}

		for (int x = 0; x < game.fieldSizeX; x++)
		{
			for (int y = 0; y < game.fieldSizeY; y++)
			{
				if (game.field[x][y] == NONE)
				{
					game.field[x][y] = game.symbolHuman;
					if (isWon(game) == HUMAN_VICTORY)
					{
						game.field[x][y] = NONE;
						return { y, x };
					}
					game.field[x][y] = NONE;
				}			
			}
		}

		if (game.field[0][0] == NONE) return { 0,0 };
		if (game.field[0][game.fieldSizeY - 1] == NONE) return { game.fieldSizeY - 1, 0 };
		if (game.field[game.fieldSizeX - 1][0] == NONE) return { 0, game.fieldSizeX - 1 };
		if (game.field[game.fieldSizeX - 1][game.fieldSizeY - 1] == NONE) return { game.fieldSizeY - 1,game.fieldSizeX - 1 };

		for (int i = 0; i < game.fieldSizeX; i++)
		{
			for (int j = 0; j < game.fieldSizeY; j++)
			{
				if (game.field[i][j] == NONE) return { j, i };
			}
		}
	}

	void Conclude(Game& game)
	{
		if (game.progress == MyLib::HUMAN_VICTORY) std::cout << "\nHuman won!";
		if (game.progress == MyLib::AI_VICTORY) std::cout << "\nAI won!";
		if (game.progress == MyLib::DRAW) std::cout << "\nIt's a draw!";
	}
}