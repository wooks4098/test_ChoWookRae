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

#pragma region 클릭이벤트
bool GameManager::MouseClick(HDC hdc, HWND hWnd, POINT mouse)
{
	mouse = MousePointChange(mouse);

	//순서에 따라 관리해주는 코드 추가

	if (ClickPiece)//클릭한 피스가 있음
	{
		//해당 피스를 다시 클랙했는가?
		if (player[TurnCheck()].Piece_Click_AgainCheck(mouse, &ClickPiece_info, &ClickPiece, &CanMove_Pos))
		{
			CanMove_Pos.clear();
			return false;

		}
		//이동가능한 좌표를 클릭했는가?
		if (MouseClick_CanMovePos(mouse))
		{

			POINT pos;
			pos = player[TurnCheck()].Return_Piece_Pos(ClickPiece_info.PieceNumber);
			//이동
			player[TurnCheck()].Piece_Move(hWnd, mouse, ClickPiece_info);
			
			//충돌체크
			if (Piece_Pos[mouse.y][mouse.x].PieceNumber != -1)
			{
				if (player[Piece_Pos[mouse.y][mouse.x].isBlack].Piece_Die(mouse, Piece_Pos))
				{
					//종료
					Win(hWnd);
					return true;
				}
			}

			//피스정보 저장
			Piece_Pos[mouse.y][mouse.x].isBlack= Piece_Pos[pos.y][pos.x].isBlack;
			Piece_Pos[mouse.y][mouse.x].PieceNumber= Piece_Pos[pos.y][pos.x].PieceNumber;
			//이동한 피스 위치 제거
			Piece_Pos[pos.y][pos.x].PieceNumber = -1;

			Trun++;
			ClickPiece_info.PieceNumber = -1;
			CanMove_Pos.clear();
			ClickPiece = false;
		}
		//else


	}
	else//클릭한 피스가 없음
	{
		//피스선택
		if (player[TurnCheck()].Piece_Click(mouse, &ClickPiece_info, &ClickPiece))
		{
			////이동가능한 좌표 탐색 후 표시
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
		(MessageBox(hWnd, TEXT("흑 승리"), TEXT("체스"), MB_OK));
	}
	else
	{
		(MessageBox(hWnd, TEXT("백 승리"), TEXT("체스"), MB_OK));
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