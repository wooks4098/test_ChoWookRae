#include "Hammer.h"



Hammer::Hammer()
{
}
Hammer::Hammer(Weapon* tmp)
{
	m_strName = tmp->ReturnName();
	m_iStr = tmp->ReturnStr();
	m_iPrice = tmp->ReturnPrice();
	m_strClass = tmp->ReturnClass();
}
int Hammer::Skill(int player_str)
{
	string str;
	str = "망치나가신다!! (" + to_string(m_iStr*3) + ")";
	Map.DrawMidText(str, WIDTH, 14);
	return m_iStr * 3;
}

Hammer::~Hammer()
{
}
