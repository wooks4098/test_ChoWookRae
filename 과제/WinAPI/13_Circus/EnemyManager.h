#pragma once
#include "Mecro.h"
#include "Enemy.h"
#define ENEMY_COUNT 15
#define ENEMY_ITEM_COUNT 10

class EnemyManager
{
private:
	Enemy* enemy[ENEMY_COUNT];
	Enemy* enemy_Item[ENEMY_ITEM_COUNT];
public:
	EnemyManager();

	void Creat_Enemy();
	bool Is_Item();


};

