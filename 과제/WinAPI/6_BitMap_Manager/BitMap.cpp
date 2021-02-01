#include "BitMap.h"


BitMap::BitMap()
{

}
void BitMap::Draw(HDC hdc, int x, int y, int spX = 1, int spY = 1)
{

}

void BitMap::ImageData_Set(HDC hdc, HINSTANCE hInst,int Id)
{
	MemDC = CreateCompatibleDC(hdc);
	m_pMyBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(Id));
	m_pOldBitMap = (HBITMAP)SelectObject(MemDC, m_pMyBitMap);

	BITMAP Bit_Info;

	GetObject(m_pMyBitMap, sizeof(Bit_Info), &Bit_Info);
	m_size.cx = Bit_Info.bmWidth;
	m_size.cy = Bit_Info.bmHeight;
}

BitMap::~BitMap()
{

}