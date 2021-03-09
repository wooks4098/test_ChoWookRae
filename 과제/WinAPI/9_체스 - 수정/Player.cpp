#include "Player.h"


#pragma region 데이터 세팅
void Player::SetData_White()
{
	IsBlack = WHITE;
	SetPiece_Data_White();
	SetPos_White();
}

void Player::SetData_Black()
{
	IsBlack = BLACK;
	SetPiece_Data_Black();
	SetPos_Black();
}


void Player::SetPiece_Data_White()
{
	for (int i = 0; i < PIECECOUNT; i++)
	{
		switch (i)
		{
		case Piece_KING:
			Piece[i] = new King(SPRITE_W_KING, false);
			break;
		case Piece_QUEEN:
			Piece[i] = new Queen(SPRITE_W_QUEEN, false);
			break;
		case Piece_KNIGHT_0:
		case Piece_KNIGHT_1:
			Piece[i] = new Knight(SPRITE_W_BISHOP, false);
			break;
		case Piece_BISHOP_0:
		case Piece_BISHOP_1:
			Piece[i] = new Bishop(SPRITE_W_KNIGHT, false);
			break;
		case Piece_ROOK_0:
		case Piece_ROOK_1:
			Piece[i] = new Rook(SPRITE_W_ROOK, false);
			break;
		case Piece_PAWN_0:
		case Piece_PAWN_1:
		case Piece_PAWN_2:
		case Piece_PAWN_3:
		case Piece_PAWN_4:
		case Piece_PAWN_5:
		case Piece_PAWN_6:
		case Piece_PAWN_7:
			Piece[i] = new Pawn(SPRITE_W_PAWN, false);
			break;
		}
	}

}

void Player::SetPiece_Data_Black()
{
	for (int i = 0; i < PIECECOUNT; i++)
	{
		switch (i)
		{
		case Piece_KING:
			Piece[i] = new King(SPRITE_B_KING, true);
			break;
		case Piece_QUEEN:
			Piece[i] = new Queen(SPRITE_B_QUEEN, true);
			break;
		case Piece_KNIGHT_0:
		case Piece_KNIGHT_1:
			Piece[i] = new Knight(SPRITE_B_BISHOP, true);
			break;
		case Piece_BISHOP_0:
		case Piece_BISHOP_1:
			Piece[i] = new Bishop(SPRITE_B_KNIGHT, true);
			break;
		case Piece_ROOK_0:
		case Piece_ROOK_1:
			Piece[i] = new Rook(SPRITE_B_ROOK, true);
			break;
		case Piece_PAWN_0:
		case Piece_PAWN_1:
		case Piece_PAWN_2:
		case Piece_PAWN_3:
		case Piece_PAWN_4:
		case Piece_PAWN_5:
		case Piece_PAWN_6:
		case Piece_PAWN_7:
			Piece[i] = new Pawn(SPRITE_B_PAWN, true);
			break;
		}
	}
}


void Player::SetPos_White()
{
	int y;
	for (int x = 0; x < PIECECOUNT/2; x++)
	{
		//폰 세팅
		y = 6;
		Piece[x + 8]->SetPos(x, y);

		//그외
		y = 7;
		Piece[x]->SetPos(x, y);
	}
}


void Player::SetPos_Black()
{
	int y;
	for (int x = 0; x < PIECECOUNT/2; x++)
	{
		//폰 세팅
		y = 1;
		Piece[x + 8]->SetPos(x, y);


		//그외
		y = 0;
		Piece[x]->SetPos(x, y);
	}
}
#pragma endregion

#pragma region 클릭이벤트

bool Player::Piece_Click(POINT mouse, Piece_info* info, bool* isClick)
{
	POINT Check_Pos;
	for (int i = 0; i < PIECECOUNT; i++)
	{
		Check_Pos = Piece[i]->Return_Pos();
		if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y) //마우스 클릭 위치에 피스 있는지 탐색
		{
			//GameManager피스 정보 저장
			Piece[i]->isClick(true);
			info->isBlack = IsBlack;
			info->PieceNumber = i;
			*isClick = true;
			return true;
		}
	}
}

bool Player::Piece_Click_AgainCheck(POINT mouse, Piece_info* info, bool* isClick)
{
	POINT Check_Pos;
	for (int i = 0; i < PIECECOUNT; i++)
	{
		Check_Pos = Piece[i]->Return_Pos();
		if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y //마우스 클릭 위치에 피스 있는지
			&&info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)  //이전에 클릭했던 피스를 클릭했는지 탐색
		{
			*isClick = false;
			info->PieceNumber = -1;
			return true;
		}
	}
	return false;
}

void Player::Piece_Can_Move_Search(Piece_info info, std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	CanMove_Pos->clear();
	Piece[info.PieceNumber]->CanMovePos(CanMove_Pos, Piece_Pos);
	
}
void Player::Get_Piece_info(Piece_info Piece_Pos[][8])
{
	POINT Pos;
	for (int i = 0; i < PIECECOUNT; i++)
	{
		if (Piece[i] != NULL)
		{
			Pos = Piece[i]->Return_Pos();
			Piece_Pos[Pos.y][Pos.x].isBlack = Piece[i]->Return_isBlack();
			Piece_Pos[Pos.y][Pos.x].PieceNumber = i;
		}
	}
}




bool Player::PieceCheck(POINT mouse, Piece_info* info, bool* isClick)
{
	POINT Check_Pos;

	//이미 클릭한 피스가 있는 경우인지 부터 체크
	if (*isClick)	//이미 클릭한 피스가 있는 경우
	{
		if (0)	//이동가능한 경로인지 체크
		{
			//true 
		//이동
		//충돌체크
		//이동가능한 좌표 제거
			*isClick = false;
			info->PieceNumber = -1;
			return true;
		}
		else
		{
			for (int i = 0; i < PIECECOUNT; i++)
			{
				Check_Pos = Piece[i]->Return_Pos();
				if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y //마우스 클릭 위치에 피스 있는지
					&&info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)  //이전에 클릭했던 피스를 클릭했는지 탐색
				{
					*isClick = false;
					info->PieceNumber = -1;
					return true;
				}
			}

			return false;
		}
	}
	else	//이미 클릭한 피스가 없는 경우
	{
		for (int i = 0; i < PIECECOUNT; i++)
		{
			Check_Pos = Piece[i]->Return_Pos();
			if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y) //마우스 클릭 위치에 피스 있는지 탐색
			{
				//GameManager피스 정보 저장
				Piece[i]->isClick(true);
				info->isBlack = IsBlack;
				info->PieceNumber = i;
				*isClick = true;

				//이동가능한 좌표 표시


				return true;
			}
		}

		//관련없는 좌표를 눌렀때 
		return false;

	}
	//for (int i = 0; i < PIECECOUNT; i++)
	//{
	//	Check_Pos = Piece[i]->Return_Pos();
	//	
	//	if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y)//마우스 클릭 위치에 피스 있는지 탐색
	//	{
	//		if (*isClick)//이미 클릭한 피스가 있는 경우
	//		{
	//			if (info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)//이전에 선택했던 피스를 클릭했을 경우
	//			{
	//				//클릭 취소
	//				Piece[i]->isClick(false);
	//
	//				//이동가능한 좌표 제거
	//				*isClick = false;
	//				info->PieceNumber = -1;
	//
	//				return true;
	//			}
	//			else//이전에 선택했던 피스를 클릭하지 않았을 경우
	//			{
	//				//이동가능한 좌표를 클릭한 경우
	//					//이동
	//			
	//				//이동가능한 좌표를 클릭하지 않은 경우
	//					//무시
	//
	//
	//				return false;
	//			}
	//		}
	//		else//이미 클릭한 피스가 없는 경우
	//		{
	//			//GameManager피스 정보 저장
	//			Piece[i]->isClick(true);
	//			info->isBlack = IsBlack;
	//			info->PieceNumber = i;
	//			*isClick = true;
	//
	//			//이동가능한 좌표 표시
	//			
	//
	//			return true;
	//		}
	//	}
	//}
	//return false; //탐색실패
}



#pragma endregion


void Player::Draw(HDC hdc)
{
	for (int i = 0; i < PIECECOUNT; i++)
	{
		Piece[i]->Draw(hdc);
	}

}