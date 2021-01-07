#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
char g_szClassName[256] = "RadioButton";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
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
	WndClass.lpszClassName = g_szClassName;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(g_szClassName, g_szClassName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return (int)Message.wParam;
}

enum 
{
	ID_R1 = 101,
	ID_R2,
	ID_R3,
	ID_R4,
	ID_R5,
	ID_R6,
};

HWND r1, r2, r3, r4, r5;
int Graph = 0;
COLORREF Color = RGB(0, 0, 0);

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH myBrush, oldBrush;

	switch (iMessage)
	{
		case WM_CREATE:

			CreateWindow(TEXT("button"), TEXT("Graph"), WS_CHILD | WS_VISIBLE |
				BS_GROUPBOX, 5, 5, 120, 110, hWnd, (HMENU)0, g_hInst, NULL);
			CreateWindow(TEXT("button"), TEXT("Color"), WS_CHILD | WS_VISIBLE |
				BS_GROUPBOX, 145, 5, 120, 110, hWnd, (HMENU)1, g_hInst, NULL);

			r1 = CreateWindow(TEXT("button"), TEXT("Rectangle"), WS_CHILD | WS_VISIBLE |
				BS_AUTORADIOBUTTON | WS_GROUP, 10, 20, 100, 30, hWnd, (HMENU)ID_R1, g_hInst, NULL);
			r2 = CreateWindow(TEXT("button"), TEXT("Ellipse"), WS_CHILD | WS_VISIBLE |
				BS_AUTORADIOBUTTON, 10, 50, 100, 30, hWnd, (HMENU)ID_R2, g_hInst, NULL);

			r3 = CreateWindow(TEXT("button"), TEXT("Rectangle"), WS_CHILD | WS_VISIBLE |
				BS_AUTORADIOBUTTON | WS_GROUP, 150, 20, 100, 30, hWnd, (HMENU)ID_R3, g_hInst, NULL);
			r4 = CreateWindow(TEXT("button"), TEXT("Ellipse"), WS_CHILD | WS_VISIBLE |
				BS_AUTORADIOBUTTON, 150, 50, 100, 30, hWnd, (HMENU)ID_R4, g_hInst, NULL);
			r5 = CreateWindow(TEXT("button"), TEXT("Rectangle"), WS_CHILD | WS_VISIBLE |
				BS_AUTORADIOBUTTON, 150, 80, 100, 30, hWnd, (HMENU)ID_R5, g_hInst, NULL);

			CheckRadioButton(hWnd, ID_R1, ID_R2, ID_R1);
			CheckRadioButton(hWnd, ID_R3, ID_R5, ID_R3);

			return 0;

		case WM_COMMAND:

			switch(LOWORD(wParam))
			{
				case ID_R1:
					Graph = 0;
					break;
				case ID_R2:
					Graph = 1;
					break;
				case ID_R3:
					Color = RGB(0, 0, 0);
					break;
				case ID_R4:
					Color = RGB(255, 0, 0);
					break;
				case ID_R5:
					Color = RGB(0, 0, 255);
					break;
			}
			InvalidateRect(hWnd, NULL, TRUE);
			return 0;
		
		case WM_PAINT:

			hdc = BeginPaint(hWnd, &ps);
			
			myBrush = CreateSolidBrush(Color);
			oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

			switch(Graph)
			{
				case 0:
					Rectangle(hdc, 10, 200, 200, 300);
					break;
				case 1:
					Ellipse(hdc, 10, 200, 200, 300);
					break;
			}

			SelectObject(hdc, oldBrush);
			DeleteObject(myBrush);
			EndPaint(hWnd, &ps);

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);

			return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
