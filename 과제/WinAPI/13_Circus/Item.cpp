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

void Item::Move()
{
	Pos.left -= 2;
	Pos.right -= 2;


}
void Item::Move_Left()
{
	Pos.left -= 2;
	Pos.right -= 2;

}
void Item::Move_Right()
{
	Pos.left +=3;
	Pos.right += 3;
}

void Item::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_CASH);
}

