#include "Wand.h"



Wand::Wand()
{
}
Wand::Wand(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Wand::Skill(int player_str)
{
	string str;
	str = "파이어볼!! (" + to_string(m_iStr + player_str) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return m_iStr + player_str;
}


Wand::~Wand()
{
}
