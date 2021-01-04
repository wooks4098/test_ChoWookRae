#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Sword : public Weapon
{
public:
	Sword();
	Sword(Weapon* tmp);
	int Skill(int player_str);
	~Sword();
};

