#include "BitMapManager.h"
BitMapManager* BitMapManager::m_pThis = NULL;



BitMapManager::BitMapManager()
{
}

void BitMapManager::Draw(HDC hdc, RECT rect, int FileName, int Frame, int Direction)
{
	bitmap[FileName].Draw(hdc, rect,Frame,Direction);

}



void BitMapManager::Draw(HDC hdc, RECT rect, int FileName)
{
	bitmap[FileName].Draw(hdc, rect);
}


void BitMapManager::CreatImage(HWND hWnd)
{
	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);

	for (int i = 0; i < RESOURCE; i++)
	{
		switch (i)
		{											   
		case 0:										   
			wsprintf(buf, L"ReSource//back.bmp");
			break;									   
		case 1:										   
			wsprintf(buf, L"ReSource//back_deco.bmp");
			break;								  
		case 2:									  
			wsprintf(buf, L"ReSource//back_normal.bmp");
			break;								  
		case 3:									  
			wsprintf(buf, L"ReSource//back_normal2.bmp");
			break;								  
		case 4:									  
			wsprintf(buf, L"ReSource//cash.bmp");
			break;								  
		case 5:									  
			wsprintf(buf, L"ReSource//die.bmp.");
			break;								  
		case 6:									  
			wsprintf(buf, L"ReSource//end.bmp");
			break;								  
		case 7:									  
			wsprintf(buf, L"ReSource//enemy_L.bmp");
			break;								  
		case 8:									  
			wsprintf(buf, L"ReSource//enemy_L1.bmp");
			break;								 
		case 9:									  
			wsprintf(buf, L"ReSource//enemy_R.bmp");
			break;								  
		case 10:								  
			wsprintf(buf, L"ReSource//enemy_R1.bmp");
			break;								  
		case 11:								  
			wsprintf(buf, L"ReSource//front.");
			break;								  
		case 12:								  
			wsprintf(buf, L"ReSource//front1.bmp");
			break;								 
		case 13:								 
			wsprintf(buf, L"ReSource//icon.bmp");
			break;								 
		case 14:								  
			wsprintf(buf, L"ReSource//miter.bmp");
			break;
		case 15:
			wsprintf(buf, L"ReSource//player0.bmp");
			break;
		case 16:
			wsprintf(buf, L"ReSource//player1.bmp");
			break;
		case 17:
			wsprintf(buf, L"ReSource//player2.bmp");
			break;
		case 18:
			wsprintf(buf, L"ReSource//star.bmp");
			break;
		case 19:
			wsprintf(buf, L"ReSource//star1.bmp");
			break;
		case 20:
			wsprintf(buf, L"ReSource//star2.bmp");
			break;
		case 21:
			wsprintf(buf, L"ReSource//win.bmp");
			break;
		case 22:
			wsprintf(buf, L"ReSource//win2.bmp");
			break;
		case 23:
			wsprintf(buf, L"ReSource//z_backBlack.bmp");
			break;
		case 24:
			wsprintf(buf, L"ReSource//Z_Enemy_L.bmp");
			break;
		case 25:
			wsprintf(buf, L"ReSource//Z_Enemy_L1.bmp");
			break;
		case 26:
			wsprintf(buf, L"ReSource//Z_Enemy_R.bmp");
			break;
		case 27:
			wsprintf(buf, L"ReSource//Z_Enemy_R1.bmp");
			break;
		}
		bitmap[i].CreatImage(hdc, buf);
	}
}


BitMapManager::~BitMapManager()
{
}
