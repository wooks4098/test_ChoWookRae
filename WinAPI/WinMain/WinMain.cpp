#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
LPCTSTR lpszClass = TEXT("HelloWorld"); //â�̸�

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;

	//1. ������ Ŭ���� ����
		WNDCLASS WndClass; 
		g_hInst = hInstance;
		//WndClass�� �⺻ ������ȯ���� ����� ����ü��. �ɹ������� �ؿ��� ����.
		WndClass.cbClsExtra = 0; //���࿵�� (�Ű�x)
		WndClass.cbWndExtra = 0; //���࿵�� (�Ű�x)
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //����
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	//Ŀ��
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ ���
		WndClass.hInstance = hInstance;//(���α׷� �ڵ鰪(��ȣ)���)
		WndClass.lpfnWndProc = WndProc;	//���μ��� �Լ� ȣ��
		WndClass.lpszClassName = lpszClass;	//Ŭ���� �̸�
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;//�������� ������ ������ ���� �� �ٽ� �׸���. (Ȯ�� ���� �Ұ��� ���ϱ�)

	//2. ������ Ŭ���� ���
		RegisterClass(&WndClass);  //������� WidClass�� ���


	//3. ������ ����
		hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);



	//4. �����츦 ȭ�鿡 ǥ��
		ShowWindow(hWnd, nCmdShow); //�����츦 ȭ�鿡 ǥ��
		


	//5. �޽����� �޾� ó��
		while (GetMessage(&Message, NULL, 0, 0))//����ڿ��� �޽����� �޾ƿ��� �Լ�(WM_QUIT �޽��� ���� �� ����)
		{
			TranslateMessage(&Message); //  Ű���� �Է� �޽��� ó���Լ�
			DispatchMessage(&Message); //���� �޽����� WndProc�� �����ϴ� �Լ�
		}



		return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:// �����찡 �ı��Ǿ��ٴ� �޼���
		PostQuitMessage(0); //GetMessage�Լ��� WM_QUIT �޽����� ������.
		return 0; //WndProc�� Switch�� break ��� return 0; �� ����.
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case�� �ִ� �޽����� ������ ������ �޽����� ó���Ѵ�.
}