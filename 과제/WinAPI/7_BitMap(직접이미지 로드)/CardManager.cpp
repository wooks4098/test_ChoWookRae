#include "CardManager.h"

CardManager::CardManager()
{
	OpenCard_Count = 0;
	openCard[0].Name = "";
	openCard[1].Name = "";
}



void CardManager::SetData()
{
	int SetNumber = 0;
	int CardSize = 10;
	int random[20];
	int randNum;
	bool doubleCheck;

	//카드 정하기

	for (int i = 0; i < 10; i++)
	{
		do
		{
			doubleCheck = false;
			randNum = rand() % CardSize;
			random[i] = randNum;
			for (int k = 0; k < SetNumber; k++)
			{

				if (random[k] == randNum)
				{
					doubleCheck = true;
					break;
				}
			}

		} while (doubleCheck == true);

		CardList[0][i].SetData(randNum);
		SetNumber++;
	}

	for (int i = 0; i < 10; i++)
	{
		do
		{
			doubleCheck = false;
			randNum = rand() % CardSize;
			random[i+10] = randNum;
			for (int k = 0; k < SetNumber-10; k++)
			{

				if (random[k+10] == randNum)
				{
					doubleCheck = true;
					break;
				}
			}

		} while (doubleCheck == true);

		CardList[1][i].SetData(randNum);
		SetNumber++;
	}
	//위치지정
	SetPos();
}


void CardManager::SetPos() //50
{
	for (int i = 0; i < 10; i++)
	{
		CardList[0][i].SetPos(50 + (150 * i), 10);
	}

	for (int i = 0; i < 10; i++)
	{
		CardList[1][i].SetPos(50 + (150 * i), 300);
	}
}

void CardManager::DrawAll(HDC hdc)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			CardList[i][j].Draw(hdc);
		}
	}
}



void CardManager::CheckCard(HDC hdc, HINSTANCE hInst, HWND hWnd, POINT mouse)
{
	OpenCard *Open_Card;
	if (openCard[0].Name == "")
		Open_Card = &openCard[0];
	else
		Open_Card = &openCard[1];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (!CardList[i][j].CardOpen(mouse))
				continue;
			

			Open_Card->Name = CardList[i][j].Get_Name();
			CardList[i][j].SetState(true);
			Open_Card->x = j;
			Open_Card->y = i;

			WinCheck(hdc, hInst, hWnd);
			return;
		}
	}
}

void CardManager::WinCheck(HDC hdc, HINSTANCE hInst, HWND hWnd)
{
	if (openCard[1].Name == "")
		return;
	if (openCard[0].x == openCard[1].x && openCard[0].y == openCard[1].y)
	{
		CardList[openCard[0].y][openCard[0].x].SetState(false);
		CardList[openCard[1].y][openCard[1].x].SetState(false);
		openCard[0].Name = "";
		openCard[0].x = -1;
		openCard[0].y = -1;
		openCard[1].Name = "";
		openCard[1].x = -1;
		openCard[1].y = -1;
		return;
	}

	if (openCard[0].Name == openCard[1].Name)
	{
		OpenCard_Count++;
		if (OpenCard_Count == END)
		{
			InvalidateRect(hWnd, NULL, TRUE);

			(MessageBox(hWnd, TEXT("클리어"), TEXT("짝맞추기"), MB_OK));
			return;
		}

	}
	else
	{
		CardList[openCard[0].y][openCard[0].x].SetState(false);
		CardList[openCard[1].y][openCard[1].x].SetState(false);
		
	}
	openCard[0].Name = "";
	openCard[0].x = -1;
	openCard[0].y = -1;
	openCard[1].Name = "";
	openCard[1].x = -1;
	openCard[1].y = -1;
}
