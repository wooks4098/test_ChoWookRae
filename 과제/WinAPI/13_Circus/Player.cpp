#include "Player.h"



Player::Player()
{
	Player_State = PLAYERSTATE_RUN;
	time = 0;
	ClearFrame = BITMAP_WIN;
	RunFrame = BITMAP_PLAYER0;
	Pos.left = 0;
	Pos.top = 280;
	Pos.right = Pos.left + 66;
	Pos.bottom = Pos.top + 63;
	isJump = false;
}

void Player::Move(DWORD Time)
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		Pos.left -= 1;
		Pos.right -= 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		Pos.left += 1;
		Pos.right += 1;
	}

	if (!isJump&&GetKeyState(VK_SPACE) & 0x8000)
	{
		isJump = true;
		Jump_y = 280;
		JumpCount = 0;
	}


	//����7
	//
	if (isJump)
	{
		if (time % 6 != 0)
			return;
		JumpCount++;

		Pos.top -= cos(M_PI / 1000 * JumpCount);
		Pos.top = Jump_y -
			sinf(0.02f * JumpCount * M_PI) * 100;
		if (JumpCount >= 50)
		{
			isJump = false;
		}
	}
}

void Player::Draw(HDC hdc, DWORD G_time)
{
	time++;
	switch (Player_State)
	{
	case PLAYERSTATE_RUN:
		if (time >= 100)
		{
			RunFrame++;
			time = 0;
			if (RunFrame >= BITMAP_PLAYER2)
				RunFrame = BITMAP_PLAYER0;
		}
		BitMapManager::GetInstans()->Draw(hdc, Pos, RunFrame);
		break;
	case PLAYERSTATE_JUMP:
		BitMapManager::GetInstans()->Draw(hdc, Pos, BITMAP_DIE);
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
