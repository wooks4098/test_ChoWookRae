#include "Computer.h"

void Computer::Creat(Cpu* _cpu, Gpu* _gpu, Ram* _ram)
{
	cpu = _cpu;
	gpu = _gpu;
	ram = _ram;
}

bool Desktop::Boot()
{
	Cpu_k* cpu = dynamic_cast<Cpu_k*>(GetCpu());
	Gpu_geforce* gpu = dynamic_cast<Gpu_geforce*>(GetGpu());
	Ram_desktop* ram = dynamic_cast<Ram_desktop*>(GetRam());

	if (cpu == NULL || gpu == NULL || ram == NULL)
		return false;

	cout << "데스크탑 부팅 완료" << endl;
	return true;
}

bool Laptop::Boot()
{
	Cpu_u* cpu = dynamic_cast<Cpu_u*>(GetCpu());
	Gpu_mx* gpu = dynamic_cast<Gpu_mx*>(GetGpu());
	Ram_laptop* ram = dynamic_cast<Ram_laptop*>(GetRam());

	if (cpu == NULL || gpu == NULL || ram == NULL)
		return false;

	cout << "노트북 부팅 완료" << endl;
	return true;
}