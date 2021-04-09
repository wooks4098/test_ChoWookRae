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

	void Move();//기본이동
	void Move_Left();//플레이어가 앞으로가면 이동하도록
	void Move_Right();//플레이어가 뒤로가면 이동하도록

	bool Return_Active() { return isActive; }
};

