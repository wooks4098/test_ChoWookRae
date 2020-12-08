#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Weapon.h"
using namespace std;

class Inventory
{
	Inventory* parent;

public:
	Inventory();

	virtual Weapon* Return_Weapon() = 0;
	virtual void AddInventory(Inventory* inventory) = 0;
	virtual void RemoveInventory(Inventory* inventory) = 0;

	void SetParent(Inventory* _parent);
	Inventory* GetParent();
	int GetLevel();

protected:
	int GetSize();
};

class Item : public Inventory
{
private:
	Weapon **m_pWeapon;

public:
	Item();

	void AddInventory(Inventory* inventory) {};
	void RemoveInventory(Inventory* inventory) {};
	Weapon* Return_Weapon()override;
};



class Bag : public Inventory
{
	vector<Inventory*> inventoryList;
public:
	Bag();
	~Bag();

	Weapon* Return_Weapon() override;
	void AddInventory(Inventory* inventory) override;
	void RemoveInventory(Inventory* inventory) override;
};