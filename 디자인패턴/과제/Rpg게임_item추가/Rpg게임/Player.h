#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Weapon.h"
#include "Bow.h"
#include "Dagger.h"
#include "Gun.h"
#include "Hammer.h"
#include "Sword.h"
#include "Wand.h"
#include "Inventory.h"
class Player
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

	//Weapon *m_pWeapon;
	Inventory* inventory;
public:
	//void GetPlayerData();
	//void LoadINFO();
	void ShowInfo(int TextLine);
	void LoadDefaultInfo();
	void LoadNewInfo(int FileNumber);
	void SetName();
	void SaveData(int FileNumber);
	int GetRCP();

	int ChangeHP(int Monster_Srt);
	void ChangeEXP(int exp);
	void ChangeGOLD(int Gold);
	void Get_Weapon(string Weapon_Class);

	int Weapon_Skill();


	void Buy_Weapon(Weapon &wp,string Class);

	string ReturnName(){return m_strName;}
	int ReturnLevel(){return m_iLevel;}
	int ReturnStr()
	{
		if (inventory->Return_Weapon_state() == NULL)
			return m_iStr;
		else
			return m_iStr + inventory->Return_Weapon_state()->ReturnStr();
		/*return m_iStr + inventory->Return_Weapon()->ReturnStr();*/
	}
	int ReturnNhp()	{return m_iNhp;}
	int ReturnMaxhp(){return m_iMaxhp;}
	int ReturnNExp(){return m_iNExp;}
	int ReturnMaxExp(){return m_iMaxExp;}
	int ReturnGiveExp(){return m_iGiveExp;}
	int ReturnGold(){return m_iGold;}
	Player();
	~Player();
};

