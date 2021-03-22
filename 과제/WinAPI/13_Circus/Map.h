#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
struct BackGround
{
	RECT rect;
	int BitMap_Number[2];
};
class Map
{
private:
	//인터페이스 관객 잔디
	BackGround Ground[8];
	BackGround Ui;
	BackGround crowd[16];

	bool isWin();
	DWORD WinTIme;
public:
	Map();
	~Map();
	
	void Draw(HDC hdc);



};

