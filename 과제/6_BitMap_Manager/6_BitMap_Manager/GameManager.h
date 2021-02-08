#pragma once
#include<Windows.h>
#include "Sprite.h"
class GameManager
{
private:
	static GameManager* m_pThis;
	Sprite sprite;

public:
	static GameManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new GameManager;
		}
		return m_pThis;
	}

	GameManager();
	void Create_Sprite(HWND hWnd, HINSTANCE hInst);
	void Draw(HDC hdc, int x, int y, std::string Name);

};

