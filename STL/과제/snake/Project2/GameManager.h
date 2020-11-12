#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include "Block.h"
#include "Snake.h"
using namespace std;

enum KEY
{
	KEY_SPACEBAR = 32,
};

class GameManager
{
private:
	Block *block;
	Snake *snake;
	int m_iSelete;
public:
	void Start();
	void GameOver();
	GameManager();
	~GameManager();
};

