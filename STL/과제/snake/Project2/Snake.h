#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <list>
using namespace std;

enum MOVE
{
	MOVE_RIGHT = 100,
	MOVE_LEFT = 97,
	MOVE_UP = 119,
	MOVE_DOWN = 115,
};

struct Pos
{
	int x, y;
};
class Snake
{
private:
	int m_iDirection;
	int m_iSpeed;
	int m_iCurClock;
	int m_iSpeedtime;
	int m_iSnakeCount;
	bool m_bStartCheck;
	int m_iHeight;
	int m_iWidth;
	int m_iLastX;
	int m_iLastY;
	int tmp_x;
	int tmp_y;
	Pos tmp;
	list<Pos> snake;
	

public:
	list<Pos>::iterator Move(list<Pos>::iterator iter);
	void Input();
	void SnakeAdd();
	void Draw();
	list<Pos>::iterator Draw_snake(list<Pos>::iterator iter);
	int ReturnPosX();
	int ReturnPosY();
	int SnakeCollisionCheck();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Snake();
	~Snake();
};

