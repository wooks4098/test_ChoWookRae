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
}
void Enemy_Original::Draw_First(HDC hdc)
{
	Time_L++;
	BitMapManager::GetInstans()->Draw(hdc, Pos, Image);

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

void Enemy_Original::Reset()
{
	//위치 리셋
	Pos.left = 139;
	Pos.top = 180;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 132;
	isActive = true;
}



//아이템
Enemy_Item::Enemy_Item()
{
	Image = BITMAP_ItemEnemy_L;
}
void Enemy_Item::Draw_First(HDC hdc)
{
	Time_L++;
	BitMapManager::GetInstans()->Draw(hdc, Pos, Image);

	if (Time_L >= 30)
	{
		Time_L = 0;
		Image = (Image != BITMAP_ItemEnemy_L) ? BITMAP_ItemEnemy_L : BITMAP_ItemEnemy_L1;
	}
}

void Enemy_Item::Draw_Back(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Pos, Image + 2);
}

void Enemy_Item::Reset()
{
	//위치 리셋  	138
	Pos.left = 139;
	Pos.top = 180;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 100;

	//HitBox;
	isActive = true;
}