#include <iostream>
#include <string>
#include<Windows.h>
#include"StudentManager.h"
using namespace std;

void main()
{
	int iSelect;
	//StudentManager Manager;

	do
	{
		system("cls");
		cout << "======�л����� ���α׷�======" << endl;
		cout << "	1.�л� ���" << endl;
		cout << "	2.�л� ���<��ȣ��>" << endl;
		cout << "	3.�л� ���<�г��>" << endl;
		cout << "	4.�л� �˻�" << endl;
		cout << "	5.�г� �˻�" << endl;
		cout << "	6.�������л� ����" << endl;
		cout << "	7.�л� ��ü ����" << endl;
		cout << "	8.����" << endl;
		cout << "�л� �� : " << StudentManager::GetInstance()->GetStudentCount() << endl;
		cout << "�Է� : ";
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			StudentManager::GetInstance()->AddStudent();
			break;
		case 2:
			StudentManager::GetInstance()->ShowStudentList_number();
			break;
		case 3:
			StudentManager::GetInstance()->ShowStudentList_Grade();
			break;
		case 4:
			StudentManager::GetInstance()->SelectStudentList_number();
			break;
		case 5:
			StudentManager::GetInstance()->SelectStudentList_Grade();
			break;
		case 6:
			StudentManager::GetInstance()->DeleteStudent();
			break;
		case 7:
			StudentManager::GetInstance()->DeleteAllStudent();
			break;
		}
	} while (iSelect != 8);
}