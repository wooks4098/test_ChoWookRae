#pragma once
#include "Mecro.h"
#include "Map.h"
class GameFrame
{
private:
	HWND	m_hWnd;
	HDC			m_hMemDC[2]; //0 ¸ÞÀÎ 1¼û±è
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;

	//Å¸ÀÓÃ¼Å©¿ë
	DWORD		m_dwLastTime;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	Map map;

public:
	GameFrame();
	~GameFrame();

	void SetData();
	void Update();


	void Draw();


	void Release();

};

