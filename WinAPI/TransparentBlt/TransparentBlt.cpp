#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TransparentBlt");

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
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass); 
			 
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, (HMENU)NULL, hInstance, NULL); 

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
	HBITMAP hImage, hOldBitmap;
	int bx, by;
	BITMAP bit;

	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hdc); 
								  
		hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
			IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);

		GetObject(hImage, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;

		//���� �״��
		//ȭ���� (50, 50) ��ġ�� ���� ũ��� ������ (0, 0) ��ġ���� �����Ͽ� �׸���
		BitBlt(hdc, 50, 50, bx, by, hMemDC, 0, 0, SRCCOPY);

		//����ó��
		//RGB(255, 0, 255)(��ũ��)�� �����ϰ� ����� �׸���
		TransparentBlt(hdc, 350, 50, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

		//����ó���� �κб׸���
		//�̹����� ������ ���� �ְ� �ѹ��� ������ ĳ���͸� �׸���
		TransparentBlt(hdc, 650, 50, bx / 4, by / 4,
			hMemDC, (bx / 4) * 1, (by / 4) * 2, bx / 4, by / 4, RGB(255, 0, 255));

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