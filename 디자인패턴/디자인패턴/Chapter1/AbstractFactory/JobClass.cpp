#include "JobClass.h"

/* JobClass */
void JobClass::SetWeapon(Weapon * _weapon)
{
	weapon = _weapon;
}

Weapon * JobClass::GetWeapon()
{
	return weapon;
}

/* Knight */
bool Knight::EquipCheck()
{
	Sword* sword = dynamic_cast<Sword*>(GetWeapon());

	if (sword == NULL)
		return false;

	cout << "�� ����!" << endl;

	return sword->Attack();
}

/* Archer */
bool Archer::EquipCheck()
{
	Bow* bow = dynamic_cast<Bow*>(GetWeapon());

	if (bow == NULL)
		return false;

	cout << "Ȱ ����!" << endl;

	return bow->Attack();
}

/* Wizard */
bool Wizard::EquipCheck()
{
	Staff* staff = dynamic_cast<Staff*>(GetWeapon());

	if (staff == NULL)
		return false;

	cout << "������ ����!" << endl;

	return staff->Attack();
}