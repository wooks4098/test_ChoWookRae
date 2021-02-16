#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{

}


void GameManager::GameDataSet(HWND hWnd)
{
	BitMapManager::GetInstans()->SetImage( hWnd);
}