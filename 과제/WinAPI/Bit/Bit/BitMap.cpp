#include "BitMap.h"

BitMap::BitMap()
{

}
void BitMap::DrawAll(HDC hdc, HINSTANCE hInst)
{
	Setbit(hdc, hInst, IDB_BITMAP1, 50, 50);
	Setbit(hdc, hInst, IDB_BITMAP2, 200, 50);
}

void BitMap::Setbit(HDC hdc, HINSTANCE hInst, int id,int x, int y)
{

	MemDC = CreateCompatibleDC(hdc);
	pBitMap = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(id));
	pBitOld = (HBITMAP)SelectObject(MemDC, pBitMap);

	BITMAP BitMap_Info;

	GetObject(pBitMap, sizeof(BitMap_Info), &BitMap_Info);
	size.cx = BitMap_Info.bmWidth;
	size.cy = BitMap_Info.bmHeight;

	Draw(hdc, x, y, size.cx, size.cy);

}

void BitMap::Draw(HDC hdc, int x, int y, int cx, int cy)
{
	StretchBlt(hdc, x, y, cx, cy, MemDC, 0, 0, size.cx, size.cy, SRCCOPY);
}



void BitMap::MouseClick(HWND hWnd, int Mouse_x, int Mouse_y)
{

	if (Mouse_x >= 50 && Mouse_x <= 195)
	{
		if (Mouse_y >= 50 && Mouse_y <= 285)
		{
			(MessageBox(hWnd, "강아지", "동물", MB_OK));
		}
	}

	if (Mouse_x >= 200 && Mouse_x <= 345)
	{
		if (Mouse_y >= 50 && Mouse_y <= 285)
		{
			(MessageBox(hWnd, "호랑이", "동물", MB_OK));
		}
	}

}

BitMap::~BitMap()
{
}
