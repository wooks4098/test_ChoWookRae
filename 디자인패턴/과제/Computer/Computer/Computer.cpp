#include "Computer.h"
#include <Windows.h>

void Computer::Creat(Cpu* _cpu, Gpu* _gpu, Ram* _ram, string Name, string ProductName, bool State, string Gpu, string Cpu, int iRam)
{
	cpu = _cpu;
	gpu = _gpu;
	ram = _ram;

	m_stdName = Name;
	m_stdProductName = ProductName;
	m_bState = State;
	m_stdGpu = Gpu;
	m_stdCpu = Cpu;
	m_iRam = iRam;
	system("cls");

}



void Computer::Menu()
{
	int select;
	system("cls");

	cout << m_stdName << "의 컴퓨터 ON" << endl;
	for (int i = 0; i < 5; i++)
	{
		Sleep(1000);
	}
	do
	{
		system("cls");
		cout << "===== 환 영 합 니 다 =====" << endl;
		cout << "1. 컴퓨터 상태" << endl;
		cout << "2. 기능" << endl;
		cout << "3. 회원 정보" << endl;
		cout << "4. 회원 정보 변경" << endl;
		cout << "5. off" << endl;
		cout << "입력 >>>>";
		cin >> select;
		switch (select)
		{
		case 1:
			State();
			break;
		case 2:
			Function();
			break;
		case 3:
			Member_info(member, login_number);
			break;
		case 4:
			Change_memberinfo(member, login_number);
			break;
		}
	} while (select != 5);
	Off();
}
void Computer::State()
{
	system("cls");
	cout << "제품명 : " << m_stdProductName << endl;
	cout << "현재 상태 : ";
	if (m_bState == true)
		cout << "ON" << endl;
	else
		cout << "OFF" << endl;
	cout << "그래픽카드 : " << m_stdGpu << endl;
	cout << "C P U : " << m_stdCpu << endl;
	cout << "메 모 리 : " << m_iRam << endl;
	system("pause");
}
void Computer::Function()
{

	int select;
	do
	{
		system("cls");
		cout << "1. 계산기" << endl;
		cout << "2. 메모장" << endl;
		cout << "3. 그림판" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "입력 >>>";
		cin >> select;
		switch (select)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		}
		system("pause");
	} while (select != 4);
}
void Computer::Off()
{
	system("cls");
	for (int i = 5; i > 0; i--)
	{
		cout << "off" << i << "초 전" << endl;
		Sleep(1000);
	}
}
bool Desktop::Boot()
{
	Cpu_k* cpu = dynamic_cast<Cpu_k*>(GetCpu());
	Gpu_geforce* gpu = dynamic_cast<Gpu_geforce*>(GetGpu());
	Ram_desktop* ram = dynamic_cast<Ram_desktop*>(GetRam());

	if (cpu == NULL || gpu == NULL || ram == NULL)
		return false;

	cout << "데스크탑 부팅 성공" << endl;
	Sleep(500);
	return true;
}

bool Laptop::Boot()
{
	Cpu_u* cpu = dynamic_cast<Cpu_u*>(GetCpu());
	Gpu_mx* gpu = dynamic_cast<Gpu_mx*>(GetGpu());
	Ram_laptop* ram = dynamic_cast<Ram_laptop*>(GetRam());

	if (cpu == NULL || gpu == NULL || ram == NULL)
		return false;

	cout << "노트북 부팅 성공" << endl;
	Sleep(500);

	return true;
}