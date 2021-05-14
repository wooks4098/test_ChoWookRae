#pragma once
#include "BitMapManager.h"
#include "Mecro.h"
class EndFloor
{
private:
	RECT Pos;

public:

	void Move(float Move_Dir, float Player_Speed);
	bool HitCheck(RECT Player_Rect);
	void Draw(HDC hdc);
	void Reset();

	RECT Return_Rect() { return Pos; };
	EndFloor();
	~EndFloor();
};

