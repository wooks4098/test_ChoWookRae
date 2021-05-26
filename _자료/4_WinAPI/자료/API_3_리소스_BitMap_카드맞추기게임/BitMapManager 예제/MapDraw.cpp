#include "MapDraw.h"

MapDraw::MapDraw()
{

}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void MapDraw::DrawCharacter(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}
void MapDraw::ConsoleSet(int x, int y)
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", y + 5, x * 2);
	system(buf);
}
void MapDraw::BoxDraw(int start_x,int start_y ,int Width, int Height, int Mode)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(start_x, start_y+y);
		if (y == 0)
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
			{
				if (Mode == MAP)
					cout << "��";
				else if (Mode == BOX)
					cout << "��";
			}
			cout << "��";
		}
		else if (y == Height - 1)
		{
			cout << "��";
			for (int x = 1; x < Width - 1; x++)
				if (Mode == MAP)
					cout << "��";
				else if (Mode == BOX)
					cout << "��";
			cout << "��";
		}
		else
		{
			if (Mode == MAP)
			{
				cout << "��";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "��";
				}
				cout << "��";
			}
			else if (Mode == BOX)
			{
				cout << "��";
				for (int x = 1; x < Width - 1; x++)
				{
					cout << "  ";
				}
				cout << "��";
			}

		}
	}
	return;
}

MapDraw::~MapDraw()
{

}