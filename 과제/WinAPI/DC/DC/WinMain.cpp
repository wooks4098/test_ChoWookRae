#include<windows.h>
#include <math.h>
#define _USE_MATH_DEFINES

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
	double x;
	double y;


	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		for (int i = 0; i < 20; i++)
		{
			x = 300-cos(3.14*i / 20);
			y = 300- cos(3.14*i / 20);
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}

		//for (int i = 0; i < 360; i++)
		//{
		//	//x^2 + y^2 = r^2
		//	//y^2= 100 - i
		//	y = 100 - i * i;
		//	y = sqrt(y);
		//	SetPixel(hdc, i+100, y+100, RGB(0, 0, 0));
		//}
			/*
					Vector2 dirVec = new Vector2(Mathf.Cos(Mathf.PI * 2 * i / BulletCount),
										 Mathf.Sin(Mathf.PI * 2 * i / BulletCount))
		*/
		
		EndPaint(hWnd, &ps);
		

		return 0;
		

	case WM_LBUTTONDOWN:
		
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
