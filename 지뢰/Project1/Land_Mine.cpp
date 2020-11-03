#include "Land_Mine.h"



Land_Mine::Land_Mine()
{
	BlockSet();
	m_ix = 0;
	m_iy = 0;
}
void Land_Mine::BlockDraw(int x, int y)
{
	Map.gotoxy(x*2, y);
	if (block[y][x].isOpen == false)
		cout << "■";
	else if (block[y][x].isbomb == true)
	{
		cout << "★";
	}
	else
		cout << block[y][x].Number;
}
void Land_Mine::Draw_Land_MIne()
{

	Map.gotoxy(0, 0);
	char ch;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			BlockDraw(x, y);
		}
	}

	while (1)
	{
		if (kbhit())
		{
			ch = getch();


			if (ch == 'd' && m_ix < 9)
				BlockDraw(m_ix++, m_iy);
			else if (ch == 'a' && m_ix > 0)
				BlockDraw(m_ix--, m_iy);
			else if (ch == 's' && m_iy < 9)
				BlockDraw(m_ix, m_iy++);
			else if (ch == 'w' && m_iy > 0)
				BlockDraw(m_ix, m_iy--);
			else if (ch == 13 && block[m_iy][m_ix].isOpen == false)
			{
				OpenBlock(&block[m_iy][m_ix]);
				continue;
			}
			else 
				continue;
				Map.gotoxy(m_ix*2, m_iy);
				cout << "▲";
		}
	}

}

void Land_Mine::OpenBlock(Block *block)
{
	/*
	들어오면 열었는지 체크
	0번째방부터 8뱡향으로 지뢰가 있는지 체크 있다면 폭탄 갯수를 적용하고 리턴
	없다면 0번째 방으로 이동(재귀)
	체크하는 x y값이 배열 크기에 없다면 다음 칸 체크
	*/

	int BombCount = 0;
	
	block.isOpen = true;
	//BlockDraw(x, y);그리기 추가
	BlockDraw(block.x, block.y);
	if (block.isbomb == true)
		return;
	for (auto iter = block.NextBlock.begin(); iter < block.NextBlock.end(); iter++ )
	{
		if((*iter)->isbomb == true)
			BombCount++;
	}

	//for (int C_y = 0; C_y < HEIGHT; C_y++)
	//{
	//	for (int C_x = 0; C_x < WIDTH; C_x++)
	//	{
	//		if (C_x == x && C_y == y)
	//			continue;
	//		if (block[C_y][C_x].isbomb == true)
	//			BombCount++;
	//	}
	//}
	block.Number = BombCount;
	if (BombCount >= 1)
		return;

	for (int i =0 ; i<block.NextBlock.size(); i++)
	{
		if (block.NextBlock[i]->isbomb== false)
			OpenBlock(*block.NextBlock[i]);
	}



}

void Land_Mine::Test_Show_Land_Mine()
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
			block[y][x].isOpen = false;
			block[y][x].x = x;
			block[y][x].y = y;
			BlockSet_Neighbor(x, y);

		}
		i = 0;
	}
	BLockSet_Bomb();
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
