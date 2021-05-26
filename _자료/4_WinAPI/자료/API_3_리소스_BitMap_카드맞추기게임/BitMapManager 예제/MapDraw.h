#pragma once
#include"Mecro.h"
class MapDraw
{
public:
	void BoxDraw(int x, int y, int Width, int Height, int Mode);
	void DrawCharacter(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void ConsoleSet(int x, int y);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

