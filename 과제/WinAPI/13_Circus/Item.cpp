#include "Item.h"
#include "GameFrame.h"
void Item::Reset()
{
	isActive = false;
}

void Item::Spawn(int _left, int _top)
{
	isActive = true;
	Pos.left = _left - 15;
	Pos.top = _top + 20;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 35;
}

void Item::Move(float Speed)
{
	Pos.left += Speed;
	Pos.right += Speed;
}

void Item::IsHIt(RECT Player_Rect)
{
	if (!isActive)
		return;
	RECT tmp;
	if (IntersectRect(&tmp, &Pos, &Player_Rect))  
  	{
		GameFrame::GetInstans()->ChangeScore(400);

		isActive = false; 
		return;
	}

}


void Item::Draw(HDC hdc)
{
	if (!isActive)
		return;
	BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_CASH);
}

