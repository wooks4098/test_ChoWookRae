#pragma once
#include "Monster.h"
#include "Player.h"
#include "Mecro.h"
#include "MapDraw.h"
#include "Store.h"

#define NEWGAME 0
#define SAVEFILECOUNT 10 
#define PLAYER_INFO_TEXTLINE 13

struct MonsterData
{
	int Number;
	Monster monster;
	MonsterData* Next;
};

enum RCP_CHECK
{
	RCP_CHECK_DRAW = 10,
	RCP_CHECK_PLAYERWIN,
	RCP_CHECK_MONSTERWIN,
};

class GameManager
{
private:
	int m_iWidth;
	int m_iHeight;
	int m_iSelect;
	int m_iMonsterCount;
	char buf[256];
	bool GameOver;

	MonsterData *monster, *tmp, *add;
	MapDraw Map;
	Player *player;
	Store store;

public:
	void Start();
	void LoadGame();
	void Dongeon();
	void MonsterSet(int NewGameCheck);
	void GamePlay();
	void ShowMonsterInfo();
	void SaveData();
	int Check_RCP_WIN(int PlayerRCP, int MonsterRCP);
	void SaveMonsterData(int FileNumber);
	void Show_Win(string name, int exp);
	void Show_GameOVer();

	void Monster_Release(MonsterData* Node);
	
	GameManager();
	~GameManager();
};

