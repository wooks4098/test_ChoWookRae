#include<windows.h>
#pragma comment(lib, "msimg32.lib")
#include "SpriteManager.h"
#include "GameManager.h"
GameManager GM;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");

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
RECT clientRect;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	POINT Point;
	switch (iMessage)
	{
	case WM_CREATE:
		SetRect(&clientRect, 0, 0, 640, 640); //원하는 클라이언트 크기를 저장한다.
		AdjustWindowRect(&clientRect, WS_OVERLAPPEDWINDOW, FALSE); //윈도우 크기를 계산

		MoveWindow(hWnd, 0, 0, clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, TRUE);
		SpriteManager::GetInstans()->SetImage(hWnd);
		GM.SetData();
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//Map::GetInstans()->MapDraw(hdc);
		GM.Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_LBUTTONDOWN:
		hdc = BeginPaint(hWnd, &ps);
		Point.x = LOWORD(lParam);
		Point.y = HIWORD(lParam);

		GM.MouseClick(Point);

		EndPaint(hWnd, &ps);
		InvalidateRect(hWnd, NULL, TRUE);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
