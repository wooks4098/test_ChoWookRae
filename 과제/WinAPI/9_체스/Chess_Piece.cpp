#include "Chess_Piece.h"


//Piece
void Chess_Piece::Draw(HDC hdc, float x, float y, float spX, float spY)
{
	SpriteManager::GetInstans()->Draw(hdc, x, y, spX, spY, m_name, true);
}


//king

King::King(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void King::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
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
}

void Pawn::Move()
{

}

void Pawn::Change()
{

}