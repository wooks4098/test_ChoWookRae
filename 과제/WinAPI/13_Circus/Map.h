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
	BackGround crowd[24];

public:
	Map();
	~Map();
	
	void Crowd_Move(int x, float m_fDeltaTime);
	void Draw(HDC hdc);



};

