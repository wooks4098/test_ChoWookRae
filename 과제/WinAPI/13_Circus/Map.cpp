#include "Map.h"



Map::Map()
{

#pragma region 백그라운드 이미지 위치 세팅

	//UI
	Ui.BitMap_Number[0] = z_backBlack;
	Ui.rect.top = 0;
	Ui.rect.left = 0;

	//관중
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
		{
			crowd[i].rect.left = -521;
			crowd[i].rect.top = 133;
			crowd[i].rect.right = crowd[i].rect.right = crowd[i].rect.left + 66;
			crowd[i].BitMap_Number[0] = BITMAP_BACK_DECO;
		}
		else if (i == 8|| i==16)
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
}
void Map::Draw(HDC hdc)
{
	//UI출력
	BitMapManager::GetInstans()->Draw(hdc, Ui.rect, Ui.BitMap_Number[0]);

	//잔디 출력
	for (int i = 0; i < 8; i ++ )
		BitMapManager::GetInstans()->Draw(hdc, Ground[i].rect, Ground[i].BitMap_Number[0]);

	//관중 출력
	for (int i = 0; i < 24; i++)
		BitMapManager::GetInstans()->Draw(hdc, crowd[i].rect, crowd[i].BitMap_Number[0]);
}

void Map::Crowd_Move(int x, float m_fDeltaTime)
{

	int WindowOut_image = -1;
	int FrontImage_Number;
	for (int i = 0; i < 24; i++)
	{
		crowd[i].rect.left += (int)x* m_fDeltaTime;
		crowd[i].rect.right += (int)x* m_fDeltaTime;
		
		if (x >= 0)
		{
			if (crowd[i].rect.right > 1041)
				WindowOut_image = i;
		}
		else
		{
			if (crowd[i].rect.right < -521)
				WindowOut_image = i;
		}
	}
	
	if (WindowOut_image != -1)//화면 밖으로 나가면
	{
		if (x >= 0)
		{
			FrontImage_Number = WindowOut_image + 1;
			if (FrontImage_Number >= 24)
				FrontImage_Number = 0;

			crowd[WindowOut_image].rect.right = crowd[FrontImage_Number].rect.left - 1;
			if (WindowOut_image == 0 || WindowOut_image == 8 || WindowOut_image == 16)
				crowd[WindowOut_image].rect.left = crowd[WindowOut_image].rect.right - 66;
			else
				crowd[WindowOut_image].rect.left = crowd[WindowOut_image].rect.right - 65;

		}
		else
		{
			FrontImage_Number = WindowOut_image - 1;
			if (FrontImage_Number <= -1)
				FrontImage_Number = 23;
			crowd[WindowOut_image].rect.left = crowd[FrontImage_Number].rect.right + 1;
			if (WindowOut_image == 0 || WindowOut_image == 8 || WindowOut_image == 16)
				crowd[WindowOut_image].rect.right = crowd[WindowOut_image].rect.right = crowd[WindowOut_image].rect.left + 66;
			else
				crowd[WindowOut_image].rect.right = crowd[WindowOut_image].rect.right = crowd[WindowOut_image].rect.left + 65;
		}
		
	}
}


Map::~Map()
{

}
