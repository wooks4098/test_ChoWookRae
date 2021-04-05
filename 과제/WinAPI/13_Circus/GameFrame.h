#pragma once
#include "Mecro.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
class GameFrame
{
private:
	HWND	m_hWnd;
	HDC			m_hMemDC[2]; //0 ���� 1����
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;

	//Ÿ��üũ��
	DWORD		m_dwLastTime;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	Map map;

	int Move_x;
	Player player;
	EnemyManager enemyManager;
public:
	GameFrame();
	~GameFrame();

	void SetData(HWND hWnd);
	void Update();

	void Move();//ĳ����, ��, ������Ʈ(�Ÿ�, �׾Ƹ�)�̵�

	void Draw();

	void CreatEnemy(float _Time);

	void Release();

};

