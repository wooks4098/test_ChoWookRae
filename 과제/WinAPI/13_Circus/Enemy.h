#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
#include "Item.h"
#define ENEMY_MOVE_DIR -2

/// <summary>
/// GameFrame에서 생성시킬지 측정
/// 2~3초마다 나오도록 item이 적은 확률로 나오게
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
	RECT Pos;
	RECT HitBox;
public:

	virtual void Draw_First(HDC hdc) = 0;
	virtual void Draw_Back(HDC hdc) = 0;
	virtual void Reset() = 0;//초기화(생성시)

	void Move_Left();//기본 이동
	void Move_Right();//플레이어가 뒤로가면 이동하도록
	bool Return_Active() { return isActive; }
};

class Enemy_Original : public Enemy
{

public:
	Enemy_Original();
	void Draw_First(HDC hdc);
	void Draw_Back(HDC hdc);
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
	void Reset();
};