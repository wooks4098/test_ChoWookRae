#pragma once
#include "Mecro.h"
class GameFrame
{
private:
	HWND	m_hWnd;
	HDC			m_hMemDC[3];
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;
public:
	GameFrame();
	~GameFrame();

	void SetData(HWND hWnd);



};

