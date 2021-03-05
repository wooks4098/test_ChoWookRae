#pragma once
#include "Player.h"
#include "Map.h"
class GameManager
{
private:
	int Trun;
	bool ClickPiece;
	Player player[2];
public:
	void SetData();
	void Draw(HDC hdc);

	void MouseClick(POINT mouse);
	POINT MousePointChange(POINT mouse);//���콺 ������ ��ġ ��ǥ�� ��ȯ

	int TurnCheck();//���� ���� �÷��̾� ��ȯ
};

