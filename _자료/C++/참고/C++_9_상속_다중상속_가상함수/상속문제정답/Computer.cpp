#include "Computer.h"



Computer::Computer()
{
	m_strName = "����ȣ ��ǻ��";
	m_strGraphic = "GTX1060Ti";
	m_bOnOff = false;
	m_iRam = 16;
	m_strCpu = "I7";
}


void Computer::Computerdisplay()
{
	int Select;
	cout << "����ȣ ��ǻ�� on" << endl;
	Sleep(3000);
	system("cls");
	while (true) {
		cout << "===== ȯ �� �� �� �� =====" << endl;
		cout << "1.��ǻ�� ����" << endl;
		cout << "2.�� ��" << endl;
		cout << "3.ȸ�� ����" << endl;
		cout << "4.ȸ�� ���� ����" << endl;
		cout << "5.off" << endl;
		cout << "�Է� >> ";
		cin >> Select;
		switch (Select) {
		case 1:
			condition();
			break;
		case 2:
			function();
			break;
		case 3:
			Login::ShowID();
			break;
		case 4:
			Login::SetID();
			break;
		case 5:
			for (int i = 5; i > 0; i--)
			{
				cout << "off " << i << " ����" << endl;
				Sleep(1000);
			}
			return;
		}
		system("pause");
		system("cls");
	}
}

void Computer::condition()
{
	system("cls");
	cout << "�� ǰ �� : " << m_strName << endl;
	cout << "���� ���� : ";
	if(m_bOnOff)	
		cout << "On " << endl;
	else
		cout << "Off " << endl;
	cout << "�׷���ī�� : " << m_strGraphic << endl;
	cout << "C P U : " << m_strCpu << endl;
	cout << "�� �� �� : " << m_iRam << "G" << endl;
}

void Computer::function()
{
	int i;
	system("cls");
	while (true) {
		cout << "1.�� �� ��" << endl;
		cout << "2.�� �� ��" << endl;
		cout << "3.�� �� ��" << endl;
		cout << "4.���ư���" << endl;
		cout << "���� >>>>"; cin >> i;
		switch (i) {
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		default:
			return;
		}
		system("pause"); system("cls");
	}
}

Computer::~Computer()
{
}
