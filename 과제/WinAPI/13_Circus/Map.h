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
	//�������̽� ���� �ܵ�
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

