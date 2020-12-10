#include "Inventory.h"


Inventory::Inventory()
{
	parent = NULL;
}

void Inventory::SetParent(Inventory * _parent)
{
	parent = _parent;
}

Inventory * Inventory::GetParent()
{
	return parent;
}


int Inventory::GetLevel()
{
	int level = 0;

	Inventory* inventory = GetParent();

	while (inventory != NULL)
	{
		level++;
		inventory = inventory->GetParent();
	}

	return level;
}

int Inventory::GetSize()
{
	return GetLevel() * 2;
}




Item::Item()
{
	m_pWeapon = NULL;
}

Weapon** Item::Return_Weapon()
{
	return &m_pWeapon;
}

Weapon* Item::Return_Weapon_state()
{
	return m_pWeapon;
}

Bag::Bag()
{
}

Bag::~Bag()
{
	inventoryList.clear();
}

void Bag::AddInventory(Inventory* inventory)
{

	inventory->SetParent(this);	inventoryList.push_back(inventory);
}

void Bag::RemoveInventory(Inventory* inventory)
{
	vector<Inventory*>::iterator remove = find(inventoryList.begin(), inventoryList.end(), inventory);

	if (remove != inventoryList.end())
	{
		inventoryList.erase(remove);
	}
}
Weapon** Bag::Return_Weapon()
{
	vector<Inventory*>::iterator begin = inventoryList.begin();
	vector<Inventory*>::iterator end = inventoryList.end();
	Weapon **wp;
	while (begin != end)
	{
		wp = (*begin)->Return_Weapon();
		return wp;
		begin++;
	}
}

Weapon* Bag::Return_Weapon_state()
{
	vector<Inventory*>::iterator begin = inventoryList.begin();
	vector<Inventory*>::iterator end = inventoryList.end();
	Weapon *wp;
	while (begin != end)
	{
		wp = (*begin)->Return_Weapon_state();
		return wp;
		begin++;
	}
}