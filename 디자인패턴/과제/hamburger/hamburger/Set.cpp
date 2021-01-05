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
	cout << "주문완료" << endl << endl;

	Sleep(800);
	Give();
}

void Wafer::Give()
{
	Wafer_original* b = dynamic_cast<Wafer_original*>(GetBurger());
	Cola* d = dynamic_cast<Cola*>(GerDrink());
	Original* f = dynamic_cast<Original*>(GerFrench_fries());


	cout << "주문하신 와퍼세트가 나왔습니다" << endl;

	if (b == NULL)
	{
		burger = new Wafer_original;
		cout << "버거를 잘못 선택하여 와퍼로 변경되었습니다." << endl;
	}
	else if (d == NULL)
	{
		drink = new Cola;
		cout << "음료 잘못 선택하여 콜라로 변경되었습니다." << endl;

	}
	else if (f == NULL)
	{
		french_fries = new Original;
		cout << "사이드 잘못 선택하여 감자튀김(오리지널)으로 변경되었습니다." << endl;

	}
	cout << endl;
}

void Monster::Give()
{
	Monster_original* b = dynamic_cast<Monster_original*>(GetBurger());
	Fanta* d = dynamic_cast<Fanta*>(GerDrink());
	Seasoned* f = dynamic_cast<Seasoned*>(GerFrench_fries());


	cout << "주문하신 몬스터세트가 나왔습니다" << endl;

	if (b == NULL)
	{
		burger = new Monster_original;
		cout << "버거를 잘못 선택하여 몬스터로 변경되었습니다." << endl;
	}
	else if (d == NULL)
	{
		drink = new Fanta;
		cout << "음료 잘못 선택하여 환타로 변경되었습니다." << endl;

	}
	else if (f == NULL)
	{
		french_fries = new Seasoned;
		cout << "사이드 잘못 선택하여 감자튀김(양념)으로 변경되었습니다." << endl;

	}
}


