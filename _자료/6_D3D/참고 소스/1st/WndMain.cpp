#include "d3dUtility.h"

IDirect3DDevice9* Device = 0;

IDirect3DVertexBuffer9* VB = 0;
IDirect3DIndexBuffer9* IB = 0;

IDirect3DTexture9* Texture = 0;

ID3DXMesh *Teapot = 0;
D3DMATERIAL9 TeapotMtrl;

const int Width = 1280;
const int Height = 720;

const char *AppName = "MyProject";

bool Setup()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////������ �׸���, �ؽ��� ������///////////////////////////////////////////
	/// �ؽ��ĸ� ������ ���� ���ؽ� ���ۿ� ���� �Է� ����.
	/// �޸� ���� ���� ���Ͽ� �ε��� ���� ���.
	/// �ؽ��� �ҷ��� ������.
	Device->CreateVertexBuffer(
		8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_DEFAULT,
		&VB,
		0);

	Device->CreateIndexBuffer(
		36 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX32,
		D3DPOOL_DEFAULT,
		&IB,
		0);


	Vertex* vertices;
	VB->Lock(0, 0, (void**)&vertices, 0);
	vertices[0] = Vertex(-1.0f, -1.0f, -1.0f, -0.333f, -0.333f, -0.333f, 0.0f, 1.0f);
	vertices[1] = Vertex(-1.0f,  1.0f, -1.0f, -0.333f, 0.333f, -0.333f, 0.0f, 0.0f);
	vertices[2] = Vertex( 1.0f,  1.0f, -1.0f, 0.333f, 0.333f, -0.333f, 1.0f, 0.0f);
	vertices[3] = Vertex( 1.0f, -1.0f, -1.0f, 0.333f, -0.333f, -0.333f, 1.0f, 1.0f);
	vertices[4] = Vertex(-1.0f, -1.0f,  1.0f, -0.333f, -0.333f, 0.333f, 0.0f, 0.0f);
	vertices[5] = Vertex(-1.0f,  1.0f,  1.0f, -0.333f, 0.333f, 0.333f, 0.0f, 1.0f);
	vertices[6] = Vertex( 1.0f,  1.0f,  1.0f, 0.333f, 0.333f, 0.333f, 1.0f, 1.0f);
	vertices[7] = Vertex( 1.0f, -1.0f,  1.0f, 0.333f, -0.333f, 0.333f, 1.0f, 0.0f);
	VB->Unlock();

	DWORD* indices = 0;
	IB->Lock(0, 0, (void**)&indices, 0);
	// ����.
	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;
	// �ĸ�.
	indices[6] = 4; indices[7] = 6; indices[8] = 5;
	indices[9] = 4; indices[10] = 7; indices[11] = 6;
	// ����.
	indices[12] = 4; indices[13] = 5; indices[14] = 1;
	indices[15] = 4; indices[16] = 1; indices[17] = 0;
	// ����.
	indices[18] = 3; indices[19] = 2; indices[20] = 6;
	indices[21] = 3; indices[22] = 6; indices[23] = 7;
	// ���.
	indices[24] = 1; indices[25] = 5; indices[26] = 6;
	indices[27] = 1; indices[28] = 6; indices[29] = 2;
	// �ϴ�.
	indices[30] = 4; indices[31] = 0; indices[32] = 3;
	indices[33] = 4; indices[34] = 3; indices[35] = 7;
	IB->Unlock();

	D3DXCreateTextureFromFile(
		Device,
		"crate.jpg",
		&Texture);

	// �ؽ��� ���͸� ����.
	Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC);	// D3DTEXF_LINEAR
	Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);	// D3DTEXF_LINEAR
	Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////����Ʈ ��� ����///////////////////////////////////////////////////////
	// ����Ʈ�� Ȱ��ȭ.
	Device->SetRenderState(D3DRS_LIGHTING, true);

	// direction ����Ʈ�� ����.
	D3DLIGHT9 dir;
	dir.Type = D3DLIGHT_DIRECTIONAL;
	dir.Diffuse = d3d::WHITE;
	dir.Specular = d3d::WHITE * 0.6f;
	dir.Ambient = d3d::WHITE * 0.4f;
	dir.Direction = D3DXVECTOR3(1.0f, 0.0f, 0.0f);

	// ����Ʈ ����, ����Ʈ�� ���.
	Device->SetLight(0, &dir);
	Device->LightEnable(0, true);

	// ī�޶� ��ġ, ���� ����.
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX view;
	D3DXMatrixLookAtLH(&view, &position, &target, &up);
	Device->SetTransform(D3DTS_VIEW, &view);

	// ������ ����, ���ݻ籤�� Ȱ��ȭ.
	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, true);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////���� ����//////////////////////////////////////////////////////////
	/// ���� ���� �׽�Ʈ�� ���� Ƽ�� �޽� ����.
	/// ���� ���� ����.
	///
	// Ƽ���� material�� ����.
	TeapotMtrl = d3d::RED_MTRL;
	TeapotMtrl.Diffuse.a = 0.5f;

	// Ƽ�� �޽��� ����.
	D3DXCreateTeapot(Device, &Teapot, 0);

	// ���ĸ� ����ϱ� ���� material�� diffuse ������Ʈ ������ ���ĸ� ���.
	Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);	// D3DTA_TEXTURE : �ؽ��� ���� ���� ü���� �̿�.
	Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	// ���� �μ��� �����Ͽ� ���� ������ �����ϵ��� �Ѵ�.
	Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////�������� ����//////////////////////////////////////////////////////////
	// ����(��������) ��� ����.
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,							// [���]����(��������) ���.
		d3d::DegToRad(90.0f),			// �þ߰��� ��������, y ���⿡�� �þ�.
		((float)Width/(float)Height),	// ��Ⱦ�� = �ʺ� / ����.
		1.0f,							// ����� �� ����� Z ��, near.
		1000.0f);						// �� �� ����� Z ��, far.
	Device->SetTransform(D3DTS_PROJECTION, &proj);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// ������ ���� ����.
	// ���̵� ���, �� ���̵�.
	Device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_PHONG);

	return true;
}

void Cleanup()
{
	d3d::Release<IDirect3DVertexBuffer9*>(VB);
	d3d::Release<IDirect3DIndexBuffer9*>(IB);	
}

float y = 0.0f;
float rate = 0.0f;
bool Display(float timeDelta)
{
	if(Device)
	{
		// �Թ�ü ȸ��.
		D3DXMATRIX Rx, Ry;

		// x������ 45�� ȸ��.
		D3DXMatrixRotationX(&Rx, d3d::DegToRad(45.0f));

		// �� �����Ӵ� y ȸ���� ����.
		D3DXMatrixRotationY(&Ry, y);
		y += timeDelta;
		if(6.28f <= y) y = 0.0f;

		// ȸ�� ����.
		D3DXMATRIX world = Rx * Ry;
		Device->SetTransform(D3DTS_WORLD, &world);

		if(rate >= 0.1f)
		{
			rate = 0;
			if(::GetAsyncKeyState('A') & 0x8000f) TeapotMtrl.Diffuse.a += 0.1f;
			if(::GetAsyncKeyState('S') & 0x8000f) TeapotMtrl.Diffuse.a -= 0.1f;

			if(TeapotMtrl.Diffuse.a > 1.0f) TeapotMtrl.Diffuse.a = 1.0f;
			if(TeapotMtrl.Diffuse.a < 0.0f) TeapotMtrl.Diffuse.a = 0.0f;
		}
		rate += timeDelta;

		// D3DCLEAR_TARGET(���� ��� ǥ��, �ĸ� ����)��
		// D3DCLEAR_ZBUFFER(���� ����)��
		// 0x00000000(������)���� �����.
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000,
			1.0f/*���� ���ۿ� �����ϰ��� �ϴ� ��, D3D������ 1�� ���� ��.*/,
			0/*���ٽ� ���ۿ� �����ϰ��� �ϴ� ��*/);

		Device->BeginScene();

		////////////////////////////////////////////////////////////////////////////////////////
		/// ������ �ؽ��Ŀ� Material�� Ȱ��ȭ �Ѵ�.
		///
		Device->SetTexture(0, Texture);
		// ���� ����.
		Device->SetMaterial(&d3d::WHITE_MTRL);
		////////////////////////////////////////////////////////////////////////////////////////

		Device->SetStreamSource(0, VB, 0, sizeof(Vertex));
		Device->SetIndices(IB);
		Device->SetFVF(Vertex::FVF);
		Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

		///////////////////////////////////////////////////////////////////
		Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

		D3DXMatrixScaling(&world, 1.5f, 1.5f, 1.5f);
		Device->SetTransform(D3DTS_WORLD, &world);
		Device->SetMaterial(&TeapotMtrl);
		Device->SetTexture(0, 0);
		Teapot->DrawSubset(0);

		Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		///////////////////////////////////////////////////////////////////

		Device->EndScene();

		Device->Present(0, 0, 0, 0);		//�ĸ� ���� �ÿ�.
	}
	return true;
}

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance,
				   PSTR cmdLine,
				   int showCmd)
{
	if(!d3d::InitD3D(hinstance, Width, Height, true, D3DDEVTYPE_HAL, &Device, AppName))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if(!Setup())
	{
		::MessageBox(0, "Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if(wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}