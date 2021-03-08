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

#pragma region Ŭ���̺�Ʈ
void GameManager::MouseClick(POINT mouse)
{
	mouse = MousePointChange(mouse);

	for (int i = 0; i < 2; i++)
	{
		if (player[i].PieceCheck(mouse, &ClickPiece_info, &ClickPiece))
			return;
	}

	if (ClickPiece)//Ŭ���� �ǽ��� ����
	{
		//�ش� �ǽ��� �ٽ� Ŭ���ߴ°�?

		//�̵������� ��ǥ�� Ŭ���ߴ°�?

		//else


	}
	else//Ŭ���� �ǽ��� ����
	{
		//�ǽ��� Ŭ���ߴ°�?

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