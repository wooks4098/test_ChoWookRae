#pragma once
#include <windows.h>
#include "resource.h"
class BitMap
{
private:
	HDC		MemDC;
	HBITMAP	pBitMap;
	HBITMAP pBitOld;
	SIZE	size;
public:
	BitMap();
	void Setbit(HDC hdc, HINSTANCE hInst, int id, int x, int y);
	void Draw(HDC hdc, int x, int y, int cx, int cy);
	void DrawAll(HDC hdc, HINSTANCE hInst);
	void MouseClick(HWND hWnd, int Mouse_x, int Mouse_y);
	~BitMap();
};

