#pragma once

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
	
	void __fastcall clearScreen();

	/// <summary>
	/// Функция для динамического выделения памяти под двумерный массив со значениями ячеек игрового поля
	/// </summary>
	/// <param name="game"> - объект структуры Game, в котором требуется создание игрового поля </param>
	/// <returns></returns>
	void __fastcall createGameField(Game& game);

	/// <summary>
	/// Функция для очистки памяти от массива со значениями ячеек игрового поля
	/// </summary>
	/// <param name="game"> - объект структуры Game, для которого требуется удаление игрового поля из памяти </param>
	/// <returns></returns>
	void __fastcall deleteGameField(Game& game);

	/// <summary>
	/// Функция задания размера игрового поля
	/// </summary>
	/// <param name="game"> - объект структуры Game, для которого задается размер </param>
	/// <returns></returns>
	void __fastcall defineFieldSize(Game& game, int x, int y);

	/// <summary>
	/// Функция устанавливающая каким символом играет человек, а каким ИИ
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall defineSymbols(Game& game);

	/// <summary>
	/// Функция, определяющая сколько символов одного типа необходимо выстроить в линию для победы
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall defineRowLength(Game& game, int length);

	/// <summary>
	/// Функция вывода игрового поля на экран
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall drawField(Game& game);

	/// <summary>
	/// Функция для опеределия кто ходит первым
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall defineTurn(Game& game);

	Progress __fastcall isWon(Game& game);

	Coord __fastcall getCoordHuman(Game& game);

	Coord __fastcall getCoordAI(Game& game);

	Coord __fastcall getCoordAI(Game& game, bool debugCheck);

	void Conclude(Game& game);
}