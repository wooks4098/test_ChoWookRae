#pragma once
#include<Windows.h>
#include "Sprite.h"

struct Point
{
	int id;
	bool isOpen;
};

struct CheckData
{
	int id;
	int x;
	int y;
};

class GameManager
{
private:
	static GameManager* m_pThis;
	Sprite sprite;
	Point point[2][9];

	int rightCount;

	CheckData firstOpen;
	CheckData secondOpen;

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
	void Draw(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name);

	void DrawAll(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name);
	void Click(HWND hWnd, int Mouse_x, int Mouse_y);

	void CardCheck();

};

