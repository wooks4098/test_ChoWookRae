#include "Dagger.h"



Dagger::Dagger()
{
}
Dagger::Dagger(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Dagger::Skill(int player_str)
{
	string str;
	str = "Ä¡¸íÅ¸!! (" + to_string((m_iStr + player_str)/2) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return (m_iStr + player_str) / 2;
}

Dagger::~Dagger()
{
}
