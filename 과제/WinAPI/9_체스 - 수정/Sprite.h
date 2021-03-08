#include "Mecro.h"
#pragma once

class Sprite
{
private:
	HDC     MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE    m_size;

public:
	void Draw(HDC hdc, float x, float y, float spX, float spY, bool Transparent);
	void CreatImage(HDC hdc, LPCWSTR FileName);
	inline SIZE GetSize()
	{
		return m_size;
	}
};
