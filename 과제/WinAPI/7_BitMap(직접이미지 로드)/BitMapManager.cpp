#include "BitMapManager.h"
BitMapManager* BitMapManager::m_pThis = NULL;




void BitMapManager::SetImage(HWND hWnd)
{

	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);
	std::string name;
	for (int i = 0; i < 11; i++)
	{
		wsprintf(buf, L"ReSource//0%d.bmp", i);
		switch (i)
		{
		case 0:
			name = DOG;
			break;
		case 1:
			name = TIGER;
			break;
		case 2:
			name = DUCK;
			break;
		case 3:
			name = ELEPHONT;
			break;
		case 4:
			name = COW;
			break;
		case 5:
			name = HORSE;
			break;
		case 6:
			name = CAT;
			break;
		case 7:
			name = MONKEY;
			break;
		case 8:
			name = FROG;
			break;
		case 9:
			name = CHICKEN;
			break;
		case 10:
			name = BLACK;
			break;
		}
		Load_Image(hdc, buf, name);
	}

}


void BitMapManager::Load_Image(HDC hdc, LPCWSTR FileName, std::string name)
{
	Bitmap bit;
	bit.CreatImage(hdc, FileName);
	Image.insert(std::make_pair(name, bit));
}


void BitMapManager::Draw(HDC hdc, int x, int y, float spX, float spY, std::string name)
{
	std::map<std::string, Bitmap>::iterator iter = Image.find(name);
	iter->second.Draw(hdc, x, y, spX, spY);
}

SIZE BitMapManager::GetSize(std::string name)
{
	std::map<std::string, Bitmap>::iterator iter = Image.find(name);

	return iter->second.GetSize();
}









