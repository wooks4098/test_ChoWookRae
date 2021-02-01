#pragma once
#include <Windows.h>
class BitMap
{
private:
	HDC		MemDC;
	HBITMAP	m_pMyBitMap;
	HBITMAP	m_pOldBitMap;
	SIZE	m_size;
public:
	void Draw(HDC hdc, int x, int y, int spX = 1, int spY = 1);
	void ImageData_Set(HDC hdc, HINSTANCE hInst, int Id);
	BitMap();
	~BitMap();

};

