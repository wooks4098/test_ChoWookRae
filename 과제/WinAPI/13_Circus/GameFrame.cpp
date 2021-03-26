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
	//매 프레임마다 찍히는 TickCount를 받는다. -  현제의 틱카운드를 받아온다.
	m_dwCurTime = GetTickCount();
	Time = (m_dwCurTime - m_fDeltaTime);

	Move();

	Draw();
}
void GameFrame::Move()
{

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		map.Crowd_Move(Map_Right_Move);//캐릭터가 왼쪽으로 이동하면 맵은 오른쪽으로 이동

		if (Move_x - 1 <= StartMap)
		{
			//캐릭터 이동
		}
		else
		{
			//Move_x--;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		map.Crowd_Move(Map_Left_Move);//캐릭터가 오른쪽으로 이동하면 맵은 왼쪽으로 이동

		if (Move_x + 1 >= EndMap)
		{
			//캐릭터 이동
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
	//배경 캐릭터 오브젝트  숨겨 그리기
	map.Draw(m_hMemDC[0]);

	player.Draw(m_hMemDC[0],m_dwCurTime);
	
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);


	//DeleteObject(SelectObject(m_hMemDC[0], m_hOld)); //끝으로 메모리와 오브젝트을 해지해준다.
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
