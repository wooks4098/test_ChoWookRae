#pragma once
#include "Chess_Piece.h"

//struct Position
//{
//	int x;
//	int y;
//	int Piece_Number;
//};

class Player
{
private:
	bool IsBlack;
	Chess_Piece *Piece[16];
	//Position Pos[8][8];
public:

	//피스 세팅
	void SetData_White();
	void SetData_Black();

	void SetPos_White();
	void SetPos_Black();

	void SetPiece_Data_White();
	void SetPiece_Data_Black();

	void Draw(HDC hdc);


	//클릭 이벤트
	bool PieceCheck(POINT mouse, Piece_info* info, bool* isClick); //어떤 피스를 클릭했는지 

};

