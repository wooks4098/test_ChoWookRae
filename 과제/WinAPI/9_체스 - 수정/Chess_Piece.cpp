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

void King::Move()
{

}

void King::Change()
{

}
void King::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{

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


void Queen::Move()
{

}

void Queen::Change()
{

}
void Queen::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{

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

void Knight::Move()
{

}

void Knight::Change()
{

}
void Knight::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{

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
void Bishop::Move()
{

}

void Bishop::Change()
{

}
void Bishop::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{

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


void Rook::Move()
{

}

void Rook::Change()
{

}
void Rook::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{

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

void Pawn::Move()
{

}

void Pawn::Change()
{

}

void Pawn:: CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	//앞 2칸 && 앞 대각선 검은피스 있을 경우
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
			}
			
		}
		else
		{
			//y+1
			Pos.y++;
			if(Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //( Pos.x <0 || Pos.x>8)  && 
				CanMove_Pos->push_back(Pos);
			//x-1 y+1
			Pos.x--;
			if(Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
				CanMove_Pos->push_back(Pos);

			// x+1 y+1
			Pos.x += 2;
			if (Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
				CanMove_Pos->push_back(Pos);
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
			}
		}
		else
		{
			//y-1
			Pos.y--;
			if ( Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
				CanMove_Pos->push_back(Pos);
			//x-1 y-1
			Pos.x--;
			if (Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
				CanMove_Pos->push_back(Pos);

			// x+1 y-1
			Pos.x += 2;
			if (Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
				CanMove_Pos->push_back(Pos);
		}


	
	}
}