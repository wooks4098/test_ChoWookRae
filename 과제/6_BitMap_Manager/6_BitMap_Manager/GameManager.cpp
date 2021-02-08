#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
}


void GameManager::Create_Sprite(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	sprite.Create_Sprite(hdc, hInst);
}

void GameManager::Draw(HDC hdc, int x, int y, std::string Name)
{
	sprite.Draw(hdc,x,y,Name);
}