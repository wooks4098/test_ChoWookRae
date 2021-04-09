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

	float Time;
	float Enemy_Spawn_Time;
public:
	EnemyManager();

	void Creat_Enemy(float _Time);
	bool Is_Item();

	void Move();
	void Move_Left();
	void Move_Right();

	void Draw_Front(HDC hdc);
	void Draw_Back(HDC hdc);


};

