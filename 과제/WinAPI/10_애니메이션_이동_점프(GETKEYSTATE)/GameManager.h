#pragma once
#include "BitMap.h"
#include <math.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
enum Dir {
	DIR_Down = 0,
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT,
};
class GameManager
{
private:
	POINT Pos;
	int Jump_y;
	int JumpTimer;

	int Count;
	int Frame;
	int Direction;
	bool isJump;
	BitMap bit;
	
public:
	
	GameManager();
	~GameManager();

	void SetData(HWND hWnd);
	void GetKey();
	void Animation(HDC hdc);
};

