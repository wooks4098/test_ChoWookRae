#include "GameManager.h"


GameManager::GameManager()
{
}


void GameManager::Create_Sprite(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	sprite.Create_Sprite(hdc, hInst);
}