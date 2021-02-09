#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	CardDataSet();

	firstOpen.id = -1;
	secondOpen.id = -1;
	rightCount = 0;
}
void GameManager::CardDataSet()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			cardData[i][j].isOpen = false;

	for (int i = 0; i < 9; i++)
		cardData[0][i].data.y = 50;
	for (int i = 0; i < 9; i++)
		cardData[1][i].data.y = 300;
	cardData[0][0].data.x = 50;
	cardData[0][1].data.x = 200;
	cardData[0][2].data.x = 350;
	cardData[0][3].data.x = 500;
	cardData[0][4].data.x = 650;
	cardData[0][5].data.x = 800;
	cardData[0][6].data.x = 950;
	cardData[0][7].data.x = 1100;
	cardData[0][8].data.x = 1250;
	cardData[1][0].data.x = 50;
	cardData[1][1].data.x = 200;
	cardData[1][2].data.x = 350;
	cardData[1][3].data.x = 500;
	cardData[1][4].data.x = 650;
	cardData[1][5].data.x = 800;
	cardData[1][6].data.x = 950;
	cardData[1][7].data.x = 1100;
	cardData[1][8].data.x = 1250;

	cardData[0][0].data.id = IDB_BITMAP1;
	cardData[0][1].data.id = IDB_BITMAP7;
	cardData[0][2].data.id = IDB_BITMAP8;
	cardData[0][3].data.id = IDB_BITMAP1;
	cardData[0][4].data.id = IDB_BITMAP5;

	cardData[0][5].data.id = IDB_BITMAP4;
	cardData[0][6].data.id = IDB_BITMAP2;
	cardData[0][7].data.id = IDB_BITMAP6;
	cardData[0][8].data.id = IDB_BITMAP9;

	cardData[1][0].data.id = IDB_BITMAP7;
	cardData[1][1].data.id = IDB_BITMAP5;
	cardData[1][2].data.id = IDB_BITMAP2;
	cardData[1][3].data.id = IDB_BITMAP9;

	cardData[1][4].data.id = IDB_BITMAP4;
	cardData[1][5].data.id = IDB_BITMAP3;
	cardData[1][6].data.id = IDB_BITMAP8;
	cardData[1][7].data.id = IDB_BITMAP6;
	cardData[1][8].data.id = IDB_BITMAP3;

	cardData[0][0].data.name = "강아지";
	cardData[0][1].data.name = "고양이";
	cardData[0][2].data.name = "원숭이";
	cardData[0][3].data.name = "강아지";
	cardData[0][4].data.name = "소";
	cardData[0][5].data.name = "코끼리";
	cardData[0][6].data.name = "호랑이";
	cardData[0][7].data.name = "말";
	cardData[0][8].data.name = "개구리";
	cardData[1][0].data.name = "고양이";
	cardData[1][1].data.name = "소";
	cardData[1][2].data.name = "호랑이";
	cardData[1][3].data.name = "개구리";
	cardData[1][4].data.name = "코끼리";
	cardData[1][5].data.name = "오리";
	cardData[1][6].data.name = "원숭이";
	cardData[1][7].data.name = "말";
	cardData[1][8].data.name = "오리";
}

void GameManager::Create_Sprite(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	sprite.Create_Sprite(hdc, hInst);
}

void GameManager::Draw(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name)
{
	sprite.Draw(hdc, hInst, x, y, Name);
}

void GameManager::DrawAll(HDC hdc, HINSTANCE hInst)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(cardData[i][j].isOpen == false)
				Draw(hdc, hInst, cardData[i][j].data.x, cardData[i][j].data.y, "검은색");
			else
				Draw(hdc, hInst, cardData[i][j].data.x, cardData[i][j].data.y, cardData[i][j].data.name);



		}
	}
		
}


void GameManager::Click(HDC hdc, HINSTANCE hInst, HWND hWnd, int Mouse_x, int Mouse_y)
{
	CheckData *check;
	if (firstOpen.id == -1)
		check = &firstOpen;
	else
		check = &secondOpen;
	if (Mouse_y >= 50 && Mouse_y <= 285)
	{
		check->y = 0;

		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP1;
			check->x = 0;
			if(cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;

		}
		if (Mouse_x >= 200 && Mouse_x <= 345)
		{
			check->id = IDB_BITMAP7;
			check->x = 1;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 350 && Mouse_x <= 495)
		{
			check->id = IDB_BITMAP8;
			check->x = 2;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 500 && Mouse_x <= 645)
		{
			check->id = IDB_BITMAP1;
			check->x = 3;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 650 && Mouse_x <= 795)
		{
			check->id = IDB_BITMAP5;
			check->x = 4;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 800 && Mouse_x <= 945)
		{
			check->id = IDB_BITMAP4;
			check->x = 5;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 950 && Mouse_x <= 1095)
		{
			check->id = IDB_BITMAP2;
			check->x = 6;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 1100 && Mouse_x <= 1245)
		{
			check->id = IDB_BITMAP6;
			check->x = 7;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 1250 && Mouse_x <= 1395)
		{
			check->id = IDB_BITMAP9;
			check->x = 8;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}

	}
	if(Mouse_y >= 300 && Mouse_y <= 585)
	{
		check->y = 1;


		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP7;
			check->x = 0;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 200 && Mouse_x <= 345)
		{
			check->id = IDB_BITMAP5;
			check->x = 1;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 350 && Mouse_x <= 495)
		{
			check->id = IDB_BITMAP2;
			check->x = 2;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 500 && Mouse_x <= 645)
		{
			check->id = IDB_BITMAP9;
			check->x = 3;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 650 && Mouse_x <= 795)
		{
			check->id = IDB_BITMAP4;
			check->x = 4;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 800 && Mouse_x <= 945)
		{
			check->id = IDB_BITMAP3;
			check->x = 5;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 950 && Mouse_x <= 1095)
		{
			check->id = IDB_BITMAP8;
			check->x = 6;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 1100 && Mouse_x <= 1245)
		{
			check->id = IDB_BITMAP6;
			check->x = 7;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd, check);
			else
				check->x = -1;
		}
		if (Mouse_x >= 1250 && Mouse_x <= 1395)
		{
			check->id = IDB_BITMAP3;
			check->x = 8;
			if (cardData[check->y][check->x].isOpen == false)
				CardOpen(hdc, hInst, hWnd,check);
			else
				check->x = -1;
		}
	}

}
void GameManager::CardOpen(HDC hdc, HINSTANCE hInst,HWND hWnd, CheckData *Open)
{
	cardData[Open->y][Open->x].isOpen = true;
	CardCheck(hdc, hInst, hWnd);
}


void GameManager::CardCheck(HDC hdc, HINSTANCE hInst, HWND hWnd)
{
	if (secondOpen.id == -1)
		return;


	if (firstOpen.id == secondOpen.id)
	{
		firstOpen.id = -1;
		secondOpen.id = -1;
		rightCount++;
		if (rightCount == END)
		{
			InvalidateRect(hWnd, NULL, TRUE);

			(MessageBox(hWnd, TEXT("클리어"), TEXT("짝맞추기"), MB_OK));
			return;
		}
	}
	else
	{
		cardData[firstOpen.y][firstOpen.x].isOpen = false;
		cardData[secondOpen.y][secondOpen.x].isOpen = false;
		firstOpen.id = -1;
		secondOpen.id = -1;

	}


}