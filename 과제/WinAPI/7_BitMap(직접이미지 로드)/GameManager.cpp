#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	OpenCard_Count = 0;
}


void GameManager::GameDataSet(HWND hWnd)
{
	BitMapManager::GetInstans()->SetImage( hWnd);
	cardManager.SetData();
}



void GameManager::CheckCard(HDC hdc, HINSTANCE hInst, HWND hWnd, POINT mouse)
{
	cardManager.CheckCard(hdc, hInst, hWnd, mouse);
}


void GameManager::OpenCard()
{

}


void GameManager::CloseCard()
{

}


void GameManager::DrawAll(HDC hdc)
{
	cardManager.DrawAll(hdc);
}


