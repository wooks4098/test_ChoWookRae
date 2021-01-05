#pragma once
#include <string>
using namespace std;

class Burger
{
protected:
	virtual void bake() = 0;
public:
	Burger();
	~Burger();
};

class Wafer_original : public Burger
{
	virtual void bake();
};



class Monster_original : public Burger
{
	virtual void bake();


};

