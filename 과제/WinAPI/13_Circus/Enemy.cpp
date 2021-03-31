#include "Enemy.h"

void Enemy::Move_Left()
{

}
void Enemy::Move_Right()
{

}

//기본
void Enemy_Original::Draw_First()
{
	Time_L++;
	if (Time_L >= 30)
	{
		Time_L = 0;
	}
}

void Enemy_Original::Draw_Back()
{
	Time_R++;
	if (Time_R >= 30)
	{
		Time_R = 0;
	}
}

void Enemy_Original::Reset()
{
	//위치 리셋
	isActive = true;
}



//아이템
void Enemy_Item::Draw_First()
{
	Time_L++;




	if (Time_L >= 30)
	{
		Time_L = 0;
	}
}

void Enemy_Item::Draw_Back()
{
	Time_R++;
	if (Time_R >= 30)
	{
		Time_R = 0;
	}
}

void Enemy_Item::Reset()
{
	//위치 리셋
	isActive = true;
}