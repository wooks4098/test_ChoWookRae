#pragma once
#include  "SpriteManager.h"
class Chess_Piece
{
private:

public:
	virtual void Move() = 0;
	virtual void Draw() = 0;
	void Erase();
	void Die();
	virtual void Change() = 0;

};

