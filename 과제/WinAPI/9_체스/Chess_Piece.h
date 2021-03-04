#pragma once
#include  "SpriteManager.h"
class Chess_Piece
{
protected:
	int m_name;
	bool m_isBlack;
public:

	void Erase();
	void Die();
	void Draw(HDC hdc, float x, float y, float spX, float spY);

	virtual void SetPiece(int name, bool isBlack) = 0;
	virtual void Move() = 0;
	virtual void Change() = 0;

};

class King : public Chess_Piece
{

public:
	King(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();
};


class Queen : public Chess_Piece
{

public:
	Queen(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();
};

class Knight : public Chess_Piece
{

public:
	Knight(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();
};

class Bishop : public Chess_Piece
{

public:
	Bishop(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();

};

class Rook : public Chess_Piece
{

public:
	Rook(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();
};

class Pawn : public Chess_Piece
{

public:
	Pawn(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	void Move();
	void Change();
};
