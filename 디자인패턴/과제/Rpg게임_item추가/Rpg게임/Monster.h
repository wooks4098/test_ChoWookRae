#pragma once
#include "Mecro.h"
#include "MapDraw.h"
class Monster
{
private:
	MapDraw Map;

	string m_strName;//�̸�
	int m_iLevel;//����
	int m_iStr;//���ݷ�
	int m_iNhp;//����ä��
	int m_iMaxhp;//�ִ�ä��
	int m_iNExp;//�������ġ
	int m_iMaxExp;//�ִ� ����ġ
	int m_iGiveExp;//�ִ°���ġ
	int m_iGold;//���
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

