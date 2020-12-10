#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Bow : public Weapon
{
public:
	Bow();
	Bow(Weapon* tmp);

	int Skill(int player_str);
	~Bow();
};

