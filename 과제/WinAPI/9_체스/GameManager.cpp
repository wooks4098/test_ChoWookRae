#include "GameManager.h"

void GameManager::SetData()
{
	ClickPiece = false;
	Trun = 0;
	player[BLACK].SetData_Black();
	player[WHITE].SetData_White();
}

void GameManager::Draw(HDC hdc)
{
	Map::GetInstans()->MapDraw(hdc);

	for (int i = 0; i < 2; i++)
		player[i].Draw(hdc);
}


void GameManager::MouseClick(POINT mouse)
{
	mouse = MousePointChange(mouse);
	if (ClickPiece)
	{
		ClickPiece = false;
	}
	else
	{
		ClickPiece = true;
	}

}

POINT GameManager::MousePointChange(POINT mouse)
{
	mouse.x = (mouse.x - 20)/WIDTH;
	mouse.y = (mouse.y - 20)/HEIGHT;
	return mouse;
}

int GameManager::TurnCheck()
{
	if (Trun % 2 == 0)
		return WHITE;
	else
		return BLACK;
}