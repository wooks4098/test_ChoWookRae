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
		cout << "======학생관리 프로그램======" << endl;
		cout << "	1.학생 등록" << endl;
		cout << "	2.학생 목록<번호순>" << endl;
		cout << "	3.학생 목록<학년순>" << endl;
		cout << "	4.학생 검색" << endl;
		cout << "	5.학년 검색" << endl;
		cout << "	6.마지막학생 삭제" << endl;
		cout << "	7.학생 전체 삭제" << endl;
		cout << "	8.종료" << endl;
		cout << "학생 수 : " << StudentManager::GetInstance()->GetStudentCount() << endl;
		cout << "입력 : ";
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