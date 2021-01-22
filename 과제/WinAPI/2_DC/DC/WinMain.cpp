#include<windows.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TextOut");

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	int r = 100;
	int Position_x = 300;
	int Position_y = 300;
	double x;
	double y;


	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for(int angle = 0; angle <360; angle++)
		{
			x = Position_x + r * cos(angle);
			y = Position_y + r * sin(angle);
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}
		Position_x += 500;

		for (int angle = 0; angle < 360; angle++)
		{
			x = Position_x + r* cos(angle);
			y = Position_y + 60 * sin(angle);
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}
		EndPaint(hWnd, &ps);
		

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_LBUTTONDOWN:
		
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
