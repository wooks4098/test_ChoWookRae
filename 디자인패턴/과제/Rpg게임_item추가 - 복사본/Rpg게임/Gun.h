#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Gun : public Weapon
{
public:
	Gun();
	Gun(Weapon* tmp);
	int Skill(int player_str);
	~Gun();
};

