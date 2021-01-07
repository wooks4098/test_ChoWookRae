#include "GameFrameWork.h"
#include <math.h>

GameFrameWork::GameFrameWork()
{
	Player_x = 200.0f;
	Player_y = 500.0f;

	m_bJump = false;

	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();
}


GameFrameWork::~GameFrameWork()
{
}

void GameFrameWork::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	HDC hdc = GetDC(hWnd);
	
	m_hMemDC[0] = CreateCompatibleDC(hdc);
	m_hBitmap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld[0] = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitmap[0]);

	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
	m_hBitmap[1] = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOld[1] = (HBITMAP)SelectObject(m_hMemDC[1], m_hBitmap[1]);

	m_hMemDC[2] = CreateCompatibleDC(m_hMemDC[0]);
	m_hBitmap[2] = (HBITMAP)LoadImage(NULL, "char.bmp", IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOld[2] = (HBITMAP)SelectObject(m_hMemDC[2], m_hBitmap[2]);
	ReleaseDC(hWnd, hdc);
}


void GameFrameWork::Release()
{
	for (int i = 0; i < 3; i++)
	{
		SelectObject(m_hMemDC[i], m_hOld[i]);
		DeleteObject(m_hBitmap[i]);
		DeleteDC(m_hMemDC[i]);
	}
}

void GameFrameWork::Update()
{
	//��Ŭ��
	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{
		POINT pt;
		
		//���콺 ����Ʈ�� ��ǥ�� �����´�.
		GetCursorPos(&pt);
		
		//��ũ������ ��ǥ���� Client���� ��ǥ�� �ٲ� �ش�.
		ScreenToClient(m_hWnd, &pt);
	}

	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount();

	//���� �ð��� �����Ѵ�. ��ƾ�� ���ư� �� ���� ��ƾ������ ƽ ī��Ʈ���� ���̸� üũ�ϱ� ���ؼ� �̴�.
	//1000 �̻��� ���̰� ���� 1���̹Ƿ�  / 1000�ؼ� �ʷ� ȯ��.
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//���� Ÿ���� �޴´�.
	//��������� ���� Ÿ���� �ð��� �޴°�.
	m_dwLastTime = m_dwCurTime;

	//��, ��, ��, ��, ������ üũ �Ѵ�.
	OperateInput();

	//������ �����ؼ� �����̰� �ִ� �ð��� �ֱ⶧���� ���� ���ӽð����� ������ �������.
	if (m_eState == JUMP)
	{
		m_fCurJumpTime += m_fDeltaTime;

		//���׸��� �� �̰��� �����ϰ� �����ϸ� ������ �ȴ�.
		//���� ���ӽð��� üũ�ؼ� ��ġ�� ���¸� �ʱ�ȭ ���ش�.
		Player_x = m_fJumpX - cosf(m_fCurJumpTime * PI ) * 80;
		Player_y = m_fJumpY - sinf(m_fCurJumpTime * PI ) * 80;

		//���� ���ӽð� üũ�� �ʱ�ȭ.
		if (m_fCurJumpTime > 1.0f)
		{
			m_fCurJumpTime = 0.0f;

			//��Ȯ�� ������ ���� �÷��̾��� ��ġ�� ������ �ʿ䰡 �ְų� 
			//�÷��̾��� ��ġ�� �ڽ��� ���ϴ� �꿡 ���� �������ִ� ��ƾ�� ¥��ȴ�.

			//���� �ʱ�ȭ
			m_eState = IDLE;
		}
	}

	//�׷��ش�.
	Render();
}

//Degree(����)���� �޾� Radian �� ��ȯ �Լ�
float DegreeToRadian(float degree)
{
	return (PI / 180) * degree;
}

//�������ӵ��� �������� ���� ���ݸ�ŭ �����̰��ϰٴ�
void GameFrameWork::OperateInput()
{
	//��, ��, ��, �Ʒ�
	if (GetKeyState(VK_LEFT) & 0x8000)
		Player_x -= 500 * m_fDeltaTime;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		Player_x += 500 * m_fDeltaTime;
	if (GetKeyState(VK_UP) & 0x8000)
		Player_y -= 500 * m_fDeltaTime;
	if (GetKeyState(VK_DOWN) & 0x8000)
		Player_y += 500 * m_fDeltaTime;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (m_eState == IDLE)
		{
			// Ű �ٿ�
			m_eState = JUMP;
			
			//���� ������ ����ϱ� ���� ������ ������ġ�� �������ش�.
			m_fJumpY = Player_y;
			m_fJumpX = Player_x;	
		}
	}
}

//�׸���
void GameFrameWork::Render()
{
	HDC hdc = GetDC(m_hWnd);

	BitBlt(m_hMemDC[0], 0, 0, 1024, 768, m_hMemDC[1], 0, 0, SRCCOPY);
	TransparentBlt(m_hMemDC[0], (int)Player_x, (int)Player_y, 240, 192, 
		m_hMemDC[2], 0, 0, 240, 192, RGB(255, 0, 255));

	BitBlt(hdc, 0, 0, 1024, 768, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, hdc);
}
