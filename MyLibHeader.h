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
	/// ������� ��� ������������� ��������� ������ ��� ��������� ������ �� ���������� ����� �������� ����
	/// </summary>
	/// <param name="game"> - ������ ��������� Game, � ������� ��������� �������� �������� ���� </param>
	/// <returns></returns>
	void __fastcall createGameField(Game& game);

	/// <summary>
	/// ������� ��� ������� ������ �� ������� �� ���������� ����� �������� ����
	/// </summary>
	/// <param name="game"> - ������ ��������� Game, ��� �������� ��������� �������� �������� ���� �� ������ </param>
	/// <returns></returns>
	void __fastcall deleteGameField(Game& game);

	/// <summary>
	/// ������� ������� ������� �������� ����
	/// </summary>
	/// <param name="game"> - ������ ��������� Game, ��� �������� �������� ������ </param>
	/// <returns></returns>
	void __fastcall defineFieldSize(Game& game);

	/// <summary>
	/// ������� ��������������� ����� �������� ������ �������, � ����� ��
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall defineSymbols(Game& game);

	/// <summary>
	/// �������, ������������ ������� �������� ������ ���� ���������� ��������� � ����� ��� ������
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall defineRowLength(Game& game);

	/// <summary>
	/// ������� ������ �������� ���� �� �����
	/// </summary>
	/// <param name="game"></param>
	/// <returns></returns>
	void __fastcall drawField(Game& game);
}