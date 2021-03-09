#include "Chess_Piece.h"


//Piece
void Chess_Piece::Draw(HDC hdc)
{
	SpriteManager::GetInstans()->Draw(hdc, 20 + m_Pos.x * WIDTH, 20 + m_Pos.y * HEIGHT, WIDTH, HEIGHT, m_name, true);
}
void Chess_Piece::SetPos(int x, int y)
{
	m_Pos.x = x;
	m_Pos.y = y;

}

void Chess_Piece::isClick(bool check)
{
	m_isClick = check;
}

void Chess_Piece::Move(POINT mouse)
{
	m_Pos = mouse;
}

#pragma region Return
bool Chess_Piece::Return_isBlack()
{
	return m_isBlack;
}

POINT Chess_Piece::Return_Pos()
{
	return m_Pos;
}

#pragma endregion



//king

King::King(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void King::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


void King::Change()
{

}
bool King::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	return false;
}

//Queen

Queen::Queen(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Queen::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


void Queen::Change()
{

}
bool Queen::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	return false;
}
//Knight

Knight::Knight(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Knight::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


void Knight::Change()
{

}
bool Knight::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	return false;

}
//Bishop

Bishop::Bishop(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Bishop::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}

void Bishop::Change()
{

}
bool Bishop::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	return false;
}
//Rook

Rook::Rook(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Rook::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


void Rook::Change()
{

}
bool Rook::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;
	Pos = m_Pos;
	//→ x++
	for (int i = 0; i < 8; i++)
	{
		Pos.x++;
		if (Pos.x > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 ||		//피스가 없거나
			(Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)	)	//다른피스가 있거나
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
	}
	//← x--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.x--;
		if (Pos.x < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 ||		//피스가 없거나
			(Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))	//다른피스가 있거나
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}


	}
	//↑ y--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y--;
		if (Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1)
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		//if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 ||		//피스가 없거나
		//	(Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))	//다른피스가 있거나
		//{
		//	CanMove_Pos->push_back(Pos);
		//	CanMove = true;
		//	break;
		//}


	}

	//↓ y++
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y++;
		if (Pos.y > 7)
			break;

		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 ||		//피스가 없거나
			(Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))	//다른피스가 있거나
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}

	}
	return false;
}

//Pawn

Pawn::Pawn(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Pawn::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}

void Pawn::Change()
{

}

bool Pawn:: CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	
	//앞 2칸 && 앞 대각선 검은피스 있을 경우
	bool CanMove = false;
	POINT Pos;
	Pos = m_Pos;
	if (m_isBlack)//검은색인 경우
	{
		if (m_Pos.y == 1)//처음위치일 경우
		{
			//y+1 y+2			
			for (int i = 0; i < 2; i++)
			{
				Pos.y++;
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
			
		}
		else
		{
			//y+1
			Pos.y++;
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1)
			{
				CanMove_Pos->push_back(Pos); 
				CanMove = true;

			}
			//x-1 y+1
			Pos.x--;
			if (Pos.x >= 0 &&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
			// x+1 y+1
			Pos.x += 2;
			if (Pos.x <= 7 && Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		
	}
	else//흰색인 경우
	{
		if (m_Pos.y == 6)//처음위치일 경우
		{
			//y-1  y -2
			for (int i = 0; i < 2; i++)
			{
				Pos.y--;
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		else
		{
			//y-1
			Pos.y--;
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;

			}
			//x-1 y-1
			Pos.x--;
			if (Pos.x >= 0&&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}

			// x+1 y-1
			Pos.x += 2;
			if (Pos.x<= 7 &&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;

			}
		}


	
	}
	return CanMove;
}