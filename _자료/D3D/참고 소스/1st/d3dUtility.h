#ifndef __d3dUtilityH__
#define __d3dUtilityH__

#include <d3dx9.h>
#include <string>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

namespace d3d
{
	bool InitD3D(
		HINSTANCE hInstance,		// [입력]응용프로그램 Instance 핸들.
		int width, int height,		// [입력]화면 해상도, 후면 버퍼 크기.
		bool windowed,				// [입력]Windowed (true)  full screen (false).
		D3DDEVTYPE deviceType,		// [입력]장치 타입(deviceType)을 D3DDEVTYPE_HAL(하드웨어 장치)또는 D3DDEVTYPE_REF(소프트웨어 장치)로 설정.
		IDirect3DDevice9** device,	// [출력]생성된 장치.
		const char *appName);

	int EnterMsgLoop( 
		bool (*ptr_display)(float timeDelta));	// 메시지 루프.

	LRESULT CALLBACK WndProc(
		HWND hwnd,
		UINT msg, 
		WPARAM wParam,
		LPARAM lParam);

	template<class T> void Release(T t)
	{
		if( t )
		{
			t->Release();
			t = 0;
		}
	}
		
	template<class T> void Delete(T t)
	{
		if( t )
		{
			delete t;
			t = 0;
		}
	}

	float DegToRad(float degree);

	const D3DXCOLOR A_WHITE(D3DCOLOR_ARGB(255, 255, 255, 255));
	const D3DXCOLOR A_BLACK(D3DCOLOR_ARGB(255, 0, 0, 0));
	const D3DXCOLOR A_RED(D3DCOLOR_ARGB(255, 255, 0, 0));
	const D3DXCOLOR A_GREEN(D3DCOLOR_ARGB(255, 0, 255, 0));
	const D3DXCOLOR A_BLUE(D3DCOLOR_ARGB(255, 0, 0, 255));

	const D3DXCOLOR A_YELLOW(D3DCOLOR_ARGB(255, 255, 255, 0));
	const D3DXCOLOR A_CYAN(D3DCOLOR_ARGB(255, 0, 255, 255));
	const D3DXCOLOR A_MAGENTA(D3DCOLOR_ARGB(255, 255, 0, 255));

	const D3DXCOLOR WHITE(D3DCOLOR_XRGB(255, 255, 255));
	const D3DXCOLOR BLACK(D3DCOLOR_XRGB(0, 0, 0));
	const D3DXCOLOR RED(D3DCOLOR_XRGB(255, 0, 0));
	const D3DXCOLOR GREEN(D3DCOLOR_XRGB(0, 255, 0));
	const D3DXCOLOR BLUE(D3DCOLOR_XRGB(0, 0, 255));

	const D3DXCOLOR YELLOW(D3DCOLOR_XRGB(255, 255, 0));
	const D3DXCOLOR CYAN(D3DCOLOR_XRGB(0, 255, 255));
	const D3DXCOLOR MAGENTA(D3DCOLOR_XRGB(255, 0, 255));

	D3DMATERIAL9 InitMtrl(D3DXCOLOR a, D3DXCOLOR d, D3DXCOLOR s, D3DXCOLOR e, float p);
	const D3DMATERIAL9 WHITE_MTRL = InitMtrl(WHITE, WHITE, WHITE, BLACK, 8.0f);
	const D3DMATERIAL9 RED_MTRL = InitMtrl(RED, RED, RED, BLACK, 8.0f);
	const D3DMATERIAL9 GREEN_MTRL = InitMtrl(GREEN, GREEN, GREEN, BLACK, 8.0f);
	const D3DMATERIAL9 BLUE_MTRL = InitMtrl(BLUE, BLUE, BLUE, BLACK, 8.0f);
	const D3DMATERIAL9 YELLOW_MTRL = InitMtrl(YELLOW, YELLOW, YELLOW, BLACK, 8.0f);
}

struct Vertex
{
	Vertex(float x, float y, float z,
		float nx, float ny, float nz,
		float u, float v)
	{
		_x = x, _y = y, _z = z;
		_nx = nx, _ny = ny, _nz = nz;
		_u = u, _v = v;
	}

	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;

	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;
};

//struct Normal : public Vertex
//{
//	Normal(float x, float y, float z,
//		float nx, float ny, float nz):Vertex(x, y, z)
//	{
//		_nx = nx, _ny = ny, _nz = nz;
//	}
//
//	float _nx, _ny, _nz;
//
//	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL;
//};

//struct ColorVertex
//{
//	ColorVertex();
//	ColorVertex(float x, float y, float z, D3DXCOLOR color)
//	{
//		_x = x, _y = y, _z = z;
//		_color = color;
//	}
//
//	float _x, _y, _z;
//	D3DXCOLOR _color;
//
//	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
//};

#endif // __d3dUtilityH__