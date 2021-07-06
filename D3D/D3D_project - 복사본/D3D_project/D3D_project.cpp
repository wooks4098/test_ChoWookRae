/*
        기본세팅 변경 후 사용

⁻ [포함 디렉터리]에서 <편집…>을 선택
⁻ 리스트 박스에 보이는 폴더 모양의 버튼을 선택 후, […]버튼 선택
⁻ 설치해둔 SDK의 [Include폴더]를 지정
⁻ 최신 DirectX SDK가 WindowsSDK에 포함되어 있다


[VC++ 디렉터리]의 [라이브러리 디렉터리] or
[링커]/[일반]의 [추가 라이브러리 디렉터리]에 [포함 디렉터리]에서 했던 것 처럼
Lib폴더를 연결하면 된다


라이브러리 연결/링크 하기
⁻ 소스 코드를 이용하거나 속성에서 직접 추가하는 2가지 방법이 있다
⁻ 라이브러리는 d3d9.lib와 d3dx9.lib를 추가하며, .h(헤더)파일을 추가해야만
사용이 가능하다
*/
#include "framework.h"
#include "D3D_project.h"
#include <d3d9.h>
#include <d3dx9.h>
#define MAX_LOADSTRING 100
#define D3DFVF_CUSTOM (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#define Deg2Rad 0.017453293f

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

LPDIRECT3D9 g_pD3D = NULL; // D3D Device를 생성할 D3D 객체 변수. 전역 변수.
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL; // 렌더링에 사용될 D3D Device. 전역 변수.

LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL; // 정점 버퍼. 전역변수.

D3DXMATRIXA16 g_matEarth, g_matMoon; 


struct CUSTOMVERTEX
{
    float x, y, z; // 정점의 좌표.
    DWORD color; // 정점의 색깔.
};

LPDIRECT3DINDEXBUFFER9 g_pIB = NULL; // 인덱스 버퍼. 전역 변수.
struct INDEX
{
    WORD _0, _1, _2;
};

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

HRESULT InitD3D(HWND hWnd);

#pragma region 함수선언
void Cleanup();
void Render();
HRESULT InitVertexBuffer();
void SetupMatrices();
HRESULT InitIndexBuffer();
void Update();
void DrawMesh(const D3DXMATRIXA16& matrix);
#pragma endregion



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_D3DPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    if (SUCCEEDED(InitD3D(hWnd)))
    {
        if (SUCCEEDED(InitVertexBuffer()))
        {
            if (SUCCEEDED(InitIndexBuffer()))
            {
                ShowWindow(hWnd, nCmdShow);
                UpdateWindow(hWnd);

                MSG msg;
                ZeroMemory(&msg, sizeof(msg));
                ULONGLONG frameTime, limitFrameTime = GetTickCount64();
                while (WM_QUIT != msg.message)
                {
                    if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
                    {
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                    }
                    else
                    {
                        Update();
                        Render();
                    }
                }
            }
        }


    }

    return 0;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_D3DPROJECT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        Cleanup();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Direct3D 초기화.
HRESULT InitD3D(HWND hWnd)
{
    // Device를 생성하기 위한 D3D객체.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) return E_FAIL;
    // Device 생성을 위한 구조체.
    // Present는 백 버퍼의 내용을 스크린에 보여주는 작업을 한다.
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp)); // 메모리의 쓰레기 값을 반드시 지원야 한다.
    d3dpp.Windowed = TRUE; // 창 모드로 생성.
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // 가장 효율적인 SWAP 효과. 백 버퍼의 내용을 프론트 버퍼로 Swap하는 방식.
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // 런타임에, 현재 디스플레이 모드에 맞춰 백 버퍼를 생성.
    
    DWORD level;
    for (auto type = (int)D3DMULTISAMPLE_16_SAMPLES; 0 < type; type--)
    {
        if (SUCCEEDED(g_pD3D->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_D16, FALSE, (D3DMULTISAMPLE_TYPE)type, &level)))
        {
            d3dpp.MultiSampleQuality = level - 1;
            d3dpp.MultiSampleType = (D3DMULTISAMPLE_TYPE)type;
            break;
        }
    }

    // Device 생성.
    // D3DADAPTER_DEFAULT : 기본 그래픽카드를 사용.
    // D3DDEVTYPE_HAL : 하드웨어 가속장치를 지원한다(그래픽카드 제조사에서 DirectX가 세부적인 부분을 제어할 필요가 없도록 지원하는 기능).
    // D3DCREATE_SOFTWARE_VERTEXPROCESSING : 정점(Vertex) 쉐이더 처리를 소프트웨어에서 한다(하드웨어에서 할 경우 더욱 높은 성능을 발휘:D3DCREATE_HARDWARE_VERTEXPROCESSING)
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }
    // TODO: 여기에서 Device 상태 정보 처리를 처리를 한다.
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링 모들를 켠다.
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE); // 광원 기능을 끈다.
    d3dpp.EnableAutoDepthStencil = TRUE; // D3D에서 프로그램의 깊이 버퍼(Z-Buffer)를 관리하게 한다.
// 깊이 버퍼:화면에 그려질 각 픽셀의 z(깊이) 값을 저장하기위한 버퍼. 주로 절두체에서 픽셀의 깊이 값을 기록하는데 사용.
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16; // 16비트의 깊이 버퍼를 사용.
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE); // Z(깊이) 버퍼 기능을 켠다
    // 컬링 모들를 켠다.
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
    // 멀티 생플링이 가능하면 기능을 활성화 하고, 아니면 끈다.
    g_pd3dDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, (0 < d3dpp.MultiSampleType));

    return S_OK;
}

// 초기화된 객체를 해제.
void Cleanup()
{
    // 반드시 생성의 역순으로 해제.
    if (NULL != g_pIB) g_pIB->Release();
    if (NULL != g_pVB) g_pVB->Release();
    if (NULL != g_pd3dDevice) g_pd3dDevice->Release();
    if (NULL != g_pD3D) g_pD3D->Release();
}

void Render()
{
    if (NULL == g_pd3dDevice) return;
    // pRects(두 번째 인자)가 NULL이라면 Count(첫 번째 인자)는 0.
    // D3DCLEAR_TARGET:surface를 대상으로 한다.
    // D3DCLEAR_ZBUFFER:Z(깊이) 버퍼를 대상으로 한다.
    // 버퍼를 파란색[RGB(0, 0, 255)]으로 지운다.
    // Z(깊이) 버퍼를 1로 지운다. (0 ~ 1 사이의 값을 사용)
    // 스텐실(stencil) 버퍼를 0으로 지운다. (0 ~ 2^n-1 사이의 값을 사용)
    // 다음과 같은 경우 IDirect3DDevice9 :: Clear() 함수가 실패.
    // - 깊이 버퍼가 연결되지 않은 렌더링 대상의 깊이 버퍼 또는 스텐실 버퍼를 지운다.
    // - 깊이 버퍼에 스텐실 데이터가 포함되지 않은 경우 스텐실 버퍼를 지운다.
    if (SUCCEEDED(g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0)))
    {
        SetupMatrices();
        // 렌더링 시작, 폴리곤을 그리겠다고 D3D에 알림(BeginScene).
        if (SUCCEEDED(g_pd3dDevice->BeginScene()))
        {
            //// 정점의 정보가 담긴 정점 버퍼를 출력 스트림으로 할당.
            //g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
            //// D3D에 정점 쉐이더 정보를 지정. / 대부분의 경우 FVF만 지정한다.
            //// FVF는 정점 버퍼를 만들때 정의한 값과 같아야 한다.
            //g_pd3dDevice->SetFVF(D3DFVF_CUSTOM);
            //// DrawPrimitive() 함수를 호출하여 출력한다.
            //// D3DPT_TRIANGLELIST:정점을 이어 삼각형을 그린다.
            //// 0 번째의 정점 값부터 사용.
            //// 삼각형을 1개 그린다.
            //g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

            //// 인덱스 버퍼를 지정.
            //g_pd3dDevice->SetIndices(g_pIB);
            //// 정점 버퍼 8개로 12개의 폴리곤을 그린다.
            //g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

            //계층구조
            DrawMesh(g_matEarth);
            DrawMesh(g_matMoon);

            // 렌더링 종료.
            g_pd3dDevice->EndScene();
        }
        // 백 버퍼를 보이는 화면으로 전환.
        g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
    }
}

HRESULT InitVertexBuffer()
{
    CUSTOMVERTEX vertices[] =
    {
        // 상자(Cube)를 그리기 위한 8개의 정점.
        { -1, 1, 1, 0xffff0000 }, // v0
        { 1, 1, 1, 0xff00ff00 }, // v1
        { 1, 1, -1, 0xff0000ff }, // v2
        { -1, 1, -1, 0xffffff00 }, // v3
        { -1, -1, 1, 0xff00ffff }, // v4
        { 1, -1, 1, 0xffff00ff }, // v5
        { 1, -1, -1, 0xff000000 }, // v6
        { -1, -1, -1, 0xffffffff }, // v7
    };
    // 정점 버퍼 생성.
    // 정점을 보관할 메모리 공간을 할당.
    // FVF를 지정하여 보관할 데이터 형식을 지정.
    // D3DPOOL_DEFAULT:리소스가 가장 적합한 메모리에 놓여진다.
    if (FAILED(g_pd3dDevice->CreateVertexBuffer(sizeof(vertices), 0, D3DFVF_CUSTOM, D3DPOOL_DEFAULT, &g_pVB, NULL)))
    {
        return E_FAIL;
    }
    // 정점 버퍼를 지정한 값으로 채운다.
    // 외부에서 접근하지 못하게 메모리를 Lock() 하고 사용이 끝난 후 Unlock()을 한다.
    LPVOID pVertices;
    if (FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0))) return E_FAIL;
    memcpy(pVertices, vertices, sizeof(vertices));
    g_pVB->Unlock();
    return S_OK;
}

void SetupMatrices()
{
    // 월드 스페이스.
    D3DXMATRIXA16 matWorld; // 월드 행렬.

    // D3DXMatrixTranslation
    // D3DXMatrixRotationX,Y,Z
    // D3DXMatrixScaling
    // 등의 작업을 여기서 수행.
    D3DXMatrixIdentity(&matWorld); // 단위행렬로 변경.
    // 좌표를 (0, 0, 0) 변경.
    // D3DXMatrixTranslation(& matWorld, 0, 0, 0);
    g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld); // 월드 스페이스로 변환.
    // 뷰 스페이스.
    D3DXVECTOR3 vEyePt(3.0f, 3.0f, -5.0f); // 월드 좌표의 카메라의 위치.
    D3DXVECTOR3 vLookAtPt(0.0f, 0.0f, 0.0f); // 월드 좌표의 카메라가 바라보는 위치.
    D3DXVECTOR3 vUpVector(0.0f, 0.1f, 0.0f); // 월드 좌표의 하늘 방향을 알기 위한 up vector.
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookAtPt, &vUpVector); // 뷰 변환 행렬 계산.
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView); // 뷰 스페이스로 변환.
    
    // 투영.
    D3DXMATRIXA16 matProj;
    // 투영 변환 행렬 계산.
    // FOV:시야각. 45도(D3DX_PI/4 == 45 * Deg2Rad).
    // 1.77f:종횡비. 1.0f(1:1), 1.33f(4:3), 1.77f/1.78f(16:9), 2.0f(18:9).......
    // 시야 거리는 1.0f(near)에서 100.0f(far)까지.
    D3DXMatrixPerspectiveFovLH(&matProj, 45 * Deg2Rad, 1.77f, 1.0f, 100.0f);
    g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj); // 투영 변환.
}

HRESULT InitIndexBuffer()
{
    INDEX indices[] =
    {
        // 상자(Cube)를 그리기 위한 12개의 면(폴리곤의 개수) 선언.
        { 0, 1, 2 }, { 0, 2, 3 }, // 윗면.
        { 4, 6, 5 }, { 4, 7, 6 }, // 아랫면.
        { 0, 3, 7 }, { 0, 7, 4 }, // 왼쪽면.
        { 1, 5, 6 }, { 1, 6, 2 }, // 오른쪽면.
        { 3, 2, 6 }, { 3, 6, 7 }, // 앞면.
        { 0, 4, 5 }, { 0, 5, 1 }, // 뒷면.
    };
    // 인덱스 버퍼 생성.
    // D3DFMT_INDEX16:인덱스의 단위가 16비트. WORD(unsigned short):2byte(16bit).
    if (FAILED(g_pd3dDevice->CreateIndexBuffer(sizeof(indices), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_pIB, NULL))) return E_FAIL;
    LPVOID pIndices;
    if (FAILED(g_pIB->Lock(0, sizeof(indices), (void**)&pIndices, 0))) return E_FAIL;
    memcpy(pIndices, indices, sizeof(indices));
    g_pIB->Unlock();
    return S_OK;
}

void DrawMesh(const D3DXMATRIXA16& matrix)
{
    g_pd3dDevice->SetTransform(D3DTS_WORLD, &matrix); g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
    g_pd3dDevice->SetFVF(D3DFVF_CUSTOM);
    g_pd3dDevice->SetIndices(g_pIB);
    g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}

void Update()
{
    auto angle = GetTickCount64() * 0.001f;
    D3DXMATRIXA16 matEarthTr, matEarthRo;
    D3DXMATRIXA16 matMoonTr, matMoonRo, matMoonSc;
    D3DXMatrixTranslation(&matEarthTr, 0, 0, 0);
    D3DXMatrixRotationY(&matEarthRo, angle);
    // 회전(자전) * 이동.
    g_matEarth = matEarthRo * matEarthTr;
    D3DXMatrixRotationY(&matMoonRo, angle * 0.5f);
    D3DXMatrixScaling(&matMoonSc, 0.5f, 0.5f, 0.5f);
    D3DXMatrixTranslation(&matMoonTr, 5, 0, 0);
    // 크기 변경 * 이동 * 회전(공전) * 부모의 정보 추가.
    g_matMoon = matMoonSc * matMoonTr * matMoonRo * g_matEarth;
}