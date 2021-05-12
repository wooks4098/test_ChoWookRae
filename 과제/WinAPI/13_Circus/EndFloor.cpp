#include "EndFloor.h"



EndFloor::EndFloor()
{
	Pos.left = 3650;
	Pos.top = 310;
	Pos.right = Pos.left + 100;
	Pos.bottom = Pos.top + 20;
}

void EndFloor::Move(float Move_Dir, float Player_Speed)
{
	
	Pos.left += Move_Dir * Player_Speed;
	Pos.right += Move_Dir * Player_Speed;
	if (Pos.left <= 500)
	{
		Pos.left = 500;
		Pos.right = Pos.left + 100;
		return;

	}
}
bool EndFloor::HitCheck(RECT Player_Rect)
{
	return false;
}
void EndFloor::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_END);
}


EndFloor::~EndFloor()
{
}
