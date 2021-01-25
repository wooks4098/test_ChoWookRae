#include<windows.h>
#include <math.h>
#define M_PI 3.14159265358979323846
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("HelloWorld");

bool isRight = true;
int x = 100, y = 0;
int timer_x = 600, timer_y = 400;
int Secound = 0;
int Minute = 0;
float Hour = 0;
bool MinuteCheck = false;
SYSTEMTIME st;
static TCHAR sTime[128];
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

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

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1, TimeProc);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//원 이동
		//Ellipse(hdc, x, y, x + 50, y + 50);

		//디지털 시계
		//TextOut(hdc, 0, 300, sTime, lstrlen(sTime));


		//아날로그 시계
		float Px, Py;
		MoveToEx(hdc, timer_x, timer_y, NULL);		
		Px = 100*cos(2* M_PI/60 *(Secound%60-15));
		Py = 100*sin(2 * M_PI / 60 * (Secound % 60 -15));
		LineTo(hdc, timer_x + Px, timer_y + Py);

		MoveToEx(hdc, timer_x, timer_y, NULL);
		Px = 70 * cos(2 * M_PI / 60 * (Minute % 60 - 15));
		Py = 70 * sin(2 * M_PI / 60 * (Minute % 60 - 15));
		LineTo(hdc, timer_x + Px, timer_y + Py);

		MoveToEx(hdc, timer_x, timer_y, NULL);
		Px = 45 * cos(2 * M_PI / 60 * (Hour - 15));
		Py = 45 * sin(2 * M_PI / 60 * (Hour  - 15));
		LineTo(hdc, timer_x + Px, timer_y + Py);



		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (x >= 200)
		isRight = false;
	else if (x <= 100)
		isRight = true;

	if (isRight)
		x += 5;
	else
		x -= 5;
	/*GetLocalTime(&st);
	wsprintf(sTime, TEXT("지금 시간은 %d시간 %d분 %d초 입니다."),
		st.wHour, st.wMinute, st.wSecond);*/

	Secound++;
	if (Secound % 60 == 0 && Secound != 0)
		Minute++;
	if (Minute % 5 == 0 && Minute != 0 && MinuteCheck == false)
	{
		MinuteCheck = true;
		Hour += 0.2083333f;
	}
	else if (Minute % 5 != 0)
		MinuteCheck = false;
	if (Hour == 365 && Hour != 0)
		Hour = 0;
	
	InvalidateRect(hWnd, NULL, TRUE);
}
