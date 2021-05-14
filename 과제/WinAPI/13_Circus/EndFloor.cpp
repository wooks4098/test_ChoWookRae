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

	Pos.left += (Move_Dir * Player_Speed);
	Pos.right += (Move_Dir * Player_Speed);
	//if (Move_Dir > 0)
	//{
	//	if (Pos.left <= 450)
	//	{
	//		Pos.left = 450;
	//		Pos.right = Pos.left + 100;
	//		return;

	//	}
	//}
	
}
bool EndFloor::HitCheck(RECT Player_Rect)
{
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
