#include "Monster.h"



Monster::Monster()
{
	m_iWidth = 30;
	m_iHeight = 30;
}
void Monster::ResetInfo()
{
	m_iNhp = m_iMaxhp;
}

int Monster::GetRCP()
{
	int RCP;
	RCP = rand()%3+1;
	switch (RCP)
	{
	case 1:
		Map.DrawMidText("가위", m_iWidth, 18);
		return RCP_SCISSOR;
		break;
	case 2:
		Map.DrawMidText("바위", m_iWidth, 18);
		return RCP_ROCK;
		break;
	case 3:
		Map.DrawMidText("보", m_iWidth, 18);
		return RCP_PAPER;
		break;

	}
}




void Monster::ShowDongeonData(int TextLine)
{
	string str;
	str = "======" + m_strName + "(" + to_string(m_iLevel) + "Lv)======";
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "공격력 = " + to_string(m_iStr) + "	  생명력 = " + to_string(m_iNhp) + "/" + to_string(m_iMaxhp);
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "경험치 = " + to_string(m_iNExp) + "/" + to_string(m_iMaxExp) + "	  GiveExp = " + to_string(m_iGiveExp);
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "Gold = " + to_string(m_iGold) + "               ";
	Map.DrawMidText(str, m_iWidth, TextLine++);
}

void Monster::GetMosterData(string name, int str,int hp,int exp,int giveexp, int level, int gold)
{
	m_strName = name;
	m_iStr = str;
	m_iMaxhp = hp;
	m_iNhp = m_iMaxhp;
	m_iMaxExp = exp;
	m_iNExp = 0;
	m_iGiveExp = giveexp;
	m_iLevel = level;
	m_iGold = gold;
}
void Monster::GetSaveData(int hp, int exp)
{
	m_iNhp = hp;
	m_iNExp = exp;
}
void Monster::ShowMonserInfo(int TextLine)
{
	string str;
	str = "======" + m_strName + "(" + to_string(m_iLevel) + "Lv)======";
	Map.DrawMidText(str, m_iWidth, TextLine);
	str = "공격력 = " + to_string(m_iStr) + "	  생명력 = " + to_string(m_iNhp) + "/" + to_string(m_iMaxhp);
	Map.DrawMidText(str, m_iWidth, TextLine+1);
	str = "경험치 = " + to_string(m_iNExp) + "/" + to_string(m_iMaxExp) + "	  GiveExp = " + to_string(m_iGiveExp);
	Map.DrawMidText(str, m_iWidth, TextLine+2);
	str = "Gold = " + to_string(m_iGold) + "               ";
	Map.DrawMidText(str, m_iWidth, TextLine+3);
}

int Monster::ChangeHP(int Player_SRT)
{
	m_iNhp -= Player_SRT;
	if (m_iNhp <= 0)
		return DIE;
	else
		return LIVE;
}


void Monster::ChangeEXP(int exp)
{
	m_iNExp += exp;
	string srt;
	if (m_iMaxExp <= m_iNExp)
	{
		m_iStr += 3;
		m_iMaxhp += 7;
		m_iNhp = m_iMaxhp;
		m_iMaxExp += 5;
		m_iNExp = 0;
		m_iLevel++;

		Map.BoxErase(m_iWidth, m_iHeight);
		Map.gotoxy(3, 20);
		system("pause");
		srt = m_strName + "레벨업!!";
		Map.DrawMidText(srt, m_iWidth, 12);

		srt = m_strName + "공격력 3증가!!";
		Map.DrawMidText(srt, m_iWidth, 15);

		srt = m_strName + "생명력 7증가!!";
		Map.DrawMidText(srt, m_iWidth, 18);
		Map.gotoxy(3, 20);
		system("pause");
	}
}

Monster::~Monster()
{
}
