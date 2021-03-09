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
	bool Piece_Click(POINT mouse, Piece_info* info, bool* isClick);//피스선택 / 클릭한 피스를 탐색 후 저장
	bool Piece_Click_AgainCheck(POINT mouse, Piece_info* info, bool* isClick); //이전에 선택한 피스를 다시 클릭했는지 탐색
	void Piece_Can_Move_Search(Piece_info info, std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]); //선택한 피스가 이동가능한 좌표 탐색
	void Get_Piece_info(Piece_info Piece_Pos[][8]);//모든 피스 정보 저장
	//void Draw_Piece_CanMovePos(Piece_info info); //선택한 피스가 이동가능한 좌표 그리기
};

