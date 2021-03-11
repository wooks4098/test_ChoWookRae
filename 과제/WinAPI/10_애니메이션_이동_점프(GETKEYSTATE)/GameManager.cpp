#include "GameManager.h"



GameManager::GameManager()
{
	Count = 0;
	Frame = 0;
	Pos.x = 100;
	Pos.y = 100;
	isJump = false;
	JumpTimer = 0;
}

void GameManager::SetData(HWND hWnd)
{
	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);
	wsprintf(buf, L"image.bmp");
	bit.CreatImage(hdc, buf);
}

void GameManager::GetKey()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		Pos.x -= 10;
		Direction = DIR_LEFT;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		Pos.x += 10;
		Direction = DIR_RIGHT;
	}
	if (GetKeyState(VK_UP) & 0x8000 && !isJump)
	{
		Pos.y -= 10;
		Direction = DIR_UP;
	}
	if (GetKeyState(VK_DOWN) & 0x8000 && !isJump)
	{
		Pos.y += 10;
		Direction = DIR_Down;
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		isJump = true;
		Jump_y = Pos.y;
		JumpTimer = 0;
	}

	//애니메이션
	Count++;
	if (Count >= 10)
	{
		Frame++;
		if (Frame >= 4)
		{
			Frame = 0;
		}
		Count = 0;
	}

	//점프
	//
	if (isJump)
	{
		JumpTimer++;
		if (JumpTimer > 30)
		{
			isJump = false;
			return;

		}
		Jump_y = 10 * cos( M_PI / 30 * JumpTimer);
		Pos.y -= Jump_y;
	}

}
void GameManager::Animation(HDC hdc)
{
	bit.Draw(hdc, Pos.x, Pos.y, Frame, Direction);
}
GameManager::~GameManager()
{
}
