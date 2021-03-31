#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
#include "Item.h"
#define ENEMY_MOVE_DIR -2

/// <summary>
/// GameFrame���� ������ų�� ����
/// 2~3�ʸ��� �������� item�� ���� Ȯ���� ������
/// 
/// </summary>

class Enemy
{
protected:
	int Enemy_State;
	RECT Pos;
	RECT HitBox;
	int Time_L;
	int Time_R;
	bool isActive;
public:

	virtual void Draw_First() = 0;
	virtual void Draw_Back() = 0;
	virtual void Reset() = 0;//�ʱ�ȭ(������)

	void Move_Left();//�⺻ �̵�
	void Move_Right();//�÷��̾ �ڷΰ��� �̵��ϵ���
	bool Return_Active() { return isActive; }
};

class Enemy_Original : public Enemy
{
public:
	void Draw_First();
	void Draw_Back();
	void Reset();
};

class Enemy_Item : public Enemy
{
private:
	Item item;
public:
	void Draw_First();
	void Draw_Back();
	void Reset();
};