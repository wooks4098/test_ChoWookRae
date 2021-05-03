#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
enum PLAYERSTATE
{
	PLAYERSTATE_RUN,
	PLAYERSTATE_JUMP,
	PLAYERSTATE_CLEAR,
	PLAYERSTATE_DIE,
};

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
	RECT Return_PlayerRect() { return Pos; }
	~Player();
};

