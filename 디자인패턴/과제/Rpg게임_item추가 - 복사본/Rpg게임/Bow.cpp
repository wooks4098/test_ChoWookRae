#include "Bow.h"



Bow::Bow()
{
}
Bow::Bow(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Bow::Skill(int player_str)
{
	string str;
	str = "´õºí¼¦!! (" + to_string(m_iStr + player_str) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return m_iStr + player_str;
}

Bow::~Bow()
{
}
