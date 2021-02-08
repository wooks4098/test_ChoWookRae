#include "Sprite.h"


void Sprite::Create_Sprite(HDC hdc, HINSTANCE hInst)
{
	DataSet_Sprite(hdc, hInst, "엑스", IDB_PNG1);
	DataSet_Sprite(hdc, hInst, "삼각형", IDB_PNG2);
	DataSet_Sprite(hdc, hInst, "오각형", IDB_PNG3);
	DataSet_Sprite(hdc, hInst, "원", IDB_PNG4);
	DataSet_Sprite(hdc, hInst, "하트", IDB_PNG5);
	DataSet_Sprite(hdc, hInst, "번개", IDB_PNG6);
	DataSet_Sprite(hdc, hInst, "번개", IDB_PNG7);
	DataSet_Sprite(hdc, hInst, "달", IDB_PNG8);
	DataSet_Sprite(hdc, hInst, "물음표", IDB_PNG9);
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



void Sprite::Draw(HDC hdc, int x, int y, std::string Name)
{
	std::map<std::string, Image>::iterator iter = sprite.find(Name);

	BitBlt(hdc, x, y, iter->second.Width, iter->second.Height, MemDC, 0, 0, SRCCOPY);
}