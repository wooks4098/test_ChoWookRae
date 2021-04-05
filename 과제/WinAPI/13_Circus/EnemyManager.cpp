#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	Time = 0;
	Enemy_Spawn_Time = 3;
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		enemy[i] = new Enemy_Original;
		enemy[i]->Reset();
	}

	for (int i = 0; i < ENEMY_ITEM_COUNT; i++)
	{
		enemy_Item[i] = new Enemy_Item;
		enemy_Item[i]->Reset();
	}
}

void EnemyManager::Creat_Enemy(float _Time)
{
	Time += _Time;
	if (Time >= Enemy_Spawn_Time)
	{
 		if (Is_Item())
		{
			for (int i = 0; i < ENEMY_COUNT; i++)
			{
				if (!enemy_Item[i]->Return_Active())
				{
					enemy_Item[i]->Spawn();
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < ENEMY_ITEM_COUNT; i++)
			{
				if (!enemy[0]->Return_Active())
				{
					enemy[i]->Spawn();
					break;
				}
			}
		}

		//생성 시간 초기화
		Time = 0;
		Enemy_Spawn_Time = rand() % 3 + 2;

	}	
}
bool EnemyManager::Is_Item()
{
	//return false;
	//return true;
	int item = rand() % 10 + 1;
	if (item >= 8)
		return true;
	else
		return false;
}


void EnemyManager::Draw_Front(HDC hdc)
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if(enemy[i]->Return_Active())
			enemy[i]->Draw_First(hdc);
	}

	for (int i = 0; i < ENEMY_ITEM_COUNT; i++)
	{
		if (enemy_Item[i]->Return_Active())
			enemy_Item[i]->Draw_First(hdc);
	}
}

void EnemyManager::Draw_Back(HDC hdc)
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemy[i]->Return_Active())
			enemy[i]->Draw_Back(hdc);
	}
	for (int i = 0; i < ENEMY_ITEM_COUNT; i++)
	{
		if (enemy_Item[i]->Return_Active())
			enemy_Item[i]->Draw_Back(hdc);
	}
}