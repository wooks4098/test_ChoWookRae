#include "Enemy.h"

void Enemy::Move_Left()
{

}
void Enemy::Move_Right()
{

}

//�⺻
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
	//��ġ ����
	isActive = true;
}



//������
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
	//��ġ ����
	isActive = true;
}