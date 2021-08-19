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
	
	void inline clearScreen();

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
	void __fastcall defineFieldSize(Game& game);

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
	void __fastcall defineRowLength(Game& game);

	/// <summary>
	/// Функция вывода игрового поля на экран
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall drawField(Game& game);
}