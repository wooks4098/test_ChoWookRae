#pragma once
#include<Windows.h>
#include "Sprite.h"
#include <string>

#define END 9
struct CheckData
{
	int id;
	int x;
	int y;
	std::string name;

};
struct CardData
{
	bool isOpen;
	CheckData data;
};


class GameManager
{
private:
	static GameManager* m_pThis;
	Sprite sprite;
	CardData cardData[2][9];

	int rightCount;

	CheckData firstOpen;
	CheckData secondOpen;

	void CardDataSet();

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

	void DrawAll(HDC hdc, HINSTANCE hInst);
	void Click(HDC hdc, HINSTANCE hInst, HWND hWnd, int Mouse_x, int Mouse_y);

	void CardCheck(HDC hdc, HINSTANCE hInst, HWND hWnd);
	void CardOpen(HDC hdc, HINSTANCE hInst, HWND hWnd, CheckData *Open);


};

