#include "Player.h"



Player::Player()
{
	Player_State = PLAYERSTATE_RUN;
	time = 0;
	ClearFrame = BITMAP_WIN;
	RunFrame = BITMAP_PLAYER0;
	Pos.left = 50;
	Pos.top = 280;
	Pos.right = Pos.left + 66;
	Pos.bottom = Pos.top + 63;
	isJump = false;
}
void Player::StartJump()
{
	if (isJump)
		return;

	isJump = true;
	Jump_y = 280;
	Player_State = PLAYERSTATE_JUMP;
}

void Player::Jump(float Time)
{
	if (isJump)
	{
		JumpCount += Time;
		Pos.top = Jump_y - sinf(JumpCount * M_PI) * 100;
		if (JumpCount > 1)
		{
			isJump = false;
			JumpCount = 0;
			Player_State = PLAYERSTATE_RUN;
		}
	}
}

void Player::Move(int Move_Dir,float Time)
{
	Pos.left += Move_Dir;
	Pos.right += Move_Dir;
	

	

	
}

void Player::Draw(HDC hdc, float G_time)
{
	time++;
	switch (Player_State)
	{
	case PLAYERSTATE_RUN:
		if (time >= 30)
		{
			RunFrame++;
			time = 0;
			if (RunFrame >= BITMAP_PLAYER2)
				RunFrame = BITMAP_PLAYER0;
		}
		BitMapManager::GetInstans()->Draw(hdc, Pos, RunFrame);
		break;
	case PLAYERSTATE_JUMP:
		BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_PLAYER2);
		break;
	case PLAYERSTATE_CLEAR:
		if (time >= 100)
		{
			ClearFrame++;
			time = 0;
			if (ClearFrame >= BITMAP_WIN2)
				ClearFrame = BITMAP_WIN;
		}
		BitMapManager::GetInstans()->Draw(hdc, Pos, ClearFrame);
		break;
	case PLAYERSTATE_DIE:
		BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_DIE);
		break;
	}
}

Player::~Player()
{
}
