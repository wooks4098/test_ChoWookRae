#pragma once
#include <vector>
#include "JobClass.h"

//����Ŭ������ �ϳ��� ��� �����ϴ� ���丮�� ����� �������ָ� �Ǽ��� ���� �� �ִ�.
class CharacterFactory
{
	vector<JobClass*> jobs;
	vector<Weapon*> weapons;

public:
	~CharacterFactory();

	virtual Weapon * CreateWeapon() = 0;
	virtual JobClass* CreateJobClass() = 0;

protected:
	void AddJob(JobClass* job);
	void AddWeapon(Weapon* weapon);

};

class KnightCharacter : public CharacterFactory
{
public:
	virtual Weapon * CreateWeapon();
	virtual JobClass* CreateJobClass();
};

class ArcherCharacter : public CharacterFactory
{
public:
	virtual Weapon * CreateWeapon();
	virtual JobClass* CreateJobClass();
};

class WizardCharacter : public CharacterFactory
{
public:
	virtual Weapon * CreateWeapon();
	virtual JobClass* CreateJobClass();
};

