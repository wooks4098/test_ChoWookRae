#include "GameFrame.h"
#include <string>
GameFrame* GameFrame::m_pThis = NULL;

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

	m_dwLastTime = GetTickCount64();
	m_dwCurTime = GetTickCount64();
	BitMapManager::GetInstans()->CreatImage(m_hWnd);
	Score = 0;
	Move_x = 0;
	HP = 3;
}

void GameFrame::Update()
{
	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount64();

	
	//���� �ð��� �����Ѵ�. ��ƾ�� ���ư� �� ���� ��ƾ������ ƽ ī��Ʈ���� ���̸� üũ�ϱ� ���ؼ� �̴�.
	//1000 �̻��� ���̰� ���� 1���̹Ƿ�  / 1000�ؼ� �ʷ� ȯ��.
 	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//���� Ÿ���� �޴´�.
	//��������� ���� Ÿ���� �ð��� �޴°�.
	

	//player.Move(2, 1);

	Move();
	CreatEnemy(m_fDeltaTime);
	Enemey_Disable_Check();
	Enemey_HitCheck();
	Draw();

	m_dwLastTime = m_dwCurTime;
		
}
void GameFrame::Move()
{
	Player_Speed = 0;
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		//ĳ���Ͱ� ���� ���� ���� ������ ĳ���� �̵�
		if ( player.Return_PlayerRect().left <= 50)
		{
			if (Move_x >= 2)
			{
				Player_Speed = Map_Right_Move;
				Move_x += m_fDeltaTime *-Player_Speed;
			}
		}
		else
			Player_Speed = -300;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (Move_x + 1 >= EndMap)
		{
			//ĳ���� �̵�
			Player_Speed = 300;
		}
		else
		{
			Player_Speed = Map_Left_Move;	
			Move_x += m_fDeltaTime * -Player_Speed;
		}
	}	
	if (GetKeyState(VK_SPACE) & 0x8000)
		player.StartJump();
	
	player.Jump(m_fDeltaTime);
	
	if (Move_x >= 0 && Move_x + 1 < EndMap) //Map�� ������ ���
	{
		map.Crowd_Move(Player_Speed, m_fDeltaTime);
		enemyManager.Move(m_fDeltaTime, Player_Speed);
		endFloor.Move(m_fDeltaTime, Player_Speed);
	}
	else //�÷��̾ ������ ���
	{
		player.Move(Player_Speed, m_fDeltaTime);
		enemyManager.Move(m_fDeltaTime);
	}

}

void GameFrame::DrawScore()
{

	//TCHAR str[] = (TCHAR)Score;
	//str= (TCHAR)Score;
	//std::wstring temp;
	int a = 110;

	auto temp = std::to_wstring(Score);
	TextOut(m_hMemDC[0], 10, 10, std::to_wstring(Score).c_str(), temp.length());
}

void GameFrame::ChangeScore(int score)
{
	Score += score;
}

void GameFrame::Draw()
{

	m_hMemDC[1] = GetDC(m_hWnd);

	//�� �׸���
	map.Draw(m_hMemDC[0]);
	endFloor.Draw(m_hMemDC[0]);

	//enemy�� �׸���
	enemyManager.Draw_Front(m_hMemDC[0]);
	//�÷��̾� �׸���
	player.Draw(m_hMemDC[0], m_fDeltaTime);	
	//enemy�� �׸���
	enemyManager.Draw_Back(m_hMemDC[0]);
	//Hp �׸���
	Draw_Hp();
	DrawScore();
	//���� ���۸�
	BitBlt(m_hMemDC[1], 0	, 0, 536, 383, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, m_hMemDC[1]);



}


void GameFrame::Draw_Hp()
{
	RECT Pos = {470,10,485,23};
	for (int i = 0; i < HP; i++)
	{
		BitMapManager::GetInstans()->Draw(m_hMemDC[0], Pos, BITMAP_ICON);
		Pos.left += 17;
		Pos.right += 17;
	}
}

void GameFrame::CreatEnemy(float _Time)
{
	enemyManager.Creat_Enemy(_Time);
}
void GameFrame::Enemey_Disable_Check()
{
	enemyManager.Disable_Check();
}
void GameFrame::Enemey_HitCheck()
{
	if (enemyManager.HitCheck(player.Return_PlayerRect()))
	{
		//���� 
		//PlayerHit();
		HP--;
	}
}

void GameFrame::PlayerHit()
{
	if (HP > 0)
	{
		HP--;
	}
	else
	{

	}
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
