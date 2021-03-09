#include "Player.h"


#pragma region ������ ����
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
		//�� ����
		y = 6;
		Piece[x + 8]->SetPos(x, y);

		//�׿�
		y = 7;
		Piece[x]->SetPos(x, y);
	}
}


void Player::SetPos_Black()
{
	int y;
	for (int x = 0; x < PIECECOUNT/2; x++)
	{
		//�� ����
		y = 1;
		Piece[x + 8]->SetPos(x, y);


		//�׿�
		y = 0;
		Piece[x]->SetPos(x, y);
	}
}
#pragma endregion

#pragma region Ŭ���̺�Ʈ

bool Player::Piece_Click(POINT mouse, Piece_info* info, bool* isClick)
{
	POINT Check_Pos;
	for (int i = 0; i < PIECECOUNT; i++)
	{
		Check_Pos = Piece[i]->Return_Pos();
		if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y) //���콺 Ŭ�� ��ġ�� �ǽ� �ִ��� Ž��
		{
			//GameManager�ǽ� ���� ����
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
		if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y //���콺 Ŭ�� ��ġ�� �ǽ� �ִ���
			&&info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)  //������ Ŭ���ߴ� �ǽ��� Ŭ���ߴ��� Ž��
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

	//�̹� Ŭ���� �ǽ��� �ִ� ������� ���� üũ
	if (*isClick)	//�̹� Ŭ���� �ǽ��� �ִ� ���
	{
		if (0)	//�̵������� ������� üũ
		{
			//true 
		//�̵�
		//�浹üũ
		//�̵������� ��ǥ ����
			*isClick = false;
			info->PieceNumber = -1;
			return true;
		}
		else
		{
			for (int i = 0; i < PIECECOUNT; i++)
			{
				Check_Pos = Piece[i]->Return_Pos();
				if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y //���콺 Ŭ�� ��ġ�� �ǽ� �ִ���
					&&info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)  //������ Ŭ���ߴ� �ǽ��� Ŭ���ߴ��� Ž��
				{
					*isClick = false;
					info->PieceNumber = -1;
					return true;
				}
			}

			return false;
		}
	}
	else	//�̹� Ŭ���� �ǽ��� ���� ���
	{
		for (int i = 0; i < PIECECOUNT; i++)
		{
			Check_Pos = Piece[i]->Return_Pos();
			if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y) //���콺 Ŭ�� ��ġ�� �ǽ� �ִ��� Ž��
			{
				//GameManager�ǽ� ���� ����
				Piece[i]->isClick(true);
				info->isBlack = IsBlack;
				info->PieceNumber = i;
				*isClick = true;

				//�̵������� ��ǥ ǥ��


				return true;
			}
		}

		//���þ��� ��ǥ�� ������ 
		return false;

	}
	//for (int i = 0; i < PIECECOUNT; i++)
	//{
	//	Check_Pos = Piece[i]->Return_Pos();
	//	
	//	if (Check_Pos.x = mouse.x && Check_Pos.y == mouse.y)//���콺 Ŭ�� ��ġ�� �ǽ� �ִ��� Ž��
	//	{
	//		if (*isClick)//�̹� Ŭ���� �ǽ��� �ִ� ���
	//		{
	//			if (info->isBlack == Piece[i]->Return_isBlack() && info->PieceNumber == i)//������ �����ߴ� �ǽ��� Ŭ������ ���
	//			{
	//				//Ŭ�� ���
	//				Piece[i]->isClick(false);
	//
	//				//�̵������� ��ǥ ����
	//				*isClick = false;
	//				info->PieceNumber = -1;
	//
	//				return true;
	//			}
	//			else//������ �����ߴ� �ǽ��� Ŭ������ �ʾ��� ���
	//			{
	//				//�̵������� ��ǥ�� Ŭ���� ���
	//					//�̵�
	//			
	//				//�̵������� ��ǥ�� Ŭ������ ���� ���
	//					//����
	//
	//
	//				return false;
	//			}
	//		}
	//		else//�̹� Ŭ���� �ǽ��� ���� ���
	//		{
	//			//GameManager�ǽ� ���� ����
	//			Piece[i]->isClick(true);
	//			info->isBlack = IsBlack;
	//			info->PieceNumber = i;
	//			*isClick = true;
	//
	//			//�̵������� ��ǥ ǥ��
	//			
	//
	//			return true;
	//		}
	//	}
	//}
	//return false; //Ž������
}



#pragma endregion


void Player::Draw(HDC hdc)
{
	for (int i = 0; i < PIECECOUNT; i++)
	{
		Piece[i]->Draw(hdc);
	}

}