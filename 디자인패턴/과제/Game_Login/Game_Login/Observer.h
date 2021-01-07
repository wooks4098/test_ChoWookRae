#pragma once
#include <iostream>
#include <string>
using namespace std;
class Observer
{
public:
	virtual void Alarm(string name) = 0;
	Observer();
	~Observer();
};

