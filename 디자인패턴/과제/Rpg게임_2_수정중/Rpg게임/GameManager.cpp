#include "GameManager.h"



GameManager::GameManager()
{
	m_iWidth = 30;
	m_iHeight = 30;
	sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight+1, m_iWidth*2);
	system(buf);
	GameOver = false;
	player = NULL;
	monster = NULL;
	add = NULL;
	tmp = NULL;
}

void GameManager::Start()
{
	do
	{
		if (player != NULL)
			delete player;
		player = new Player;
		GameOver = false;
		Map.BoxDraw(0, 0, m_iWidth, m_iHeight);
		Map.DrawMidText("☆★DonGeonRPG★☆", m_iWidth, 10);
		Map.DrawMidText("New Game", m_iWidth, 13);
		Map.DrawMidText("Load Game", m_iWidth, 16);
		Map.DrawMidText("Game Exit", m_iWidth, 19);
		m_iSelect = Map.MenuSelectCursor(3, 3, 11, 13);
		switch (m_iSelect)
		{
		case 1:
			player->SetName();
			player->LoadDefaultInfo();
			MonsterSet(NEWGAME);
			GamePlay();
			break;
		case 2:
			LoadGame();
			GamePlay();
			break;
		}
	} while (m_iSelect != 3);
}

void GameManager::GamePlay()
{
	do
	{
		Map.BoxErase(m_iWidth, m_iHeight);
		Map.DrawMidText("☆★Menu★☆", m_iWidth, 9);
		Map.DrawMidText("Dongeon", m_iWidth, 11);
		Map.DrawMidText("Player Info", m_iWidth, 13);
		Map.DrawMidText("Monster Info", m_iWidth, 15);
		Map.DrawMidText("Weapon Shop", m_iWidth, 17);
		Map.DrawMidText("Save", m_iWidth, 19);
		Map.DrawMidText("Exit", m_iWidth, 21);
		m_iSelect = Map.MenuSelectCursor(6, 2, 10, 11);
		switch (m_iSelect)
		{
		case 1:
			Dongeon();
			break;
		case 2:
			player->ShowInfo(PLAYER_INFO_TEXTLINE);
			getch();
			break;
		case 3:
			ShowMonsterInfo();
			break;
		case 4:
			store.StoreShow(player);
			break;
		case 5:
			SaveData();
			break;
		}
		if (GameOver == true)
			break;
	} while (m_iSelect != 6);

}
void GameManager::Dongeon()
{
	int PlayerRCP, MonsterRCP;
	int TextLine = 9;
	string Text;
	while (1)
	{
		if (GameOver == true || m_iSelect == m_iMonsterCount+1)
			break;
		TextLine = 9;
		Map.BoxErase(m_iWidth, m_iHeight);
		Map.DrawMidText("=====던전 입구=====", m_iWidth, TextLine);
		TextLine += 2;
		tmp = monster;
		for (int i = 0; i < m_iMonsterCount; i++)
		{
			Text = to_string(i + 1) + "층던전 : [" + tmp->monster.ReturnName() + "]";
			Map.DrawMidText(Text, m_iWidth, TextLine);
			tmp = tmp->Next;
			TextLine += 2;
		}

		Text = to_string(m_iMonsterCount + 1) + ". 돌아가기";
		Map.DrawMidText(Text, m_iWidth, TextLine);
		m_iSelect = Map.MenuSelectCursor(m_iMonsterCount + 1, 2, 7, 11);//던전 몬스터 선택
		if (m_iSelect != 7)
		{
			tmp = monster;
			while (1)
			{
				if (tmp->Number == m_iSelect)
					break;
				tmp = tmp->Next;
			}
			Map.BoxErase(m_iWidth, m_iHeight);

			while (1)//게임
			{
				player->ShowInfo(3);
				RED
					Map.DrawMidText("--------------------------vs--------------------------", m_iWidth, m_iHeight / 2);
				ORIGINAL
					tmp->monster.ShowDongeonData(23);
				PlayerRCP = player->GetRCP();
				MonsterRCP = tmp->monster.GetRCP();
				if (Check_RCP_WIN(PlayerRCP, MonsterRCP) == RCP_CHECK_DRAW)//13  19
				{
					RED
						Map.DrawMidText("DRAW", m_iWidth, 13);
					Map.DrawMidText("DRAW", m_iWidth, 19);
					ORIGINAL
				}
				else if (Check_RCP_WIN(PlayerRCP, MonsterRCP) == RCP_CHECK_PLAYERWIN)//플레이어 WIN
				{
					RED
						Map.DrawMidText("WIN", m_iWidth, 13);
					Map.DrawMidText("LOSE", m_iWidth, 19);
					ORIGINAL

						tmp->monster.ChangeHP(player->ReturnStr());
					/*if (player->Weapon_Skill_Check() == true)
					{
						
						tmp->monster.ChangeHP(player->Use_Skill());
					}*/
					tmp->monster.ChangeHP(player->Weapon_Skill());
					if (tmp->monster.ReturnNhp() <= 0)
					{
						Map.gotoxy(3, 20);
						system("pause");
						Show_Win(player->ReturnName(), tmp->monster.ReturnGiveExp());
						player->ChangeEXP(tmp->monster.ReturnGiveExp());
						tmp->monster.ResetInfo();
						player->ChangeGOLD(tmp->monster.ReturnGold());
						Map.gotoxy(3, 20);
						system("pause");
						break;
					}
				}
				else if (Check_RCP_WIN(PlayerRCP, MonsterRCP) == RCP_CHECK_MONSTERWIN)//몬스터  WIN
				{
					RED
						Map.DrawMidText("WIN", m_iWidth, 19);
					Map.DrawMidText("LOSE", m_iWidth, 13);
					ORIGINAL

						player->ChangeHP(tmp->monster.ReturnStr());

					if (player->ReturnNhp() <= 0)
					{
						Map.gotoxy(3, 20);
						system("pause");
						Show_Win(tmp->monster.ReturnName(), player->ReturnNExp());
						tmp->monster.ChangeEXP(player->ReturnNExp());
						player->ChangeEXP(0);
						Map.gotoxy(3, 20);
						system("pause");
						Show_GameOVer();
						GameOver = true;
						break;
					}

				}
				Map.gotoxy(3, 20);
				system("pause");
			}
		}
	}
		
	
	
}

void GameManager::Show_Win(string name, int exp)
{
	string str;
	str = name + " 승리!!";
	Map.BoxErase(m_iWidth, m_iHeight);
	RED
	Map.DrawMidText(str, m_iWidth, 13);
	str = name + "가 경험치 " + to_string(exp) + "를 얻었습니다.";
	Map.DrawMidText(str, m_iWidth, 16);
	ORIGINAL
}
void GameManager::Show_GameOVer()
{
	Map.BoxErase(m_iWidth, m_iHeight);
	RED
		Map.DrawMidText("Game Over", m_iWidth, m_iHeight / 2);
	ORIGINAL
		Map.gotoxy(4, m_iHeight / 2 + 2);
		system("pause");

}
int GameManager:: Check_RCP_WIN(int PlayerRCP, int MonsterRCP)
{//1가위 2바위 3보
	if (PlayerRCP == MonsterRCP)
		return RCP_CHECK_DRAW;
	else if (PlayerRCP == 1)
	{
		if (MonsterRCP == 2)
			return RCP_CHECK_MONSTERWIN;
		else if (MonsterRCP == 3)
			return RCP_CHECK_PLAYERWIN;
	}
	else if (PlayerRCP == 2)
	{
		if (MonsterRCP == 1)
			return RCP_CHECK_PLAYERWIN;
		else if (MonsterRCP == 3)
			return RCP_CHECK_MONSTERWIN;
	}
	else if (PlayerRCP == 3)
	{
		if (MonsterRCP == 1)
			return RCP_CHECK_MONSTERWIN;
		else if (MonsterRCP == 2)
			return RCP_CHECK_PLAYERWIN;
	}

}

void GameManager::LoadGame()
{
	string file;
	ifstream load;
	bool FileCheck[SAVEFILECOUNT];
	while (1)
	{
		int TextLine = 6;
		Map.BoxErase(m_iWidth, m_iHeight);
		for (int i = 0; i < SAVEFILECOUNT; i++)
		{
			file = "SavePlayer" + to_string(i + 1) + ".txt";
			load.open(file);
			if (load.is_open() == true)
			{
				file = to_string(i + 1) + "번 슬롯 : (파일여부 : O)";
				GREEN
					Map.DrawMidText(file, m_iWidth, TextLine);
				ORIGINAL
					FileCheck[i] = true;
			}
			else
			{
				file = to_string(i + 1) + "번 슬롯 : (파일여부 : X)";
				Map.DrawMidText(file, m_iWidth, TextLine);
				FileCheck[i] = false;
			}
			TextLine += 2;
			load.close();
		}
		m_iSelect = Map.MenuSelectCursor(10, 2, 6, 6);
		if (FileCheck[m_iSelect-1] == false)
		{
			Map.BoxErase(m_iWidth, m_iHeight);
			Map.DrawMidText("해당 파일이 없습니다.", m_iWidth, 15);
			Map.gotoxy(12, 16);
			system("pause");
		}
		else
		{
			player->LoadNewInfo(m_iSelect);
			MonsterSet(m_iSelect);
			break;
		}
	}
	
}

void GameManager::MonsterSet(int NewGameCheck)
{
	if(monster != NULL)
		Monster_Release(monster);
	string name;
	int monstercount = 1;
	int str, hp, exp, giveexp, level, gold, Nhp, Nexp;
	ifstream load;
	string file;
	file = "SaveMonster" + to_string(NewGameCheck) + ".txt";
	if (NewGameCheck == NEWGAME)
		load.open("DefaultMonster.txt");
	else
		load.open(file);
	load >> m_iMonsterCount;
	monster = NULL;
	for (int i = 0; i < m_iMonsterCount; i++)
	{
		load >> name;
		load >> str;
		load >> level;
		if (NewGameCheck != 0)
			load >> Nhp;
		load >> hp;
		if (NewGameCheck != 0)
			load >> Nexp;
		load >> exp;
		load >> giveexp;
		load >> gold;

		add = new MonsterData;
		add->monster.GetMosterData(name, str, hp, exp, giveexp, level, gold);
		if (NewGameCheck != 0)
			add->monster.GetSaveData(Nhp, Nexp);
		add->Next = NULL;
		add->Number = monstercount++;
		if (monster == NULL)
			monster = add;
		else
		{
			tmp = monster;
			while (tmp->Next != NULL)
			{
				tmp = tmp->Next;
			}
			tmp->Next = add;
		}
	}
}


void GameManager::ShowMonsterInfo()
{
	int TextLine = 2;
	tmp = monster;
	Map.BoxErase(m_iWidth, m_iHeight);
	for (int i = 0; i < m_iMonsterCount; i++)
	{

		if (i == 0)
		{
			monster->monster.ShowMonserInfo(TextLine);
		}
		else
		{
			tmp->monster.ShowMonserInfo(TextLine);
		}
		TextLine += 4;
		if(tmp->Next != NULL)
			tmp = tmp->Next;
	}
	while (1)
	{
		if (getch())
			break;
	}
}

void GameManager::SaveData()
{
	string file;
	ifstream load;
	bool FileCheck[SAVEFILECOUNT];

	int TextLine = 6;
	Map.BoxErase(m_iWidth, m_iHeight);
	for (int i = 0; i < SAVEFILECOUNT; i++)
	{
		file = "SavePlayer" + to_string(i + 1) + ".txt";
		load.open(file);
		if (load.is_open() == true)
		{
			file = to_string(i + 1) + "번 슬롯 : (파일여부 : O)";
			GREEN
				Map.DrawMidText(file, m_iWidth, TextLine);
			ORIGINAL
				FileCheck[i] = true;
		}
		else
		{
			file = to_string(i + 1) + "번 슬롯 : (파일여부 : X)";
			Map.DrawMidText(file, m_iWidth, TextLine);
			FileCheck[i] = false;
		}
		TextLine += 2;
		load.close();
	}
	Map.DrawMidText("11. 돌아가기", m_iWidth, TextLine);
	m_iSelect = Map.MenuSelectCursor(11, 2, 6, 6);
	player->SaveData(m_iSelect);
	SaveMonsterData(m_iSelect);
}
void GameManager::SaveMonsterData(int FileNumber)
{
	ofstream save;
	string file;
	file = "SaveMonster" + to_string(FileNumber) + ".txt";
	save.open(file);
	save << m_iMonsterCount << endl;
	string ReturnName();
	tmp = monster;
	for (int i = 0; i < m_iMonsterCount; i++)
	{
		save << tmp->monster.ReturnName() << " ";
		save << tmp->monster.ReturnStr() << " ";
		save << tmp->monster.ReturnLevel() << " ";
		save << tmp->monster.ReturnNhp() << " ";
		save << tmp->monster.ReturnMaxhp() << " ";
		save << tmp->monster.ReturnNExp() << " ";
		save << tmp->monster.ReturnMaxExp() << " ";
		save << tmp->monster.ReturnGiveExp() << " ";
		save << tmp->monster.ReturnGold() << endl;
		tmp = tmp->Next;
	}

}
void GameManager::Monster_Release(MonsterData* Node)
{
	{
		if (Node == NULL)
			return;
		Monster_Release(Node->Next);
		delete Node;
	}
}

GameManager::~GameManager()
{
	Monster_Release(monster);
	if (player != NULL)
		delete player;
}
