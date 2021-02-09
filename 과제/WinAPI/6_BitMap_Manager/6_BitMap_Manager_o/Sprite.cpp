#include "Sprite.h"


void Sprite::Create_Sprite(HDC hdc, HINSTANCE hInst)
{
	DataSet_Sprite(hdc, hInst, "강아지", IDB_BITMAP1);
	DataSet_Sprite(hdc, hInst, "호랑이", IDB_BITMAP2);
	DataSet_Sprite(hdc, hInst, "오리", IDB_BITMAP3);
	DataSet_Sprite(hdc, hInst, "코끼리", IDB_BITMAP4);
	DataSet_Sprite(hdc, hInst, "소", IDB_BITMAP5);
	DataSet_Sprite(hdc, hInst, "말", IDB_BITMAP6);
	DataSet_Sprite(hdc, hInst, "고양이", IDB_BITMAP7);
	DataSet_Sprite(hdc, hInst, "원숭이", IDB_BITMAP8);
	DataSet_Sprite(hdc, hInst, "개구리", IDB_BITMAP9);
	DataSet_Sprite(hdc, hInst, "닭", IDB_BITMAP10);
	DataSet_Sprite(hdc, hInst, "검은색", IDB_BITMAP11);
}

void Sprite::DataSet_Sprite(HDC hdc, HINSTANCE hInst, std::string Name, int Id)
{
	MemDC = CreateCompatibleDC(hdc);
	m_pMyBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(Id));
	m_pOldBitMap = (HBITMAP)SelectObject(MemDC, m_pMyBitMap);

	BITMAP Bit_Info;
	GetObject(m_pMyBitMap, sizeof(Bit_Info), &Bit_Info);

	Image newimage;

	newimage.ID = Id;
	newimage.Width = Bit_Info.bmWidth;
	newimage.Height = Bit_Info.bmHeight;
	sprite.insert(std::make_pair(Name, newimage));
}



void Sprite::Draw(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name)
{
	std::map<std::string, Image>::iterator iter = sprite.find(Name);
	MemDC = CreateCompatibleDC(hdc);
	m_pMyBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(iter->second.ID));
	m_pOldBitMap = (HBITMAP)SelectObject(MemDC, m_pMyBitMap);
	BitBlt(hdc, x, y, iter->second.Width, iter->second.Height, MemDC, 0, 0, SRCCOPY);
}