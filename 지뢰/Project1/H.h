#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include <time.h>
using namespace std;

#define WIDTH 10
#define HEIGHT 10

struct pos
{
	int x;
	int y;
};

struct Block
{
	int x, y;
	int Number;
	bool isbomb;
	bool isOpen;
	vector< Block*> NextBlock;
};

enum KEY
{
	KEY_RIGHT = 77,
	KEY_LEFT = 75,
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_ENTER = 27
};

#pragma once
