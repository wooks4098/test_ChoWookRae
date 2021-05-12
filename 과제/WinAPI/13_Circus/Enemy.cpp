#include "Enemy.h"
#define LeftSpeed 140
#define RightSpeed 300
#define EnemySpeed 150
#include "GameFrame.h"
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
	HitBox.left += Speed;
	HitBox.right += Speed;

}

bool Enemy::HitCheck(RECT Player_Rect)
{
	RECT tmp;
	if (IntersectRect(&tmp, &HitBox, &Player_Rect) && !isHit)
	{
 		isHit = true;
		return true;
	}
	else
	{
		if (IntersectRect(&tmp, &Pos, &Player_Rect) && !isHit &&!isPass)
		{
 			GameFrame::GetInstans()->ChangeScore(100);

			isPass = true;
		}

		return false;
	}
	return false;
}

void Enemy::Disable()
{
	if (Pos.right <= -150)
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
	Pos.top = 160;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 132;
	isActive = true;
	isHit = false;
	isPass = false;
	//히트박스 리셋
	HitBox.left = Pos.left -5;
	HitBox.top = Pos.bottom;
	HitBox.right = Pos.left + 5;
	HitBox.bottom = HitBox.top +20;

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
	Pos.top = 182;
	Pos.right = Pos.left + 25;
	Pos.bottom = Pos.top + 104;

	item.Spawn(Pos.left, Pos.top);

	HitBox.left = Pos.left - 5;
	HitBox.top = Pos.bottom;
	HitBox.right = Pos.left + 5;
	HitBox.bottom = HitBox.top + 20;

	isActive = true;
	isHit = false;
	isPass = false;
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
	HitBox.left += Speed;
	HitBox.right += Speed;

	item.Move(Speed);
}

bool Enemy_Item::HitCheck(RECT Player_Rect)
{
	RECT tmp;

	item.IsHIt(Player_Rect);

	if (IntersectRect(&tmp, &HitBox, &Player_Rect)&& !isHit)
	{
		isHit = true;
		return true;
	}
	else
	{
		if (IntersectRect(&tmp, &Pos, &Player_Rect) && !isHit && !isPass)
		{
			isPass = true;
		}

		return false;
	}

}


void Enemy_Item::Disable()
{
	if (Pos.right <= -150)
	{
		Reset();
		item.Reset();
	}
}