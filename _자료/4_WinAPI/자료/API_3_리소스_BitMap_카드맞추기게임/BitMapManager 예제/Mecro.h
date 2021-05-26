#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#define MOVELEFT 'a'
#define MOVEUP 'w'
#define MOVEDOWN 's'
#define MOVERIGHT 'd'
#define MORRING 'n'
#define SELECTOPTION 'p'
#define MAP 1
#define BOX 0
struct XY {
	int x;
	int y;
};
enum ICONTYPE {
	ICON_NOMAL = 1,
	ICON_HEART,
	ICON_FINGER,
	ICON_NUMCIR
};
using namespace std;
