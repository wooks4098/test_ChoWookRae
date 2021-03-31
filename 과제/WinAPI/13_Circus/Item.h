#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
class Item
{
private :
	RECT Pos;
	RECT HitBox;
	bool isActive;
public:
	void Draw();
	void Reset();
	bool Return_Active() { return isActive; }
};

