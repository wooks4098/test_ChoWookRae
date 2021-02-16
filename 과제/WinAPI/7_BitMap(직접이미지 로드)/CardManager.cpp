#include "CardManager.h"

void CardManager::SetData()
{
	int SetNumber = 0;
	int CardSize = 10;
	int random[20];
	int doubleCkeck_Count = 0;

	bool doubleCheck;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			do
			{
				int randNum = rand() % CardSize;
				for (int k = 0; k < SetNumber; k++)
				{
					doubleCheck = false;

					if (random[i] == randNum)
					{
						doubleCkeck_Count++;
						if (doubleCkeck_Count >= 2)
						{
							doubleCheck = true;
							break;
						}

					}
				}

			} while (doubleCheck != true);

			CardList[i][j].SetData(SetNumber);
			SetNumber++;
		}
	}
}