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
	Pos.bottom = Pos.top + 20;
	isJump = false;
	JumpCount = 0;
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
		Pos.bottom = Pos.top + 20;
		if (JumpCount > 1)
		{
			isJump = false;
			JumpCount = 0;
			Player_State = PLAYERSTATE_RUN;
		}
	}
}

void Player::Move(int Move_Dir,float m_fDeltaTime)
{
 	if (Pos.right >= 536 && Move_Dir > 0)
		return;
	Pos.left += Move_Dir* m_fDeltaTime;
	Pos.right += Move_Dir * m_fDeltaTime;
}

void Player::Draw(HDC hdc, float m_fDeltaTime)
{
	//time++;
	time += m_fDeltaTime;
	switch (Player_State)
	{
	case PLAYERSTATE_RUN:
		if (time >= 0.1)
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
		if (time >= 0.1)
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
