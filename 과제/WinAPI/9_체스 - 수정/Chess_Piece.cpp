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