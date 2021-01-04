#pragma once
#include "Mecro.h"
#include "MapDraw.h"
class Monster
{
private:
	MapDraw Map;

	string m_strName;//이름
	int m_iLevel;//레벨
	int m_iStr;//공격력
	int m_iNhp;//현재채력
	int m_iMaxhp;//최대채력
	int m_iNExp;//현재경험치
	int m_iMaxExp;//최대 경험치
	int m_iGiveExp;//주는경험치
	int m_iGold;//골드
	int m_iWidth;
	int m_iHeight;

public:
	void GetMosterData(string name, int str, int hp, int exp, int giveexp, int level, int gold);
	void GetSaveData(int hp, int exp);
	void ShowDongeonData(int TextLine);
	int GetRCP();

	void ResetInfo();
	int ChangeHP(int Player_SRT);
	void ChangeEXP(int exp);
	void ShowMonserInfo(int TextLine);

	string ReturnName(){return m_strName;}
	int ReturnLevel(){return m_iLevel;}
	int ReturnStr(){return m_iStr;}
	int ReturnNhp(){return m_iNhp;}
	int ReturnMaxhp(){return m_iMaxhp;}
	int ReturnNExp(){return m_iNExp;}
	int ReturnMaxExp(){return m_iMaxExp;}
	int ReturnGiveExp(){return m_iGiveExp;}
	int ReturnGold(){return m_iGold;}
	Monster();
	~Monster();
};

