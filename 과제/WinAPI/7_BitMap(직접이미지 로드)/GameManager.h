#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
class GameManager
{
#pragma region �̱���
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


public:

	GameManager();


	void GameDataSet( HWND hWnd);
};

