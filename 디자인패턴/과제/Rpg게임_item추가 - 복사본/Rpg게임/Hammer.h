#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Hammer : public Weapon
{
public:
	Hammer();
	Hammer(Weapon* tmp);
	int Skill(int player_str);
	~Hammer();
};

