#include "EndFloor.h"



EndFloor::EndFloor()
{
	Pos.left = 5000;
	Pos.top = 310;
	Pos.right = Pos.left + 100;
	Pos.bottom = Pos.top + 20;
}

void EndFloor::Move(int Move_Dir, float m_fDeltaTime)
{
	Pos.left += Move_Dir * m_fDeltaTime;
	Pos.right += Move_Dir * m_fDeltaTime;
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
