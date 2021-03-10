#pragma once
#include  "SpriteManager.h"
#include "Map.h"
//#include "GameManager.h"

class Chess_Piece
{
protected:
	int m_name;
	POINT m_Pos;
	bool m_isBlack;
	bool m_isClick;


public:
	virtual void SetPiece(int name, bool isBlack) = 0;
	virtual bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]) = 0; //이동가능한 탐색

	virtual int Change(HWND hWnd);

	void Move(POINT mouse);
	void Erase();
	void Die();
	void Draw(HDC hdc);
	void SetPos(int x, int y);
	void isClick(bool check);

	int Return_PieceName();
	bool Return_isBlack();
	POINT Return_Pos();
};

class King : public Chess_Piece
{

public:
	King(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);
};


class Queen : public Chess_Piece
{

public:
	Queen(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);
};

class Knight : public Chess_Piece
{

public:
	Knight(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);
};

class Bishop : public Chess_Piece
{

public:
	Bishop(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);

};

class Rook : public Chess_Piece
{

public:
	Rook(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);
};

class Pawn : public Chess_Piece
{

public:

	Pawn(int name, bool isBlack);
	void SetPiece(int name, bool isBlack);
	int Change(HWND hWnd);
	bool CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8]);
};
