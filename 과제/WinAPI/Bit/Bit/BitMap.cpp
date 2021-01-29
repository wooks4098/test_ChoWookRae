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

BitMap::~BitMap()
{
}
