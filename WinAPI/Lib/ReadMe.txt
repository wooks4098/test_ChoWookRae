========================================================================
    STATIC LIBRARY : JEngine Project Overview
========================================================================

											author : classicaa@naver.com

JEngine�� ���Ӿ�Ʈ�п� ���������� ������� �����Դϴ�.

WinAPI������ �����Ҽ� �ִ� ��������
�⺻ ȭ�� ������ Scene�������� ���� �˴ϴ�.

���� ��ü�� SceneManager , ResoucesManager , InputManager �� �̱������� �����˴ϴ�.

������ ������ FrameWorkLib ������Ʈ�� �����ϼ���.

Scene ��ü�� 
	virtual void Init(HWND hWnd) = 0;
	virtual bool Input() = 0;
	virtual void Update() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void Release() = 0;
�ټ������� ���� �����Լ��� ������ �ֽ��ϴ�. Scene��ü�� ��ӹ޾� �������ּ���.
(Input �޼ҵ��� ���ϰ��� ture�� �ѱ�� ������ ����˴ϴ�.)

BitMap ��ü�� �÷�Ű ��Ʈ���� Draw�� �����ϰ� Anchor����Ʈ�� �����մϴ�.

InputManager ��ü�� �⺻ VK�� �Է��Ͽ� �ش�Ű�� �� �ٿ� ���������¸� üũ�մϴ�.

POINT ��ü POINT RECT���� ��ü�� Ŭ����ȭ�Ѱ� �Դϴ�.

ResoucesManager ��ü�� BitmapŬ������ �Ҵ�� ���縦 ����ϰ� Back���۸� �����մϴ�.

/////////////////////////////////////////////////////////////////////////////
Other notes:


/////////////////////////////////////////////////////////////////////////////

