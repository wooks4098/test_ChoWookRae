#include "GameManager.h"


GameManager::GameManager()
{
	block = NULL;
	snake = NULL;
}

void GameManager::Start()
{
	do
	{
		if (block == NULL)
			block = new Block;
		if (snake == NULL)
			snake = new Snake;
		block->DrawBox();
		block->DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", 60, 12);
		block->DrawMidText("1. 게임시작", 60, 15);
		block->DrawMidText("2. 게임종료", 60, 18);
		block->DrawMidText("선택: ", 60, 21);
		cin >> m_iSelete;
		switch (m_iSelete)
		{
		case 1:
			block->DrawMap();
			while (1)
			{
				block->SetItem();
				snake->Input();
				snake->Draw();
				if (block->CollisionCheck(snake->ReturnPosX(), snake->ReturnPosY(), snake) == true)
					break;
				
			}
			GameOver();
			delete snake;
			snake = NULL;
			delete block;
			block = NULL;
			break;
		}
	} while (m_iSelete != 2);
}

void GameManager::GameOver()
{
	char ch;
	string str;
	str = "Score : " + to_string(block->ReturnScore());
	system("cls");
	block->DrawBox();
	block->DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", 60, 10);
	block->DrawMidText(str, 60, 13);
	block->DrawMidText("Continue : Space bar", 60, 15);
	while (1)
	{
		ch = getch();
		if (ch == KEY_SPACEBAR)
			break;
	}
}

GameManager::~GameManager()
{
	if (snake != NULL)
		delete snake;
	if (block != NULL)
		delete block;
}
