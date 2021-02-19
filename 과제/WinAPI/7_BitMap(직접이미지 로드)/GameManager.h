#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
#include "CardManager.h"
class GameManager
{
#pragma region ΩÃ±€≈Ê
private:
	static GameManager* m_pThis;
public:
	static GameManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new GameManager;
		}
		return m_pThis;
	}
#pragma endregion

private:
	CardManager cardManager;

	int OpenCard_Count;
public:
	GameManager();
	void GameDataSet( HWND hWnd);

	void CheckCard(HDC hdc, HINSTANCE hInst, HWND hWnd);
	void OpenCard();
	void CloseCard();

};

