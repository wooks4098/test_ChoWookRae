#include "d3dUtility.h"

bool d3d::InitD3D(
	HINSTANCE hInstance,
	int width, int height,
	bool windowed,
	D3DDEVTYPE deviceType,
	IDirect3DDevice9** device,
	const char *appName)
{
	// 윈도우 클래스 생성.
	WNDCLASS wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;				// CS_HREDRAW | CS_VREDRAW : 클라이언트 영역의 폭과 높이가 변경되었을 경우 전부 다시 그리도록 해준다.
	wc.lpfnWndProc   = (WNDPROC)d3d::WndProc;				// 윈도우 프로시저 설정.
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

	// 윈도우 생성.
	HWND hwnd = 0;
	hwnd = ::CreateWindow("Direct3D9App",	// 클래스 이름, 위에 설정한 클레스 이름과 같아야 한다.
		appName,							// 윈도우 이름.
		WS_EX_TOPMOST,
		0, 0, width, height,				// 생성될 위치(x, y), 화면 해상도(width, height).
		0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/); 

	if( !hwnd )
	{
		::MessageBox(0, "CreateWindow() - FAILED", 0, 0);
		return false;
	}

	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);

	
	/////////////////////////////////////////////////////////////////////
	// D3D 초기화. //////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	HRESULT hr = 0;

	// 인터페이스 얻기.
	IDirect3D9* d3d9 = 0;
    d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

    if( !d3d9 )
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}


	// 버텍스 프로세싱 확인.
	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);

	int vp = 0;
	if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;	// 하드웨어 버텍스 프로세싱.
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;	// 소프트웨어 버텍스 프로세싱.
	 
	// d3d 구조체 생성.
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = width;							// 후면 버퍼의 크기.
	d3dpp.BackBufferHeight           = height;							// 화면 해상도와 같은크기로 생성.
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;					// 후면 버퍼의 픽셀 포맷(D3DFMT_A8R8G8B8 : 32-비트).
	d3dpp.BackBufferCount            = 1;								// 이용할 후면 버퍼의 수, 일반적으로 하나의 후면버퍼를 사용.
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;				// 후면 버퍼에 이용할 멀티 샘플링 타입.
	d3dpp.MultiSampleQuality         = 0;								// 멀티 샘플링 레벨.
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;			// 플리핑 체인지 버퍼가 교환되는 방식, D3DSWAPEFFECT_DISCARD를 지정하는 것이 가방 효과적.
	d3dpp.hDeviceWindow              = hwnd;							// 윈도우 핸들.
	d3dpp.Windowed                   = windowed;
	d3dpp.EnableAutoDepthStencil     = true;							// D3D가 자동으로 깊이/스텐실 버퍼를 만들고 관리하길 원하는가?
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;					// 깊이/스텐실 버퍼 포맷(D3DFMT_D24S8 : 24-비트 깊이 버퍼, 8-비트 스텐실 버퍼).
	d3dpp.Flags                      = 0;								// 부가적 특성(0 : 플래그 없음), 내용이 너무 길다.....
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;			// 풀 스크린모드일때 화면 갱신 속도(재생률).
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;	// 프레임 설정(D3DPRESENT_INTERVAL_IMMEDIATE : 기다리지 않고 항상 렌더링[프레임 무제한]).

	// 인터페이스 생성.
	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT,		// 현재 생성될 객체와 대응될 물리 디스플레이 어뎁터.
		deviceType,				// 장치 타입.
		hwnd,					// 장치와 연결된 윈도우 핸들.
		vp,						// 버텍스 프로세싱 타입.
	    &d3dpp,					// 시연 인자.
	    device);				// 생성된 장치.

	if( FAILED(hr) )
	{
		// 인터페이스 생성 실패.
		// 깊이/스텐실 버퍼 포맷에
		// 16-비트 깊이버퍼만을 사용하여
		// 인터페이스 재생성 시도.
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
	// 메시지 객체 생성.
	// 객체 메모리 초기화.
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)GetTickCount(); 

	// 게임 루프.
	// 게임 실행동안 메시지가 오든 오지 않든 계속해서 갱신.
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

			// 디스플레이 함수 호출.
			ptr_display(timeDelta);

			lastTime = currTime;
        }
    }
    return msg.wParam;
}
/////////////////////////////////////////////////////////////////////

// 각도에서 라디안으로 변환.
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