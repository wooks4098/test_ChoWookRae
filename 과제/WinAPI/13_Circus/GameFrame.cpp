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

	Move_x = 0;
}

void GameFrame::Update()
{
	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount();
	Time = (m_dwCurTime - m_fDeltaTime);

	Move();

	Draw();
}
void GameFrame::Move()
{

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		map.Crowd_Move(Map_Right_Move);//ĳ���Ͱ� �������� �̵��ϸ� ���� ���������� �̵�

		if (Move_x - 1 <= StartMap)
		{
			//ĳ���� �̵�
		}
		else
		{
			//Move_x--;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		map.Crowd_Move(Map_Left_Move);//ĳ���Ͱ� ���������� �̵��ϸ� ���� �������� �̵�

		if (Move_x + 1 >= EndMap)
		{
			//ĳ���� �̵�
		}
		else
		{
			//Move_x++;
		}
	}
	player.Jump(Time);
	
}
void GameFrame::Draw()
{

	m_hMemDC[1] = GetDC(m_hWnd);
	//��� ĳ���� ������Ʈ  ���� �׸���
	map.Draw(m_hMemDC[0]);

	player.Draw(m_hMemDC[0],m_dwCurTime);
	
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);


	//DeleteObject(SelectObject(m_hMemDC[0], m_hOld)); //������ �޸𸮿� ������Ʈ�� �������ش�.
	//DeleteObject(m_hMemDC[1]);
	//DeleteDC(m_hMemDC[0]);
	//DeleteDC(m_hMemDC[1]);


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
