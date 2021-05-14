#pragma once
#include "Mecro.h"
#include "BitMapManager.h"


class Player
{
private:
	int Player_State;
	RECT Pos;
	float time;
	int ClearFrame;
	int RunFrame;
	bool isJump;
	int Jump_y;
	float JumpCount;
public:
	Player();
	void Draw(HDC hdc, float m_fDeltaTime);
	void Move(int Move_Dir, float m_fDeltaTime);
	void Jump(float Time);
	void StartJump();
	void Hit_EndFloor(RECT end_Rect);
	void Change_State(int _state);
	void Reset();

	RECT Return_PlayerRect() { return Pos; }
	int Return_PlayerState() { return Player_State; };
	~Player();
};

