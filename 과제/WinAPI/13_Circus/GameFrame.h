#pragma once
#include "Mecro.h"
#include "Map.h"
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

public:
	GameFrame();
	~GameFrame();

	void SetData();
	void Update();


	void Draw();


	void Release();

};

