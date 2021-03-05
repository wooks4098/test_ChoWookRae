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
	POINT MousePointChange(POINT mouse);//마우스 포인터 위치 좌표로 변환

	int TurnCheck();//현재 턴의 플레이어 반환
};

