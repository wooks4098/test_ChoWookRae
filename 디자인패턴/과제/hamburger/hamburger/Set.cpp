#include "Set.h"
#include <Windows.h>


Set::Set()
{
}


Set::~Set()
{
}

//Burger* GetBurger()
//{
//	return burger;
//};
//Drink* GerDrink()
//{
//	return drink;
//};
//French_fries* GerFrench_fries()
//{
//	return french_fries;
//};

void Set::Creat(Burger* _burger, Drink* _drink, French_fries* _french_fires)
{
	burger = _burger;
	drink = _drink;
	_french_fires = french_fries;
	cout << "�ֹ��Ϸ�" << endl << endl;

	Sleep(800);
	Give();
}

void Wafer::Give()
{
	Wafer_original* b = dynamic_cast<Wafer_original*>(GetBurger());
	Cola* d = dynamic_cast<Cola*>(GerDrink());
	Original* f = dynamic_cast<Original*>(GerFrench_fries());


	cout << "�ֹ��Ͻ� ���ۼ�Ʈ�� ���Խ��ϴ�" << endl;

	if (b == NULL)
	{
		burger = new Wafer_original;
		cout << "���Ÿ� �߸� �����Ͽ� ���۷� ����Ǿ����ϴ�." << endl;
	}
	else if (d == NULL)
	{
		drink = new Cola;
		cout << "���� �߸� �����Ͽ� �ݶ�� ����Ǿ����ϴ�." << endl;

	}
	else if (f == NULL)
	{
		french_fries = new Original;
		cout << "���̵� �߸� �����Ͽ� ����Ƣ��(��������)���� ����Ǿ����ϴ�." << endl;

	}
	cout << endl;
}

void Monster::Give()
{
	Monster_original* b = dynamic_cast<Monster_original*>(GetBurger());
	Fanta* d = dynamic_cast<Fanta*>(GerDrink());
	Seasoned* f = dynamic_cast<Seasoned*>(GerFrench_fries());


	cout << "�ֹ��Ͻ� ���ͼ�Ʈ�� ���Խ��ϴ�" << endl;

	if (b == NULL)
	{
		burger = new Monster_original;
		cout << "���Ÿ� �߸� �����Ͽ� ���ͷ� ����Ǿ����ϴ�." << endl;
	}
	else if (d == NULL)
	{
		drink = new Fanta;
		cout << "���� �߸� �����Ͽ� ȯŸ�� ����Ǿ����ϴ�." << endl;

	}
	else if (f == NULL)
	{
		french_fries = new Seasoned;
		cout << "���̵� �߸� �����Ͽ� ����Ƣ��(���)���� ����Ǿ����ϴ�." << endl;

	}
}


