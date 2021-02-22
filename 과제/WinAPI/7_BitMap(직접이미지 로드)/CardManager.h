#pragma once
#include "Card.h"
#include "Mecro.h"

struct OpenCard
{
	int x;
	int y;
	std::string Name;
};

class CardManager
{
private:
	Card CardList[2][10];
	OpenCard openCard[2];
	int OpenCard_Count;

public:
	CardManager();
	void SetData();
	void SetPos();

	void DrawAll(HDC hdc);

	void WinCheck(HDC hdc, HINSTANCE hInst, HWND hWnd);
	void CheckCard(HDC hdc, HINSTANCE hInst, HWND hWnd, POINT mouse);
};

