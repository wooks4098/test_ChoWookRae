#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
class Item
{
private :
	RECT Pos;

	bool isActive;
public:
	void Draw(HDC hdc);
	void Reset();
	void Spawn(int _left, int _top);

	void Move(float Speed);//기본이동

	bool IsHIt(RECT Player_Rect);

	bool Return_Active() { return isActive; }
};

