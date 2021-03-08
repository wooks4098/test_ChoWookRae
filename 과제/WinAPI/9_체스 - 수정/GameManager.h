#pragma once
#include "Player.h"
#include "Map.h"


class GameManager
{
private:
	int Trun;
	bool ClickPiece;
	Player player[2];
	Piece_info ClickPiece_info;
public:
	void SetData();
	void Draw(HDC hdc);

	//Ŭ�� �̺�Ʈ
	void MouseClick(POINT mouse);
	POINT MousePointChange(POINT mouse);//���콺 ������ ��ġ ��ǥ�� ��ȯ

	void PieceCheck(POINT mouse); //� �ǽ��� Ŭ���ߴ��� 


	int TurnCheck();//���� ���� �÷��̾� ��ȯ
};

