#include "Sword.h"



Sword::Sword()
{
}
Sword::Sword(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Sword::Skill(int player_str)
{
	string str;
	str = "우주류검술!! (" + to_string(m_iStr + player_str) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return m_iStr + player_str;
}


Sword::~Sword()
{
}
