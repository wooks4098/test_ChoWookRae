#include<windows.h>
#include "GameManager.h"
#pragma comment(lib, "msimg32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");
GameManager GM;


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

//그림은 두장이지만 두장의 그림을 계속 갱신해서 그려줄 MemDC가 하나더 필요하다.
//메모리상의 DC가 확보되었지만 도화지역활을 해줄 공간을 위해 아무것도 없는 공간에 
//하얀색 비트맵을 그려준다 - Bitmap & OldBitmap이 하나씩 더 필요하다.
HDC		g_MemDC[3];
HBITMAP	g_hBitmap[3];
HBITMAP g_hOld[3];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, NULL);
		GM.SetData(hWnd);

		hdc = GetDC(hWnd);

		//숨겨 그릴 장소(도화지)를 준비한다.
		g_MemDC[0] = CreateCompatibleDC(hdc);
		g_hBitmap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[0] = (HBITMAP)SelectObject(g_MemDC[0], g_hBitmap[0]);

		//숨겨 그릴 장소(도화지)에 캐릭터를 그릴 준비를 한다.
		g_MemDC[1] = CreateCompatibleDC(g_MemDC[0]);
		//g_hBitmap[1] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[1] = (HBITMAP)SelectObject(g_MemDC[1], g_hBitmap[1]);

		g_MemDC[2] = CreateCompatibleDC(g_MemDC[0]);
		//g_hBitmap[2] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_hOld[2] = (HBITMAP)SelectObject(g_MemDC[2], g_hBitmap[2]);

		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

 		
		GM.Animation(g_MemDC);
		BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[0], 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		return 0;
	case WM_TIMER:
		GM.GetKey();
		InvalidateRect(hWnd, NULL, false);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
