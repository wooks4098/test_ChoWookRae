#pragma once
#include <Windows.h>

#define FPS			60

#define PI			3.141592f

//��Ʈ���� ���� - �÷��̾ �����̰� �ִ� ���¸� üũ�ϴ� ���̴�.
enum STATE
{
	IDLE,
	MOVE,
	JUMP
};

class GameFrameWork
{
private:
	HWND		m_hWnd;

	//Ÿ��üũ��
	DWORD		m_dwLastTime;
	DWORD		m_dwCurTime;
	float		m_fDeltaTime;

	HDC			m_hMemDC[3];
	HBITMAP		m_hBitmap[3];	//0 Back 1 BackGround 2 char
	HBITMAP		m_hOld[3];

	bool		m_bJump;
	//����������
	STATE		m_eState;
	
	float		m_fCurJumpTime;

	//������
	float		m_fVectorX;
	float		m_fVectorY;
public:
	GameFrameWork();
	~GameFrameWork();

	float		Player_x;
	float		Player_y;

	float		m_fJumpX;
	float		m_fJumpY;

	void Init(HWND hWnd);
	void Release();
	void Update();
	void OperateInput();
	void Render();
	
};

