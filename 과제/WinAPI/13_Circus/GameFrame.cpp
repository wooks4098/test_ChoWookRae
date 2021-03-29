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
	//매 프레임마다 찍히는 TickCount를 받는다. -  현제의 틱카운드를 받아온다.
	m_dwCurTime = GetTickCount();

	//현재 시간을 저장한다. 루틴이 돌아간 후 이전 루틴에서의 틱 카운트간의 차이를 체크하기 위해서 이다.
	//1000 이상의 차이가 나면 1초이므로  / 1000해서 초로 환산.
 	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//현재 타임을 받는다.
	//결론적으로 이전 타임의 시간을 받는것.
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
			//캐릭터 이동
		}
		else
		{
			map.Crowd_Move(Map_Right_Move, m_fDeltaTime);		//캐릭터가 왼쪽으로 이동하면 맵은 오른쪽으로 이동
			Move_x--;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (Move_x + 1 >= EndMap)
		{
			//캐릭터 이동
		}
		else
		{
			map.Crowd_Move(Map_Left_Move, m_fDeltaTime);		//캐릭터가 오른쪽으로 이동하면 맵은 왼쪽으로 이동
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
	//배경 캐릭터 오브젝트  숨겨 그리기
	map.Draw(m_hMemDC[0]);

	player.Draw(m_hMemDC[0],m_dwCurTime);
	
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, m_hMemDC[1]);

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
