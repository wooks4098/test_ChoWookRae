#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;
void GameManager::SetData()
{
	ClickPiece = false;
	ClickPiece_info.PieceNumber = -1;
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

#pragma region 클릭이벤트
void GameManager::MouseClick(POINT mouse)
{
	mouse = MousePointChange(mouse);

	for (int i = 0; i < 2; i++)
	{
		if (player[i].PieceCheck(mouse, &ClickPiece_info, &ClickPiece))
			return;
	}

	if (ClickPiece)//클릭한 피스가 있음
	{
		//해당 피스를 다시 클랙했는가?

		//이동가능한 좌표를 클릭했는가?

		//else


	}
	else//클릭한 피스가 없음
	{
		//피스를 클릭했는가?

		//else
	}

}

POINT GameManager::MousePointChange(POINT mouse)
{
	mouse.x = (mouse.x - 20) / WIDTH;
	mouse.y = (mouse.y - 20) / HEIGHT;
	return mouse;
}

void GameManager::PieceCheck(POINT mouse)
{
	for (int i = 0; i < 2; i++)
	{
		ClickPiece = player[i].PieceCheck(mouse, &ClickPiece_info, &ClickPiece);
		if (ClickPiece)
			return;
	}
}

#pragma endregion






int GameManager::TurnCheck()
{
	if (Trun % 2 == 0)
		return WHITE;
	else
		return BLACK;
}