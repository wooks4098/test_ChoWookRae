#pragma once
#include "Mecro.h"

class BitMap
{
public:
	BitMap();
	~BitMap();

private:
	HDC     MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE    m_size;

public:
	//void Draw(HDC hdc, float x, float y, float spX, float spY, bool Transparent);
	void Draw(HDC hdc, RECT rect, int Frame, int Direction);
	void Draw(HDC hdc, RECT rect);
	void CreatImage(HDC hdc, LPCWSTR FileName);
	/*inline SIZE GetSize()
	{
		return m_size;
	}*/
};

