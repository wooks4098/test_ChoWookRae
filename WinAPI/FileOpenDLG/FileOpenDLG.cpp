#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("FileOpenDLG");

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

TCHAR buf[1024] = TEXT("abcde");

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		return 0;

	
	//�⺻ ���
	case WM_LBUTTONDOWN:
	{
		OPENFILENAME OFN;
		char str[300];
		char lpstrFile[MAX_PATH] = "";
		char lpstrPath[MAX_PATH] = "";

		memset(&OFN, 0, sizeof(OPENFILENAME));
		OFN.lStructSize = sizeof(OPENFILENAME);
		OFN.hwndOwner = hWnd;
		OFN.lpstrFilter = "Every File(*.*)\0*.*\0Text File\0*.txt;*.doc\0";
		OFN.lpstrFile = lpstrFile;
		OFN.nMaxFile = 256;

		//���� ������ ��θ� ���´�(���ø����̼��� ����Ǵ�)
		GetCurrentDirectory(MAX_PATH, lpstrPath);

		OFN.lpstrInitialDir = lpstrPath;

		//OPENFILENAME ����ü�� ���Ͽ��� ��ȭâ�� ���� �ش������� ���ԵǸ�..
		if (GetOpenFileName(&OFN) != 0)
		{
			wsprintf(str, "%s ������ �����߽��ϴ�.", OFN.lpstrFile);
			MessageBox(hWnd, str, "���� ���� ����", MB_OK);
		}
	}
		return 0;
	case WM_DESTROY:

		PostQuitMessage(0);

		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
