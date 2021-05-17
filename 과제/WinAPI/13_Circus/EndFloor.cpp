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
	if (Player_Speed < 0)
	{
		if (Pos.left <= 450)
			return;
	}

	Pos.left += Move_Dir * Player_Speed;
	Pos.right += Move_Dir * Player_Speed;


}
bool EndFloor::HitCheck(RECT Player_Rect)
{
	RECT tmp;
	RECT PlayerRect = Player_Rect;
	PlayerRect.bottom += 45;
	if (IntersectRect(&tmp, &Pos, &PlayerRect))
	{
		return true;
	}
	return false;
}
void EndFloor::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_END);
}
void EndFloor::Reset()
{
	Pos.left = 3650;
	Pos.top = 310;
	Pos.right = Pos.left + 100;
	Pos.bottom = Pos.top + 20;
}

EndFloor::~EndFloor()
{
}
