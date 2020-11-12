#include "Block.h"



Block::Block()
{
	m_iScore = 0;
	m_iItemClock = clock();
	m_iHeight = 40;
	m_iWidth =60;
	for (int i = 0; i < 30; i++)
		wall[i] = NULL;
	for (int i = 0; i < 10; i++)
		item[i] = NULL;
	srand(time(NULL));
}

void Block::DrawBox()
{
	for (int y = 0; y < m_iHeight; y++)
	{
		gotoxy(0, 0 + y);
		for (int x = 0; x < m_iWidth; x++)
		{
			if (y == 0 || y == m_iHeight - 1 || x == 0 || x == m_iWidth - 1)
				cout << "□";
			else
				cout << "  ";
		}
	}
}

void Block::DrawMap()
{
	SetWall();
	DrawBox();
	for (int i = 0; i < WALL_SUM; i++)
	{
		gotoxy(wall[i]->x, wall[i]->y);
		cout << "▦";
	}
	DrawMidText("Score: 0", m_iWidth, m_iHeight + 1);
}

void Block::SetWall()
{
	bool check = true;
	for (int i = 0; i < WALL_SUM; i++)
	{
		wall[i] = new Pos;
		while (1)
		{
			check = true;
			wall[i]->x = rand() % 100;
			wall[i]->y = rand() % 100;
			for (int j = 0; j < i; j++)
			{
				if(wall[i]->x == wall[j]->x || wall[i]->y == wall[j]->y)//뱀초기값 예외추가
					check = false;
				break;
			}
			if ((wall[i]->x > 0 && wall[i]->x < m_iWidth - 1) && (wall[i]->y > 0 && wall[i]->y < m_iHeight - 1) && check == true)
			{
				wall[i]->x *= 2;
				break;
			}
		}
	}
}

void Block::SetItem()
{
	bool check = true;
	m_iCurClock = clock();
	if (m_iCurClock - m_iItemClock >= ITEMSPAWNTIME)
	{
		for (int i = 0; i < ITEM_SUM; i++)
		{
			if (item[i] == NULL)
			{
				item[i] = new Pos;
				while (1)
				{
					check = true;
					item[i]->x = rand() % 100;
					item[i]->y = rand() % 100/2;
					for (int j = 0; j < WALL_SUM; j++)
					{
						if (item[i]->x == wall[j]->x && item[i]->y == wall[j]->y)
						{
							check = false;
							break;
						}
					}
					for (int p = 0; p < ITEM_SUM; p++)
					{
						if (p == i)
						{
							p++;
							if (p == ITEM_SUM)
								break;
						}
						if (item[p] == NULL)
							continue;
						else
						{
							if (item[i]->x == item[p]->x && item[i]->y == item[p]->y)
							{
								check = false;
								break;
							}
						}
					}
					if ((item[i]->x > 0 && item[i]->x < m_iWidth - 1) && (item[i]->y > 0 && item[i]->y < m_iHeight - 1) && check == true)
						break;
				}
				item[i]->x *= 2;
				gotoxy(item[i]->x, item[i]->y);
				cout << "♡";
				break;
			}	
		}
		m_iItemClock = m_iCurClock;

	}

}

void Block::ScoreUp()
{
	string str;
	str = "Score: " + to_string(m_iScore);
	DrawMidText(str, m_iWidth, m_iHeight + 1);
}

void Block::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

bool Block::CollisionCheck(int x, int y, Snake* snake)
{
	for (int i = 0; i < WALL_SUM; i++)
	{
		if (wall[i]->x == x && wall[i]->y == y)
			return true;
	}
	for (int i = 0; i < ITEM_SUM; i++)
	{
		if (item[i] != NULL && item[i]->x == x && item[i]->y == y)
		{
			delete item[i];
			item[i] = NULL;
			snake->SnakeAdd();
			m_iScore++;
			ScoreUp();
		}
	}
	if (snake->SnakeCollisionCheck() == true)
		return true;
	if (y == 0 || y == 39 || x == 0 || x == 118)
		return true;
}

int Block::ReturnScore()
{
	return m_iScore;
}

Block::~Block()
{
	for (int i = 0; i < WALL_SUM; i++)
	{
		if (wall[i] != NULL)
			delete wall[i];
	}
	for (int i = 0; i <ITEM_SUM; i++)
	{
		if (item[i] != NULL)
			delete item[i];
	}
}
