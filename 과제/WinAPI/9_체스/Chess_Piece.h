#pragma once
#include  "SpriteManager.h"
class Chess_Piece
{
private:

public:

	void Erase();
	void Die();

	virtual void SetPiece(int name, bool isBlack) = 0;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Change() = 0;

};

