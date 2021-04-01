#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
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

void EnemyManager::Creat_Enemy()
{
	if (Is_Item())
	{
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			if (!enemy[i]->Return_Active())
			{
				enemy[i]->Reset();
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < ENEMY_ITEM_COUNT; i++)
		{
			if (!enemy[i]->Return_Active())
			{
				enemy[i]->Reset();
				break;
			}
		}
	}
}

bool EnemyManager::Is_Item()
{
	if (rand() % 10 + 1 >= 8)
		return true;
	else
		false;
}