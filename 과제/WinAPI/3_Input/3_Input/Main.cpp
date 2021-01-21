#include<windows.h>
#include <math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Input");

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

TCHAR str[256];
int x = 0;
int y = 0;
int Pos_x = 300;
int Pos_y = 300;
RECT rt = { 100, 100, 500, 600 };LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int len;
	int r = 100;


	switch (iMessage)
	{


	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
/*
		///1
		Pos_x = 300;
		Pos_y = 300;
		for (int angle = 0; angle < 360; angle++)
		{
			x =  r * cos(angle);
			y =  r * sin(angle);
			SetPixel(hdc, x+ Pos_x, y+ Pos_y, RGB(255, 0, 0));
		}*/

		///2
		/*for (int angle = 0; angle < 360; angle++)
		{
			x = r * cos(angle);
			y = r * sin(angle);
			SetPixel(hdc, x + Pos_x, y + Pos_y, RGB(255, 0, 0));
		}*/
		//3
		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
		for (int angle = 0; angle < 360; angle++)
		{
			x = r * cos(angle);
			y = r * sin(angle);
			SetPixel(hdc, x + Pos_x, y + Pos_y, RGB(255, 0, 0));
		}
		

		

		EndPaint(hWnd, &ps);


		return 0;

	//2
	case WM_MOUSEMOVE:

		Pos_x = LOWORD(lParam);
		Pos_y = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, TRUE);

		return 0;

		///1
	/*case WM_KEYDOWN:

		switch (wParam)
		{
			case VK_LEFT:
				Pos_x -= 10;
				break;
			case VK_RIGHT:
				Pos_x += 10;
				break;
			case VK_UP:
				Pos_y -= 10;
				break;
			case VK_DOWN:
				Pos_y += 10;
				break;
		}

		InvalidateRect(hWnd, NULL, TRUE);
	return 0;*/

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}