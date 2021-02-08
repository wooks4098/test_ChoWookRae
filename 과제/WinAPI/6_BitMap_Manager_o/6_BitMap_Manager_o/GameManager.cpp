#include "GameManager.h"
GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			point[i][j].isOpen = false;

	point[0][0].id = IDB_BITMAP1;
	point[0][1].id = IDB_BITMAP7;
	point[0][2].id = IDB_BITMAP8;
	point[0][3].id = IDB_BITMAP1;
	point[0][4].id = IDB_BITMAP5;
	point[0][5].id = IDB_BITMAP4;
	point[0][6].id = IDB_BITMAP2;
	point[0][7].id = IDB_BITMAP6;
	point[0][8].id = IDB_BITMAP9;
	point[1][0].id = IDB_BITMAP7;
	point[1][1].id = IDB_BITMAP5;
	point[1][2].id = IDB_BITMAP2;
	point[1][3].id = IDB_BITMAP9;
	point[1][4].id = IDB_BITMAP4;
	point[1][5].id = IDB_BITMAP3;
	point[1][6].id = IDB_BITMAP8;
	point[1][7].id = IDB_BITMAP6;
	point[1][8].id = IDB_BITMAP3;

	firstOpen.id = NULL;
	rightCount = 0;
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

void GameManager::DrawAll(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name)
{
	Draw(hdc, hInst, 50, 50, "검은색");
	Draw(hdc, hInst, 200, 50, "검은색");
	Draw(hdc, hInst, 350, 50, "검은색");
	Draw(hdc, hInst, 500, 50, "검은색");
	Draw(hdc, hInst, 650, 50, "검은색");
	Draw(hdc, hInst, 800, 50, "검은색");
	Draw(hdc, hInst, 950, 50, "검은색");
	Draw(hdc, hInst, 1100, 50, "검은색");
	Draw(hdc, hInst, 1250, 50, "검은색");
	Draw(hdc, hInst, 50, 300, "검은색");
	Draw(hdc, hInst, 200, 300, "검은색");
	Draw(hdc, hInst, 350, 300, "검은색");
	Draw(hdc, hInst, 500, 300, "검은색");
	Draw(hdc, hInst, 650, 300, "검은색");
	Draw(hdc, hInst, 800, 300, "검은색");
	Draw(hdc, hInst, 950, 300, "검은색");
	Draw(hdc, hInst, 1100, 300, "검은색");
	Draw(hdc, hInst, 1250, 300, "검은색");
}


void GameManager::Click(HWND hWnd, int Mouse_x, int Mouse_y)
{
	CheckData *check;
	if (firstOpen.id == NULL)
		check = &firstOpen;
	else
		check = &secondOpen;
	if (Mouse_y >= 50 && Mouse_y <= 285)
	{
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP1;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP7;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP8;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP1;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP5;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP4;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP2;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP6;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP9;


		}
	}
	if(Mouse_y >= 300 && Mouse_y <= 585)
	{

		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP7;


		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP5;


		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			check->id = IDB_BITMAP2;


		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			*check = IDB_BITMAP4;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			*check = IDB_BITMAP3;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			*check = IDB_BITMAP8;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			*check = IDB_BITMAP6;

		}
		if (Mouse_x >= 50 && Mouse_x <= 195)
		{
			*check = IDB_BITMAP3;

		}
	}
	if (firstOpen.id != NULL)
		void CardCheck();
}

void GameManager::CardCheck()
{
	if (firstOpen.id == secondOpen.id)
	{

		rightCount++;
	}

	firstOpen.id = NULL;

}