#pragma once
#include <string>
#include "Burger.h"
#include "Drink.h"
#include "French_fries.h"
#include <iostream>
using namespace std;

/*
���ۼ�Ʈ
����: ����
����: �ݶ�
��Ƣ: ��������


���ͼ�Ʈ
����: ����
����: ȯŸ
��Ƣ: ��䰨��
*/


class Set
{	


protected:
	Burger *burger;
	Drink *drink;
	French_fries *french_fries;
	Burger* GetBurger()
	{
		return burger;
	};
	Drink* GerDrink()
	{
		return drink;
	};
	French_fries* GerFrench_fries()
	{
		return french_fries;
	};
public:
	void Creat(Burger* _burger, Drink* _drink, French_fries* _french_fires);
	virtual void Give() = 0;
	Set();
	~Set();
};

class Wafer : public Set
{
	void Give();
};

class Monster : public Set
{
	void Give();


};




