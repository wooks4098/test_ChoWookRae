#include "BitMap.h"



BitMap::BitMap()
{
}
void BitMap::Draw(HDC hdc, int x, int y,int Frame, int Direction) 
{
	//TransparentBlt(hdc, x, y, m_size.cx, m_size.cy, MemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
	TransparentBlt(hdc, x, y, m_size.cx / 4, m_size.cy / 4, MemDC, (m_size.cx / 4)*Frame, (m_size.cy / 4)*Direction, m_size.cx / 4, m_size.cy / 4, RGB(255, 0, 255));

	//TransparentBlt(hdc, x, y, bx / 4, by / 4, hMemDC, (bx / 4) * Frame, (by / 4) * Direction, bx / 4, by / 4, RGB(255, 0, 255));
}
void BitMap::CreatImage(HDC hdc, LPCWSTR FileName)
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

BitMap::~BitMap()
{
}
