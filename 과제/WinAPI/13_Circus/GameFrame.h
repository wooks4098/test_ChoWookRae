#pragma once
#include "Mecro.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "BitMapManager.h"
#include "EndFloor.h"
class GameFrame
{

#pragma region 싱글톤
private:

	static GameFrame* m_pThis;
public:
	static GameFrame* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new GameFrame;
		}
		return m_pThis;
	}

#pragma endregionprivate:



	HWND	m_hWnd;
	HDC			m_hMemDC[2]; //0 메인 1숨김
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;

	//타임체크용
	DWORD		m_dwLastTime;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	Map map;

	float Move_x;
	Player player;
	EnemyManager enemyManager;
	EndFloor endFloor;
	float Player_Speed;
	int Score;
	int HP;
public:


	GameFrame();
	~GameFrame();

	void SetData(HWND hWnd);
	void Update();

	void Move();//캐릭터, 맵, 오브젝트(거리, 항아리)이동

	void Draw();
	void Draw_Hp();

	void DrawScore();
	void ChangeScore(int score);

	//enemy
	void CreatEnemy(float _Time);
	void Enemey_Disable_Check();
	void Enemey_HitCheck();
	void PlayerHit();
	void GameReset();
	void Release();
	

};

