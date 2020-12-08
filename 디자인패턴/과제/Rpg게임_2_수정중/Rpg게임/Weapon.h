#pragma once
#include "Mecro.h"
#include "MapDraw.h"
class Weapon
{
protected:
	string m_strClass;
	int m_iStr;
	int m_iPrice;
	string m_strName;
	MapDraw Map;
public:
	
	 
	Weapon();
	Weapon(Weapon *tmp);
	int ReturnStr();
	int ReturnPrice();
	string ReturnName();
	string ReturnClass();

	void Setdata(string name, int str, int price, string Class);
	void Setdata(string name, int str, string Class);
	int Use_Skill_Check(int player_str);
	int Skill(int player_str) { return NULL; };
	~Weapon();
};