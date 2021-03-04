#pragma once
#include "Chess_Piece.h"

struct Position
{
	int x;
	int y;
	int Piece_Number;
};

class Player
{
private:
	Chess_Piece *Piece[16];
	Position Pos[8][8];
public:


	void SetData_White();
	void SetData_Black();

	void SetPos_White();
	void SetPos_Black();

	void SetPiece_Data_White();
	void SetPiece_Data_Black();


	void TestDraw(HDC hdc)
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (Pos[y][x].Piece_Number != NULLPIECE)
					Piece[Pos[y][x].Piece_Number]->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT);
			}
		}
	}
};

