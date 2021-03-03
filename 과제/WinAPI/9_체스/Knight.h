#pragma once
#include "Chess_Piece.h"
class Knight : public Chess_Piece
{
private:
	int m_name;
	bool m_isBlack;
public:
	void SetPiece(int name, bool isBlack);
	void Move();
	void Draw();
	void Change();
};

