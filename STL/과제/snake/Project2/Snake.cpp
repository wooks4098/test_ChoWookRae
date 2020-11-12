#include "Snake.h"



Snake::Snake()
{
	m_iSnakeCount = 0;
	m_iSpeed = 150;
	m_bStartCheck = false;
	//snake = NULL;
	m_iWidth = 60;
	m_iHeight = 40;
	//snake = new Snake_Pos;
	tmp.x = m_iWidth;
	tmp.y = m_iHeight/2;

	m_iLastX = tmp.x;
	m_iLastY = tmp.y;
	m_iSnakeCount = 1;
	m_iSpeedtime =clock();
	snake.push_back(tmp);

}

void Snake::SnakeAdd()
{
	m_iSpeed -= 10;
	tmp.x = m_iLastX;
	tmp.y = m_iLastY;
	m_iSnakeCount++;
	snake.push_back(tmp);

}
void Snake::Draw()
{
	m_iCurClock = clock();
	if (m_iCurClock - m_iSpeedtime > m_iSpeed)
	{
		list<Pos>::iterator iter;
		iter = snake.begin();
		Move(iter);
		iter = snake.begin();
		Draw_snake(iter);
		m_iSpeedtime = m_iCurClock;
		if (m_bStartCheck == true)
		{
			gotoxy(m_iLastX, m_iLastY);
			cout << "  ";
		}
	}
}
list<Pos>::iterator Snake::Draw_snake(list<Pos>::iterator iter)//Á¦±Í
{
	if (iter == snake.end())
		return --iter;
	iter = Draw_snake(++iter);
	if (iter == snake.begin())
	{
		gotoxy(iter->x, iter->y);
		cout << "¢Á";
	}
	else
	{
		gotoxy(iter->x, iter->y);
		cout << "¡Û";
	}
	if(iter != snake.begin())
		return --iter;
	else return iter;
}
list<Pos>::iterator Snake::Move(list<Pos>::iterator iter)//Á¦±Í
{
	if (iter == snake.end())
		return --iter;
	if(iter == snake.begin())
	{
		m_iLastX = iter->x;
		m_iLastY = iter->y;
		tmp_x = iter->x;
		tmp_y = iter->y;
		if (m_iDirection == MOVE_RIGHT)
		{
			iter->x += 2;
		}
		else if (m_iDirection == MOVE_LEFT)
		{
			iter->x -= 2;
		}
		else if (m_iDirection == MOVE_UP)
		{
			iter->y -= 1;
		}
		else if (m_iDirection == MOVE_DOWN)
		{
			iter->y += 1;
		}
	}
	else
	{
		m_iLastX = iter->x;
		m_iLastY = iter->y;
		iter->x = tmp_x;
		iter->y = tmp_y;
		tmp_x = m_iLastX;
		tmp_y = m_iLastY;
	}
	Move(++iter);

	if (iter != snake.begin())
		return --iter;
	else return iter;

}

int Snake::ReturnPosX()
{
	return snake.front().x;
}

int Snake::ReturnPosY()
{
	return snake.front().y;
}
void Snake::Input()
{
	int key;
	if (kbhit())
	{
		key = getch();
		if (m_bStartCheck == false && (key == MOVE_RIGHT || key == MOVE_LEFT || key == MOVE_UP || key == MOVE_DOWN))
			m_bStartCheck = true;
		if (key == MOVE_RIGHT && m_iDirection != MOVE_LEFT)
		{
			m_iDirection = MOVE_RIGHT;
		}
		else if (key == MOVE_LEFT && m_iDirection != MOVE_RIGHT)
		{
			m_iDirection = MOVE_LEFT;
		}
		else if (key == MOVE_UP && m_iDirection != MOVE_DOWN)
		{
			m_iDirection = MOVE_UP;
		}
		else if (key == MOVE_DOWN && m_iDirection != MOVE_UP)
		{
			m_iDirection = MOVE_DOWN;
		}
	}
}

int Snake::SnakeCollisionCheck()
{
	list<Pos>::iterator iter;
	iter = snake.begin();

	while (iter != snake.end())
	{
		if (snake.begin()->x == iter->x && snake.begin()->y == iter->y
			&&iter != snake.begin())
			return true;
		iter++;
	}
}

Snake::~Snake()
{
}
