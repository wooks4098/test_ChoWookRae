#include "StudentManager.h"


StudentManager StudentManager::*instance = NULL;

StudentManager::StudentManager()
{
	instance = NULL;
}

void StudentManager::AddStudent()
{
	if (m_iStudentCount < MAX)
	{
		m_StudentList[m_iStudentCount] = new Student;
		m_StudentList[m_iStudentCount]->SetStudent(m_iStudentCount + 1);
		m_iStudentCount++;
	}
	else
	{
		cout << "더이상 학생을 등록할 수 없습니다." << endl;
		system("pause");
	}
}
void StudentManager::ShowStudentList_number()
{
	system("cls");
	for (int i = 0; i < m_iStudentCount; i++)
		m_StudentList[i]->ShowStudent_number();
	system("pause");
}
void StudentManager::ShowStudentList_Grade()
{
	system("cls");
	for (int i = CLASS_START; i <= CLASS_END; i++)
	{
		cout << "┌──────────" << i << " 학년──────────┐" << endl;
		for (int j = 0; j < m_iStudentCount; j++)
			m_StudentList[j]->ShowStudent_Grade(i);
		cout << "└───────────────────────┘" << endl;
	}

	system("pause");
}
void StudentManager::SelectStudentList_Grade()
{
	bool stop = false;
	int check;
	system("cls");
	cout << "학년 입력 : ";
	cin >> check;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		m_StudentList[i]->SelectStudent_Grade(check);
		if (stop == true)
			break;
		if (i == m_iStudentCount - 1 && stop == false)
			cout << "학생이 없습니다." << endl;
	}

	system("pause");

}

void StudentManager::SelectStudentList_number()
{
	string check;
	bool stop = false;
	system("cls");
	cout << "이름 입력 : ";
	cin >> check;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		stop = m_StudentList[i]->SelectStudent_Name(check);
		if (stop == true)
			break;
		if (i == m_iStudentCount-1 && stop == false)
			cout << "학생이 없습니다." << endl;
	}

	system("pause");
}

void StudentManager::DeleteStudent()
{
	system("cls");
	if (m_iStudentCount >= 1)
	{
		delete m_StudentList[m_iStudentCount-1];
		m_iStudentCount--;
		cout << "성공" << endl;
	}
	else
		cout << "삭제할 할생이 없습니다." << endl;
	system("pause");
}

void StudentManager::DeleteAllStudent()
{
	system("cls");
	if (m_iStudentCount >= 1)
	{
		for (int i = 0; i < m_iStudentCount-1; i++)
		{
			delete m_StudentList[i];
		}
		m_iStudentCount = 0;
		cout << "성공" << endl;
	}
	else
		cout << "삭제할 할생이 없습니다." << endl;
	system("pause");
}





StudentManager::~StudentManager()
{
}
