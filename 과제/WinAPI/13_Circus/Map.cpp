#include "Map.h"



Map::Map()
{

#pragma region 백그라운드 이미지 위치 세팅

	//UI
	Ui.BitMap_Number[0] = z_backBlack;
	Ui.rect.top = 0;
	Ui.rect.left = 0;

	//관중
	for (int i = 0; i < 16; i++)
	{
		if (i == 0)
		{
			crowd[i].rect.left = 0;
			crowd[i].rect.top = 133;
			crowd[i].rect.right = crowd[i].rect.right = crowd[i].rect.left + 66;
			crowd[i].BitMap_Number[0] = BITMAP_BACK_DECO;
		}
		else if (i == 8)
		{
			crowd[i].rect.left = crowd[i - 1].rect.right;
			crowd[i].rect.top = 133;
			crowd[i].rect.right = crowd[i].rect.left + 66;
			crowd[i].BitMap_Number[0] = BITMAP_BACK_DECO;

		}
		else
		{
			crowd[i].rect.left = crowd[i - 1].rect.right;

			crowd[i].rect.top = 136;
			crowd[i].rect.right = crowd[i].rect.right = crowd[i].rect.left + 65;
			crowd[i].BitMap_Number[0] = BITMAP_BACK_NOMAL;
			crowd[i].BitMap_Number[1] = BITMAP_BACK_NOMAL2;

		}
	}
	//잔디
	for (int i = 0; i < 8; i++)
	{
		Ground[i].BitMap_Number[0] = BITMAP_BACK;
		Ground[i].rect.top = 200;
		Ground[i].rect.left = i * 67;
	}
#pragma endregion
	
	WinTIme = 0;
}
void Map::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Ui.rect, Ui.BitMap_Number[0]);
	for (int i = 0; i < 8; i ++ )
	{
		BitMapManager::GetInstans()->Draw(hdc, Ground[i].rect, Ground[i].BitMap_Number[0]);
	}
	for (int i = 0; i < 16; i++)
	{
		BitMapManager::GetInstans()->Draw(hdc, crowd[i].rect, crowd[i].BitMap_Number[0]);

	}
}


Map::~Map()
{

}
