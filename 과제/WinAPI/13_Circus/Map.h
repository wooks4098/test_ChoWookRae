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
	//인터페이스 관객 잔디
	BackGround Ground[8];
	BackGround Ui;

public:
	Map();
	~Map();
	
	void Draw(HDC hdc);



};

