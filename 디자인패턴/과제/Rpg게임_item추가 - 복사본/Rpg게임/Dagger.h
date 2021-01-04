#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Dagger : public Weapon
{
public:
	Dagger();
	Dagger(Weapon* tmp);

	int Skill(int player_str);
	~Dagger();
};

