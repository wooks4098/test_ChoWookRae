#pragma once
#include <iostream>
using namespace std;

class Cpu
{
public:
	virtual bool On() = 0;
};

class Cpu_k : public Cpu
{
public:
	virtual bool On();
};

class Cpu_u : public Cpu
{
public:
	virtual bool On();

};