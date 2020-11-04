#include "JobClass.h"

void AttackTest(JobClass* job);

//���⸦ ��, Ȱ, �������� ���� Ŭ������ ������ �ְ�,
//������ ���, �ü�, ������ ����Ŭ������ ������ �ִ�.
//�� ������ �ش� ������ �´� ���⸦ �����߸� ������ �� �ִ�.
//���� �ʴ� ���⸦ ��� ���⸦ ������ ������ �Ϸ��� �ϸ� ������ ���� �ʰ�, ���� �����߸� ������ �����ѻ�Ȳ�̴�.
//�Ʒ�ó�� Ư�� ���� �޼����� ������ �ʴ´ٸ� üũ �� �� ���� ��Ȳ�̴�.
//����ó������ �� Ȯ���� ��� �ʿ��ϴ�.
int main()
{
	JobClass* knight = new Knight();
	JobClass* archer = new Archer();
	JobClass* wizard = new Wizard();

	knight->SetWeapon(new Bow());
	archer->SetWeapon(new Staff());
	wizard->SetWeapon(new Sword());

	AttackTest(knight);
	AttackTest(archer);
	AttackTest(wizard);
}

void AttackTest(JobClass* job)
{
	if (!job->EquipCheck())
		cout << "���� ��� ����!" << endl;
}