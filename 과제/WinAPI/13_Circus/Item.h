#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
class Item
{
private :
	RECT Pos;

	bool isActive;
public:
	void Draw(HDC hdc);
	void Reset();
	void Spawn(int _left, int _top);

	void Move();//�⺻�̵�
	void Move_Left();//�÷��̾ �����ΰ��� �̵��ϵ���
	void Move_Right();//�÷��̾ �ڷΰ��� �̵��ϵ���

	bool Return_Active() { return isActive; }
};

