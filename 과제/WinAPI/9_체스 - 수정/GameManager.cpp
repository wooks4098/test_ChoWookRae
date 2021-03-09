#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;
void GameManager::SetData()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
			Piece_Pos[y][x].PieceNumber = -1;
	}
	ClickPiece = false;
	ClickPiece_info.PieceNumber = -1;
	Trun = 0;
	player[BLACK].SetData_Black();
	player[WHITE].SetData_White();	
}

void GameManager::Draw(HDC hdc)
{
	Map::GetInstans()->MapDraw(hdc,CanMove_Pos);

	for (int i = 0; i < 2; i++)
		player[i].Draw(hdc);
}

#pragma region Ŭ���̺�Ʈ
void GameManager::MouseClick(HDC hdc, POINT mouse)
{
	mouse = MousePointChange(mouse);

	

	if (ClickPiece)//Ŭ���� �ǽ��� ����
	{
		//�ش� �ǽ��� �ٽ� Ŭ���ߴ°�?
		for (int i = 0; i < 2; i++)
		{
			if (player[i].Piece_Click_AgainCheck(mouse, &ClickPiece_info, &ClickPiece))
			{
				CanMove_Pos.clear();
				return;

			}

		}
		//�̵������� ��ǥ�� Ŭ���ߴ°�?

		//else


	}
	else//Ŭ���� �ǽ��� ����
	{
		//�ǽ�����
		for (int i = 0; i < 2; i++)
		{
			if (player[i].Piece_Click(mouse, &ClickPiece_info, &ClickPiece))
			{
				//�̵������� ��ǥ Ž�� �� ǥ��
				for (int i = 0; i < 2; i++)
					player[i].Get_Piece_info(Piece_Pos);
				player[ClickPiece_info.isBlack].Piece_Can_Move_Search(ClickPiece_info, &CanMove_Pos, Piece_Pos);
				Map::GetInstans()->Draw_CanMovePos(hdc, CanMove_Pos);
				return;
			}

		}
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