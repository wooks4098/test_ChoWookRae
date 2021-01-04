#include "Weapon.h"



Weapon::Weapon()
{
}
Weapon::Weapon(Weapon* tmp)
{
	m_strName = tmp->m_strName;
	m_iStr = tmp->m_iStr;
	m_iPrice = tmp->m_iPrice;
	m_strClass = tmp->m_strClass;
}
void Weapon::Setdata(string name, int str, int price, string Class)
{
	m_strName = name;
	m_iStr = str;
	m_iPrice = price;
	m_strClass = Class;
}
void Weapon::Setdata(string name, int str, string Class)
{
	m_strName = name;
	m_iStr = str;
	m_strClass = Class;
}
int Weapon::Use_Skill_Check(int player_str)
{
	int skillcheck = rand() % 1000;
	if (skillcheck % m_iStr == 0)
		Skill(player_str);
	else
		return 0;
}

int Weapon::ReturnStr()
{
	return m_iStr;
}
int Weapon::ReturnPrice()
{
	return m_iPrice;
}
string Weapon::ReturnName()
{
	return m_strName;
}

string Weapon::ReturnClass()
{
	return m_strClass;

}
Weapon::~Weapon()
{
}
