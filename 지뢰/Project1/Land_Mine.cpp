#include "Land_Mine.h"



Land_Mine::Land_Mine()
{
	BlockSet();
}

void Land_Mine::Show_Land_Mine()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cout << block[y][x].Number << "  ";
		}
		cout << endl;
	}
}

void Land_Mine::BlockSet()
{
	int i = 0;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			block[y][x].Number = i++;
			block[y][x].isbomb = false;
			BlockSet_Neighbor(x, y);

		}
	}
}
void Land_Mine::BLockSet_Bomb()
{
	int random;
	for (int i = 0; i < HEIGHT; i++)
	{
		random = rand() % 10;
		block[i][random].isbomb = true;
	}
}


void Land_Mine::BlockSet_Neighbor( int N_x, int N_y)
{
	for (int y = N_y - 1; y <= N_y + 1; y++)
	{
		for (int x = N_x - 1; x <= N_x + 1; x++)
		{
			if (x >= 0 && x <= x + 1 && y >= 0 && y <= y + 1)
			{
				if (x == N_x && y == N_y)
					continue;
				block[N_y][N_x].NextBlock.push_back(&block[y][x]);
			}
		}
	}
}

Land_Mine::~Land_Mine()
{
}
