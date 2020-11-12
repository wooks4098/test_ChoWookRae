#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include "Snake.h"
using namespace std;
#define ITEMSPAWNTIME 1200
#define WALL_SUM 30
#define ITEM_SUM 10




class Block
{
private:
	int m_iScore;
	int m_iCurClock;
	int m_iItemClock;
	int m_iHeight;
	int m_iWidth;
	Pos* wall[30];
	Pos* item[10];
public:
	void DrawBox();
	void DrawMap();
	void ItemCheck();
	void SetWall();
	void SetItem();
	void ScoreUp();
	void DrawMidText(string str, int x, int y);
	bool CollisionCheck(int x, int y, Snake* snake);
	int ReturnScore();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Block();
	~Block();
};

