#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
struct BackGround
{
	POINT pos;
	int BitMap_Number;
};
class Map
{

private:
	//�������̽� ���� �ܵ�
	BackGround Ground[8];
	BackGround Ui;

public:
	Map();
	~Map();
	
	void Draw(HDC hdc);



};

