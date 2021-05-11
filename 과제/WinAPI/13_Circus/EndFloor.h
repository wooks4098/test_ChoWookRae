#pragma once
#include "BitMapManager.h"
#include "Mecro.h"
class EndFloor
{
private:
	RECT Pos;

public:

	void Move(int Move_Dir, float m_fDeltaTime);
	bool HitCheck(RECT Player_Rect);
	void Draw(HDC hdc);
	EndFloor();
	~EndFloor();
};

