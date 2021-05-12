#include "d3dUtility.h"

bool d3d::InitD3D(
	HINSTANCE hInstance,
	int width, int height,
	bool windowed,
	D3DDEVTYPE deviceType,
	IDirect3DDevice9** device,
	const char *appName)
{
	// ������ Ŭ���� ����.
	WNDCLASS wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;				// CS_HREDRAW | CS_VREDRAW : Ŭ���̾�Ʈ ������ ���� ���̰� ����Ǿ��� ��� ���� �ٽ� �׸����� ���ش�.
	wc.lpfnWndProc   = (WNDPROC)d3d::WndProc;				// ������ ���ν��� ����.
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = "Direct3D9App";

	if( !RegisterClass(&wc) )
	{
		::MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}

	// ������ ����.
	HWND hwnd = 0;
	hwnd = ::CreateWindow("Direct3D9App",	// Ŭ���� �̸�, ���� ������ Ŭ���� �̸��� ���ƾ� �Ѵ�.
		appName,							// ������ �̸�.
		WS_EX_TOPMOST,
		0, 0, width, height,				// ������ ��ġ(x, y), ȭ�� �ػ�(width, height).
		0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/); 

	if( !hwnd )
	{
		::MessageBox(0, "CreateWindow() - FAILED", 0, 0);
		return false;
	}

	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);

	
	/////////////////////////////////////////////////////////////////////
	// D3D �ʱ�ȭ. //////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	HRESULT hr = 0;

	// �������̽� ���.
	IDirect3D9* d3d9 = 0;
    d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

    if( !d3d9 )
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}


	// ���ؽ� ���μ��� Ȯ��.
	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);

	int vp = 0;
	if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;	// �ϵ���� ���ؽ� ���μ���.
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;	// ����Ʈ���� ���ؽ� ���μ���.
	 
	// d3d ����ü ����.
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = width;							// �ĸ� ������ ũ��.
	d3dpp.BackBufferHeight           = height;							// ȭ�� �ػ󵵿� ����ũ��� ����.
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;					// �ĸ� ������ �ȼ� ����(D3DFMT_A8R8G8B8 : 32-��Ʈ).
	d3dpp.BackBufferCount            = 1;								// �̿��� �ĸ� ������ ��, �Ϲ������� �ϳ��� �ĸ���۸� ���.
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;				// �ĸ� ���ۿ� �̿��� ��Ƽ ���ø� Ÿ��.
	d3dpp.MultiSampleQuality         = 0;								// ��Ƽ ���ø� ����.
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;			// �ø��� ü���� ���۰� ��ȯ�Ǵ� ���, D3DSWAPEFFECT_DISCARD�� �����ϴ� ���� ���� ȿ����.
	d3dpp.hDeviceWindow              = hwnd;							// ������ �ڵ�.
	d3dpp.Windowed                   = windowed;
	d3dpp.EnableAutoDepthStencil     = true;							// D3D�� �ڵ����� ����/���ٽ� ���۸� ����� �����ϱ� ���ϴ°�?
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;					// ����/���ٽ� ���� ����(D3DFMT_D24S8 : 24-��Ʈ ���� ����, 8-��Ʈ ���ٽ� ����).
	d3dpp.Flags                      = 0;								// �ΰ��� Ư��(0 : �÷��� ����), ������ �ʹ� ���.....
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;			// Ǯ ��ũ������϶� ȭ�� ���� �ӵ�(�����).
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;	// ������ ����(D3DPRESENT_INTERVAL_IMMEDIATE : ��ٸ��� �ʰ� �׻� ������[������ ������]).

	// �������̽� ����.
	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT,		// ���� ������ ��ü�� ������ ���� ���÷��� ���.
		deviceType,				// ��ġ Ÿ��.
		hwnd,					// ��ġ�� ����� ������ �ڵ�.
		vp,						// ���ؽ� ���μ��� Ÿ��.
	    &d3dpp,					// �ÿ� ����.
	    device);				// ������ ��ġ.

	if( FAILED(hr) )
	{
		// �������̽� ���� ����.
		// ����/���ٽ� ���� ���˿�
		// 16-��Ʈ ���̹��۸��� ����Ͽ�
		// �������̽� ����� �õ�.
		/*d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		
		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT,
			deviceType,
			hwnd,
			vp,
			&d3dpp,
			device);*/

		//if( FAILED(hr) )
		//{
			d3d9->Release();
			::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
			return false;
		//}
	}

	d3d9->Release();
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	return true;
}


/////////////////////////////////////////////////////////////////////
int d3d::EnterMsgLoop( bool (*ptr_display)(float timeDelta) )
{
	// �޽��� ��ü ����.
	// ��ü �޸� �ʱ�ȭ.
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)GetTickCount(); 

	// ���� ����.
	// ���� ���ൿ�� �޽����� ���� ���� �ʵ� ����ؼ� ����.
	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
        {	
			float currTime  = (float)GetTickCount();
			float timeDelta = (currTime - lastTime)*0.001f;

			// ���÷��� �Լ� ȣ��.
			ptr_display(timeDelta);

			lastTime = currTime;
        }
    }
    return msg.wParam;
}
/////////////////////////////////////////////////////////////////////

// �������� �������� ��ȯ.
float d3d::DegToRad(float degree)
{
	return (degree * D3DX_PI / 180.0f);
}

D3DMATERIAL9 d3d::InitMtrl(D3DXCOLOR a, D3DXCOLOR d, D3DXCOLOR s, D3DXCOLOR e, float p)
{
	D3DMATERIAL9 mtrl;
	mtrl.Ambient = a;
	mtrl.Diffuse = d;
	mtrl.Specular = s;
	mtrl.Emissive = e;
	mtrl.Power = p;

	return mtrl;
}