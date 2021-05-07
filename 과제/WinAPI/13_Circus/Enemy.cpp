#include "Enemy.h"
#define LeftSpeed 140
#define RightSpeed 300
#define EnemySpeed 150
void Enemy::Move(float m_fDeltaTime, int Player_Speed)
{
	float Speed;
	if (Player_Speed == 0)
		Speed = -EnemySpeed * m_fDeltaTime;
	else
	{
		Speed = (Player_Speed- EnemySpeed )* m_fDeltaTime;
	}

	Pos.left+= Speed ;
	Pos.right += Speed ;


}


void Enemy::Disable()
{
	if (Pos.right <= -100)
		Reset();
}


//기본
Enemy_Original::Enemy_Original()
{
	Image = BITMAP_ENEMY_L;
	isActive = false;
	Time_L = 0;
}
void Enemy_Original::Draw_First(HDC hdc)
{
	RECT _Pos = Pos;
	_Pos.left -= 26;
	_Pos.right -= 26;
	Time_L++;
	
	BitMapManager::GetInstans()->Draw(hdc, _Pos, Image);

	if (Time_L >= 30)
	{
		Image = (Image != BITMAP_ENEMY_L) ? BITMAP_ENEMY_L : BITMAP_ENEMY_L1;
		Time_L = 0;
	}
}

void Enemy_Original::Draw_Back(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, Image+2);
}

void Enemy_Original::Spawn()
{
	//위치 리셋
	Pos.left = 550;
	Pos.top = 150;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 132;

	isActive = true;
}
void Enemy_Original::Reset()
{
	isActive = false;
}


//아이템
Enemy_Item::Enemy_Item()
{
	Image = BITMAP_ItemEnemy_L;
	isActive = false;
	Time_L = 0;
}
void Enemy_Item::Draw_First(HDC hdc)
{
	RECT _Pos = Pos;
	_Pos.left -= 26;
	_Pos.right -= 26;
	Time_L++;
	BitMapManager::GetInstans()->Draw(hdc, _Pos, Image);
	item.Draw(hdc);

}

void Enemy_Item::Draw_Back(HDC hdc)
{

	BitMapManager::GetInstans()->Draw(hdc, Pos, Image + 2);
	if (Time_L >= 30)
	{
		Time_L = 0;
		Image = (Image != BITMAP_ItemEnemy_L) ? BITMAP_ItemEnemy_L : BITMAP_ItemEnemy_L1;
	}
}

void Enemy_Item::Spawn()
{
	//위치 리셋  	138
	Pos.left = 550;
	Pos.top = 150;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 132;

	item.Spawn(Pos.left, Pos.top);
	//HitBox;
	isActive = true;
}
void Enemy_Item::Reset()
{
	isActive = false;
}

void Enemy_Item::Move(float m_fDeltaTime, int Player_Speed)
{
	float Speed;
	if (Player_Speed == 0)
		Speed = -EnemySpeed * m_fDeltaTime;
	else
	{
		Speed = (Player_Speed - EnemySpeed)* m_fDeltaTime;
	}

	Pos.left += Speed;
	Pos.right += Speed;
	//item.Move();
}
