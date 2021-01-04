#pragma once
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
#include <string>
#include <iostream>
#include "Login.h"
using namespace std;

class Computer : public Login
{
private:
	Cpu *cpu;
	Gpu *gpu;
	Ram *ram;
	string m_stdName;
	string m_stdProductName;
	bool m_bState;
	string m_stdGpu;
	string m_stdCpu;
	int m_iRam;

protected:
	Cpu* GetCpu() { return cpu; };
	Gpu* GetGpu() { return gpu; };
	Ram* GetRam() { return ram; };

public:
	void Menu();
	void State();
	void Function();
	void Off();
	void Creat(Cpu* _cpu, Gpu* _gpu, Ram* _ram, string Name, string ProductName, bool State, string Gpu, string Ram, int iRam);
	virtual bool Boot() = 0;
	//Computer();
	//~Computer();

};




class Desktop : public Computer
{
public:
	virtual bool Boot();
};


class Laptop : public Computer
{
public:
	virtual bool Boot();
};
