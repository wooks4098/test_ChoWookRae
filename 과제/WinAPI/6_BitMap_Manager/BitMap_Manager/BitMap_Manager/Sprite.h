#pragma once
#include <Windows.h>
#include <string>
#include<utility>
#include <map>
#include "resource.h"
struct Image
{
	int Width;
	int Height;
	int ID;
};

class Sprite
{
private:
	std::map<std::string, Image> sprite;
	HDC		MemDC;
	HBITMAP	m_pMyBitMap;
	HBITMAP	m_pOldBitMap;

public:
	void Create_Sprite(HDC hdc, HINSTANCE hInst);
	void DataSet_Sprite(HDC hdc, HINSTANCE hInst, std::string Name, int Id); //HDC hdc, HINSTANCE hInst, int Id
	void Draw(HDC hdc, int x, int y, std::string Name);
};

