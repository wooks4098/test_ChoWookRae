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
	for (int i = 0; i < 2; i++)
		player[i].Get_Piece_info(Piece_Pos);
}

void GameManager::Draw(HDC hdc)
{
	Map::GetInstans()->MapDraw(hdc,CanMove_Pos);

	for (int i = 0; i < 2; i++)
		player[i].Draw(hdc);
}

#pragma region Ŭ���̺�Ʈ
bool GameManager::MouseClick(HDC hdc, HWND hWnd, POINT mouse)
{
	mouse = MousePointChange(mouse);

	//������ ���� �������ִ� �ڵ� �߰�

	if (ClickPiece)//Ŭ���� �ǽ��� ����
	{
		//�ش� �ǽ��� �ٽ� Ŭ���ߴ°�?
		if (player[TurnCheck()].Piece_Click_AgainCheck(mouse, &ClickPiece_info, &ClickPiece, &CanMove_Pos))
		{
			CanMove_Pos.clear();
			return false;

		}
		//�̵������� ��ǥ�� Ŭ���ߴ°�?
		if (MouseClick_CanMovePos(mouse))
		{

			POINT pos;
			pos = player[TurnCheck()].Return_Piece_Pos(ClickPiece_info.PieceNumber);
			//�̵�
			player[TurnCheck()].Piece_Move(hWnd, mouse, ClickPiece_info);
			
			//�浹üũ
			if (Piece_Pos[mouse.y][mouse.x].PieceNumber != -1)
			{
				if (player[Piece_Pos[mouse.y][mouse.x].isBlack].Piece_Die(mouse, Piece_Pos))
				{
					//����
					Win(hWnd);
					return true;
				}
			}

			//�ǽ����� ����
			Piece_Pos[mouse.y][mouse.x].isBlack= Piece_Pos[pos.y][pos.x].isBlack;
			Piece_Pos[mouse.y][mouse.x].PieceNumber= Piece_Pos[pos.y][pos.x].PieceNumber;
			//�̵��� �ǽ� ��ġ ����
			Piece_Pos[pos.y][pos.x].PieceNumber = -1;

			Trun++;
			ClickPiece_info.PieceNumber = -1;
			CanMove_Pos.clear();
			ClickPiece = false;
		}
		//else


	}
	else//Ŭ���� �ǽ��� ����
	{
		//�ǽ�����
		if (player[TurnCheck()].Piece_Click(mouse, &ClickPiece_info, &ClickPiece))
		{
			////�̵������� ��ǥ Ž�� �� ǥ��
			if (!player[ClickPiece_info.isBlack].Piece_Can_Move_Search(ClickPiece_info, &CanMove_Pos, Piece_Pos))
			{
				ClickPiece_info.PieceNumber = -1;
				CanMove_Pos.clear();
				ClickPiece = false;
			}
			return false;
		}
	}
	return false;
}

void GameManager::Win(HWND hWnd)
{
	InvalidateRect(hWnd, NULL, TRUE);
	CanMove_Pos.clear();
	if (TurnCheck() == BLACK)
	{
		(MessageBox(hWnd, TEXT("�� �¸�"), TEXT("ü��"), MB_OK));
	}
	else
	{
		(MessageBox(hWnd, TEXT("�� �¸�"), TEXT("ü��"), MB_OK));
	}
}


bool GameManager::MouseClick_CanMovePos(POINT mouse)
{
	std::vector<POINT>::iterator iter;
	for (iter = CanMove_Pos.begin(); iter != CanMove_Pos.end(); ++iter)
	{
		if (mouse.x == iter->x && mouse.y == iter->y)
			return true;
	}
	return false;
}

POINT GameManager::MousePointChange(POINT mouse)
{
	mouse.x = (mouse.x - 20) / WIDTH;
	mouse.y = (mouse.y - 20) / HEIGHT;
	return mouse;
}

//void GameManager::PieceCheck(POINT mouse)
//{
//	for (int i = 0; i < 2; i++)
//	{
//		ClickPiece = player[i].PieceCheck(mouse, &ClickPiece_info, &ClickPiece);
//		if (ClickPiece)
//			return;
//	}
//}

#pragma endregion






int GameManager::TurnCheck()
{
	if (Trun % 2 == 0)
		return WHITE;
	else
		return BLACK;
}