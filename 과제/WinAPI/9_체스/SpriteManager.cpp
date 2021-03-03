#include "SpriteManager.h"
SpriteManager* SpriteManager::m_pThis = NULL;




void SpriteManager::SetImage(HWND hWnd)
{

	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);
	std::string name;
	for (int i = 0; i < RESOURCE_COUNT; i++)
	{
		
		switch (i)
		{
		case 0:
		case 1:
		case 2:
			wsprintf(buf, L"ReSource//block0%d.bmp", i);
			break;
		case 3:		
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			wsprintf(buf, L"ReSource//block_b_0%d.bmp", i);
			break;
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			wsprintf(buf, L"ReSource//block_w_0%d.bmp", i);
			break;
		}
		Load_Image(hdc, buf, i);
	}

}


void SpriteManager::Load_Image(HDC hdc, LPCWSTR FileName,int Piece_Number)
{
	Sprite Sp;
	Sp.CreatImage(hdc, FileName);
	sprite[Piece_Number] = Sp;
}


void SpriteManager::Draw(HDC hdc, float x, float y, float spX, float spY, int Piece_Number, bool Transparent)
{
	sprite[Piece_Number].Draw(hdc, x, y, spX, spY, Transparent);

}

//SIZE SpriteManager::GetSize(std::string name)
//{
//	std::map<std::string, Bitmap>::iterator iter = Image.find(name);
//
//	return iter->second.GetSize();
//}
