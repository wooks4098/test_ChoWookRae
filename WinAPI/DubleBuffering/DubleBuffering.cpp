#include "defines.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWnd;
LPCTSTR lpszClass = TEXT("DoubleBuffering");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

//�׸��� ���������� ������ �׸��� ��� �����ؼ� �׷��� MemDC�� �ϳ��� �ʿ��ϴ�.
//�޸𸮻��� DC�� Ȯ���Ǿ����� ��ȭ����Ȱ�� ���� ������ ���� �ƹ��͵� ���� ������ 
//�Ͼ�� ��Ʈ���� �׷��ش� - Bitmap & OldBitmap�� �ϳ��� �� �ʿ��ϴ�.
HDC		g_MemDC[3];
HBITMAP	g_hBitmap[3];
HBITMAP g_hOld[3];

//������ǥ
int		x = 500;
int		y = 300;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:

		SetTimer(hWnd, 1, 10, NULL);

		hdc = GetDC(hWnd);

		//���� �׸� ���(��ȭ��)�� �غ��Ѵ�.
		g_MemDC[0] = CreateCompatibleDC(hdc);
		g_hBitmap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[0] = (HBITMAP)SelectObject(g_MemDC[0], g_hBitmap[0]);

		//���� �׸� ���(��ȭ��)�� ����� �׸� �غ� �Ѵ�.
		g_MemDC[1] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitmap[1] = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0
			, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[1] = (HBITMAP)SelectObject(g_MemDC[1], g_hBitmap[1]);

		//���� �׸� ���(��ȭ��)�� ĳ���͸� �׸� �غ� �Ѵ�.
		g_MemDC[2] = CreateCompatibleDC(g_MemDC[0]);
		g_hBitmap[2] = (HBITMAP)LoadImage(NULL, "char.bmp", IMAGE_BITMAP, 0, 0
			, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_hOld[2] = (HBITMAP)SelectObject(g_MemDC[2], g_hBitmap[2]);

		ReleaseDC(hWnd, hdc);
			return 0;

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		//�׸��� ��� �������ٰ� �ٽ� �׷����� ���� g_MemDC[0]�̱� ������ �������� ������ �ʴ´�.

		//���� �׸� ���(��ȭ��)�� ����� �׸���.
		BitBlt(g_MemDC[0], 0, 0, 1024, 768, g_MemDC[1], 0, 0, SRCCOPY);

		//���� �׸� ���(��ȭ��)�� ĳ���͸� �׸���.
		TransparentBlt(g_MemDC[0], x, y, 240, 192, g_MemDC[2], 0, 0, 240, 192, RGB(255, 0, 255));

		//���� �׸� ���� ���� �������� hdc�� �׸���.
		//���� hdc�� �׸��� ���� �׸��� ������ �ϰԵȴ�.
		//�׸��� ������ ������ �޹���� ������ �ƴϰ� ���𰡸� ��� �׸��� ������ �׸��� �����ؼ� �׸��� ���� �ش� �׸��� �����ְ� �ִ� ���̶�� �����ϸ� �ȴ�.
		BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[0], 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		return 0;

	case WM_TIMER:

		if (GetKeyState(VK_LEFT) & 0x8000)
			x -= 10;

		if (GetKeyState(VK_RIGHT) & 0x8000)
			x += 10;

		if (GetKeyState(VK_UP) & 0x8000)
			y -= 10;

		if (GetKeyState(VK_DOWN) & 0x8000)
			y += 10;

		InvalidateRect(hWnd, NULL, false);
		
		return 0;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}