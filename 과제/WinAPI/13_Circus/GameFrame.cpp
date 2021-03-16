#include "GameFrame.h"



GameFrame::GameFrame()
{
}

void GameFrame::SetData(HWND hWnd)
{
	HWND	m_hWnd;
	HDC			m_hMemDC[3];
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOld;


	m_hWnd = hWnd;
	HDC hdc = GetDC(hWnd);

	m_hMemDC[0] = CreateCompatibleDC(hdc);
	m_hBitmap = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitmap);

	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
	

	m_hMemDC[2] = CreateCompatibleDC(m_hMemDC[0]);
	
	ReleaseDC(hWnd, hdc);
}



GameFrame::~GameFrame()
{
}
