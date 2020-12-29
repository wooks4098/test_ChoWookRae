#include "Computer.h"

void boot(Computer* computer)
{
	if (!computer->Boot())
		cout << "부팅실패" << endl;
}

void main()
{
	Computer* desktop = new Desktop();
	Computer* laptop = new Laptop();

	desktop->Creat(new Cpu_k(), new Gpu_mx(), new Ram_desktop());
	laptop->Creat(new Cpu_u(), new Gpu_mx(), new Ram_laptop());

	boot(desktop);
	boot(laptop);
}

