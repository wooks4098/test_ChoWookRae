#include "Item.h"

void Item::Reset()
{
	isActive = false;
}

void Item::Spawn(int _left, int _top)
{
	isActive = true;
	Pos.left = _left + 12;
	Pos.top = _top + 20;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 35;
}

void Item::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_CASH);
}

