#include "Gun.h"



Gun::Gun()
{
}

Gun::Gun(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Gun::Skill(int player_str)
{
	string str;
	str = "°üÅë¼¦!! (" + to_string(m_iStr + player_str) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return m_iStr + player_str;
}

Gun::~Gun()
{
}
