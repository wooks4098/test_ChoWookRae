#pragma once
#include "Mecro.h"
#include "Map.h"
#include "Player.h"
class GameFrame
{
private:
	HWND	m_hWnd;
	HDC			m_hMemDC[2]; //0 ���� 1����
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;

	//Ÿ��üũ��
	DWORD		Time;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	Map map;


	Player player;
public:
	GameFrame();
	~GameFrame();

	void SetData(HWND hWnd);
	void Update();


	void Draw();


	void Release();

};

