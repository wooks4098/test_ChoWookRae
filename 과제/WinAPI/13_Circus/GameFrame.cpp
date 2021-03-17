#include "GameFrame.h"



GameFrame::GameFrame()
{
	SetData();
	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();
	
}

void GameFrame::SetData()
{
	HDC hdc = GetDC(m_hWnd);

	m_hMemDC[0] = CreateCompatibleDC(hdc);
	m_hBitmap = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitmap);

	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
	

	m_hMemDC[2] = CreateCompatibleDC(m_hMemDC[0]);
	
	ReleaseDC(m_hWnd, hdc);
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


	Draw();
}

void GameFrame::Draw()
{
	//배경 캐릭터 오브젝트  숨겨 그리기

	map.Draw(m_hMemDC[0]);

	//숨긴 그림 복사
	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
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
