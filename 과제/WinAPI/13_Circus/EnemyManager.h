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

	void Move(float m_fDeltaTime, int Player_Speed);
	void Move_Left(float m_fDeltaTime);
	void Move_Right(float m_fDeltaTime);

	void Draw_Front(HDC hdc);
	void Draw_Back(HDC hdc);


};

