#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");
HBITMAP hImage, hOldBitmap;

int Count = 0;
int Frame = 0;
int Direction;
int x = 100;
int y = 100;
enum Dir {
	DIR_Down = 0,
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT,
};
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
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
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HDC hMemDC;
	int bx, by;
	BITMAP bit;
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, NULL);

		hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		return 0;
	case WM_TIMER:

		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			x -= 10;
			Direction = DIR_LEFT;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			x += 10;
			Direction = DIR_RIGHT;
		}
		if (GetKeyState(VK_UP) & 0x8000)
		{
			y -= 10;
			Direction = DIR_UP;
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			y += 10;
			Direction = DIR_Down;
		}

		Count++;
		if (Count >= 10)
		{
			Frame++;
			if (Frame >= 4)
			{
				Frame = 0;
			}
			Count = 0;
		}
		
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hdc);

		hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);

		GetObject(hImage, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;

		//투명처리와 부분그리기
		//이번에는 왼쪽을 보고 있고 한발을 내딛은 캐릭터를 그린다
		TransparentBlt(hdc, x, y, bx / 4, by / 4,
			hMemDC, (bx / 4) * Frame, (by / 4) * Direction, bx / 4, by / 4, RGB(255, 0, 255));

		SelectObject(hMemDC, hOldBitmap);
		DeleteObject(hImage);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);

		

		return 0;


	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
