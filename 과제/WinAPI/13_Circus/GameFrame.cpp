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

	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();
	
	BitMapManager::GetInstans()->CreatImage(m_hWnd);

	Move_x = 0;
}

void GameFrame::Update()
{
	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount();

	//���� �ð��� �����Ѵ�. ��ƾ�� ���ư� �� ���� ��ƾ������ ƽ ī��Ʈ���� ���̸� üũ�ϱ� ���ؼ� �̴�.
	//1000 �̻��� ���̰� ���� 1���̹Ƿ�  / 1000�ؼ� �ʷ� ȯ��.
 	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//���� Ÿ���� �޴´�.
	//��������� ���� Ÿ���� �ð��� �޴°�.
	m_dwLastTime = m_dwCurTime;

	Move();

	Draw();
		
}
void GameFrame::Move()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (Move_x - 1 <= StartMap)
		{
			//ĳ���� �̵�
		}
		else
		{
			map.Crowd_Move(Map_Right_Move, m_fDeltaTime);		//ĳ���Ͱ� �������� �̵��ϸ� ���� ���������� �̵�
			Move_x--;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (Move_x + 1 >= EndMap)
		{
			//ĳ���� �̵�
		}
		else
		{
			map.Crowd_Move(Map_Left_Move, m_fDeltaTime);		//ĳ���Ͱ� ���������� �̵��ϸ� ���� �������� �̵�
			Move_x++;
		}
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
		player.StartJump();

	player.Jump(m_fDeltaTime);
	
}
void GameFrame::Draw()
{

	m_hMemDC[1] = GetDC(m_hWnd);
	//��� ĳ���� ������Ʈ  ���� �׸���
	map.Draw(m_hMemDC[0]);

	player.Draw(m_hMemDC[0],m_dwCurTime);
	
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, m_hMemDC[1]);

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
