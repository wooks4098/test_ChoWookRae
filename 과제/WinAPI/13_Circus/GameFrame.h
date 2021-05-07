#pragma once
#include "Mecro.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
class GameFrame
{
private:



	HWND	m_hWnd;
	HDC			m_hMemDC[2]; //0 메인 1숨김
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;

	//타임체크용
	DWORD		m_dwLastTime;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	Map map;

	int Move_x;
	Player player;
	EnemyManager enemyManager;

	float Player_Speed;

public:
	GameFrame();
	~GameFrame();

	void SetData(HWND hWnd);
	void Update();

	void Move();//캐릭터, 맵, 오브젝트(거리, 항아리)이동

	void Draw();

	//enemy
	void CreatEnemy(float _Time);
	void Enemey_Disable_Check();
	void Enemey_HitCheck();


	void Release();

};

