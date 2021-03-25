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
	DWORD time;
	int ClearFrame;
	int RunFrame;
	bool isJump;
	int Jump_y;
	DWORD JumpCount;
public:
	Player();
	void Draw(HDC hdc,DWORD G_time);
	void Move(DWORD Time);
	~Player();
};

