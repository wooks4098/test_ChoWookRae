#include "Computer.h"

void boot(Computer* computer)
{
	if (!computer->Boot())
	{
		cout << "부팅실패" << endl;
		return;
	}
	computer->Menu();
}

void main()
{
	Computer* desktop = new Desktop();
	//Computer* laptop = new Laptop();

	desktop->Creat(new Cpu_k(), new Gpu_geforce(), new Ram_desktop(), "wooks", "msi", true, "gtx1060", "2600X", 16);
	//laptop->Creat(new Cpu_u(), new Gpu_mx(), new Ram_laptop());

	boot(desktop);
	//boot(laptop);
}

