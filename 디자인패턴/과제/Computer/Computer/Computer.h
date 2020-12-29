#pragma once
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"


class Computer
{
private:
	Cpu *cpu;
	Gpu *gpu;
	Ram *ram;

protected:
	Cpu* GetCpu() { return cpu; };
	Gpu* GetGpu() { return gpu; };
	Ram* GetRam() { return ram; };

public:

	void Creat(Cpu* _cpu, Gpu* _gpu, Ram* _ram);
	virtual bool Boot() = 0;


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
