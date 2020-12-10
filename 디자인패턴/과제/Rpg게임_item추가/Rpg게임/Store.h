#pragma once
#include "Player.h"
#include "Weapon.h"
#include "MapDraw.h"
#include "Mecro.h"
#include "Bow.h"
#include "Dagger.h"
#include "Gun.h"
#include "Hammer.h"
#include "Sword.h"
#include "Wand.h"
struct WeaponData
{
	string Class;
	Weapon *weapon;
	WeaponData* Next;
	int Number;
};
class Store
{
private:
	int m_iWidth;
	int m_iHeight;
	int m_iSelelct;
	int BowCount, DaggerCount, Guncount, SwordCount, WandCount, HammerCount;
	WeaponData *weapon, *tmp, *add;
	MapDraw Map;

public:
	void StoreShow(Player *player);
	void WeaponShow(string Class, Player *player);
	void SetWeaponData();

	void Weapon_Release(WeaponData* Node);
	
	Store();
	~Store();
};









