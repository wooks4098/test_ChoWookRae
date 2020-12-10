#pragma once
#include "Weapon.h"
#include "Mecro.h"
class Wand : public Weapon
{
public:
	Wand();
	Wand(Weapon* tmp);
	int Skill(int player_str);
	~Wand();
};

