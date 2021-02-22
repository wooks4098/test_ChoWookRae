#include "CardManager.h"

void CardManager::SetData()
{
	int SetNumber = 0;
	int CardSize = 10;
	int random[20];
	int doubleCkeck_Count = 0;

	bool doubleCheck;

	//카드 정하기
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			do
			{
				doubleCheck = false;
				doubleCkeck_Count = 0;
				int randNum = rand() % CardSize;
				random[j] = randNum;
				for (int k = 0; k < SetNumber; k++)
				{

					if (random[k] == randNum)
					{
						doubleCkeck_Count++;
						if (doubleCkeck_Count >= 2)
						{
							doubleCheck = true;
							break;
						}

					}
				}

			} while (doubleCheck == true);

			CardList[i][j].SetData(SetNumber);
			SetNumber++;
		}
	}
	//위치지정
	SetPos();
}


void CardManager::SetPos() //50
{
	for (int i = 0; i < 2; i++)
	{
		CardList[0][i].SetPos(50 + (100 * i), 10);
	}

	for (int i = 0; i < 2; i++)
	{
		CardList[1][i].SetPos(50 + (100 * i), 140);
	}
}
//
//
//std::string CardManager::CheckCard()
//{
//
//}