#include "Enemy.h"

void Enemy::Move_Left()
{

}
void Enemy::Move_Right()
{

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
	Time_L++;
	BitMapManager::GetInstans()->Draw(hdc, Pos_Front, Image);

	if (Time_L >= 30)
	{
		Image = (Image != BITMAP_ENEMY_L) ? BITMAP_ENEMY_L : BITMAP_ENEMY_L1;
		Time_L = 0;
	}
}

void Enemy_Original::Draw_Back(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos_Back, Image+2);
}

void Enemy_Original::Spawn()
{
	//위치 리셋
	Pos_Front.left = 200;
	Pos_Front.top = 150;
	Pos_Front.right = Pos_Front.left + 25;
	Pos_Front.bottom = Pos_Front.top + 132;

	Pos_Back.left = Pos_Front.right;
	Pos_Back.top = 150;
	Pos_Back.right = Pos_Back.left + 23;
	Pos_Back.bottom = Pos_Back.top + 132;
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
	Time_L++;
	BitMapManager::GetInstans()->Draw(hdc, Pos_Front, Image);
	item.Draw(hdc);

}

void Enemy_Item::Draw_Back(HDC hdc)
{

	BitMapManager::GetInstans()->Draw(hdc, Pos_Back, Image + 2);
	if (Time_L >= 30)
	{
		Time_L = 0;
		Image = (Image != BITMAP_ItemEnemy_L) ? BITMAP_ItemEnemy_L : BITMAP_ItemEnemy_L1;
	}
}

void Enemy_Item::Spawn()
{
	//위치 리셋  	138
	Pos_Front.left = 200;
	Pos_Front.top = 165;
	Pos_Front.right = Pos_Front.left + 24;
	Pos_Front.bottom = Pos_Front.top + 100;

	Pos_Back.left = Pos_Front.right + 1;
	Pos_Back.top = 165;
	Pos_Back.right = Pos_Front.right + 1;
	Pos_Back.bottom = Pos_Back.top + 100;

	item.Spawn(Pos_Front.left,Pos_Back.top);
	//HitBox;
	isActive = true;
}
void Enemy_Item::Reset()
{
	isActive = false;
}