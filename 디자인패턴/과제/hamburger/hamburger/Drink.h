#pragma once
#include <string>
using namespace std;

class Drink
{
protected:
	virtual void getice() = 0;

public:
	Drink();
	~Drink();
};

class Cola : public Drink
{
	virtual void getice();
};

class Fanta : public Drink
{
	virtual void getice();
};