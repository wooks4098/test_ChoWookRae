#include "GameFrame.h"



GameFrame::GameFrame()
{
	
}

void GameFrame::SetData(HWND hWnd)
{
	m_hWnd = hWnd;
	HDC hdc = GetDC(hWnd);

	m_hMemDC[0] = CreateCompatibleDC(hdc);
	m_hBitmap = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitmap);

	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
	

	m_hMemDC[2] = CreateCompatibleDC(m_hMemDC[0]);
	ReleaseDC(m_hWnd, hdc);


	m_dwCurTime = GetTickCount();
	m_fDeltaTime = m_dwCurTime;
	BitMapManager::GetInstans()->CreatImage(m_hWnd);
}

void GameFrame::Update()
{
	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount();
	Time = (m_dwCurTime - m_fDeltaTime)/10;

	player.Move(Time);
	Draw();
}

void GameFrame::Draw()
{

	m_hMemDC[1] = GetDC(m_hWnd);
	//��� ĳ���� ������Ʈ  ���� �׸���
	map.Draw(m_hMemDC[0]);

	player.Draw(m_hMemDC[0],m_dwCurTime);
	RECT rect;
	rect.left= 0;
	rect.top = 280;
	//BitMapManager::GetInstans()->Draw(m_hMemDC[0], rect, 16);
	//���� �׸� ����
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);

}

void GameFrame::Release()
{
	for(int i =0; i<2; i++)
		SelectObject(m_hMemDC[i], m_hOld);
	DeleteObject(m_hBitmap);
	for (int i = 0; i < 2; i++)
		DeleteDC(m_hMemDC[i]);
}

GameFrame::~GameFrame()
{
}
