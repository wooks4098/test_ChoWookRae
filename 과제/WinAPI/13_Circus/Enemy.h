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
	bool isHit;
	bool isPass;
	RECT Pos;
	RECT HitBox;
public:

	virtual void Disable();
	virtual void Draw_First(HDC hdc) = 0;
	virtual void Draw_Back(HDC hdc) = 0;
	virtual void Spawn() = 0;//����
	virtual void Reset() = 0;//�ʱ�ȭ(������)
	virtual bool HitCheck(RECT Player_Rect);

	virtual void Move(float m_fDeltaTime,int Player_Speed);//�⺻�̵�

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
	void Disable();
	bool HitCheck(RECT Player_Rect);
	void Move(float m_fDeltaTime, int Player_Speed);//�⺻�̵�

};