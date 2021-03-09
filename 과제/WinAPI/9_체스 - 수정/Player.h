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

	//�ǽ� ����
	void SetData_White();
	void SetData_Black();

	void SetPos_White();
	void SetPos_Black();

	void SetPiece_Data_White();
	void SetPiece_Data_Black();

	void Draw(HDC hdc);


	//Ŭ�� �̺�Ʈ
	bool PieceCheck(POINT mouse, Piece_info* info, bool* isClick); //� �ǽ��� Ŭ���ߴ��� 
	bool Piece_Click(POINT mouse, Piece_info* info, bool* isClick);//�ǽ����� / Ŭ���� �ǽ��� Ž�� �� ����
	bool Piece_Click_AgainCheck(POINT mouse, Piece_info* info, bool* isClick); //������ ������ �ǽ��� �ٽ� Ŭ���ߴ��� Ž��
	void Piece_Can_Move_Search(Piece_info info, std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]); //������ �ǽ��� �̵������� ��ǥ Ž��
	void Get_Piece_info(Piece_info Piece_Pos[][8]);//��� �ǽ� ���� ����
	//void Draw_Piece_CanMovePos(Piece_info info); //������ �ǽ��� �̵������� ��ǥ �׸���
};

