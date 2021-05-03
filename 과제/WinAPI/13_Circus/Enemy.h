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
	int Time_L;
	int Time_R;
	int Image;
	bool isActive;
	RECT Pos_Front;
	RECT Pos_Back;
	RECT HitBox;
public:

	virtual void Disable();
	virtual void Draw_First(HDC hdc) = 0;
	virtual void Draw_Back(HDC hdc) = 0;
	virtual void Spawn() = 0;//����
	virtual void Reset() = 0;//�ʱ�ȭ(������)

	virtual void Move(float m_fDeltaTime);//�⺻�̵�
	virtual void Move_Left(float m_fDeltaTime);//�÷��̾ �����ΰ��� �̵��ϵ���
	virtual void Move_Right(float m_fDeltaTime);//�÷��̾ �ڷΰ��� �̵��ϵ���
	bool Return_Active() { return isActive; }
};

class Enemy_Original : public Enemy
{

public:
	Enemy_Original();
	void Draw_First(HDC hdc);
	void Draw_Back(HDC hdc);
	void Spawn();
	void Reset();
};

class Enemy_Item : public Enemy
{
private:
	Item item;
public:
	Enemy_Item();
	void Draw_First(HDC hdc);
	void Draw_Back(HDC hdc);
	void Spawn();
	void Reset();


	void Move();//�⺻�̵�
	void Move_Left();//�÷��̾ �����ΰ��� �̵��ϵ���
	void Move_Right();//�÷��̾ �ڷΰ��� �̵��ϵ���
};