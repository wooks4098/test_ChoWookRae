#include "Sprite.h"


void Sprite::CreatImage(HDC hdc, LPCWSTR FileName)
{
	MemDC = CreateCompatibleDC(hdc);

	m_BitMap = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);
	BITMAP BitMap_Info;
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info);
	m_size.cx = BitMap_Info.bmWidth;
	m_size.cy = BitMap_Info.bmHeight;
}


void Sprite::Draw(HDC hdc, float x, float y, float spX, float spY)
{
	//BitBlt(hdc, x, y, m_size.cx, m_size.cy, MemDC, 0, 0, SRCCOPY);
	StretchBlt(hdc, x, y, m_size.cx * 0.6, m_size.cy * 0.6, MemDC, 0, 0, m_size.cx, m_size.cy, SRCCOPY);
}
