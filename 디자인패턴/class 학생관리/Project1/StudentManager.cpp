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
		cout << "���̻� �л��� ����� �� �����ϴ�." << endl;
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
		cout << "����������������������" << i << " �г⦡��������������������" << endl;
		for (int j = 0; j < m_iStudentCount; j++)
			m_StudentList[j]->ShowStudent_Grade(i);
		cout << "��������������������������������������������������" << endl;
	}

	system("pause");
}
void StudentManager::SelectStudentList_Grade()
{
	bool stop = false;
	int check;
	system("cls");
	cout << "�г� �Է� : ";
	cin >> check;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		m_StudentList[i]->SelectStudent_Grade(check);
		if (stop == true)
			break;
		if (i == m_iStudentCount - 1 && stop == false)
			cout << "�л��� �����ϴ�." << endl;
	}

	system("pause");

}

void StudentManager::SelectStudentList_number()
{
	string check;
	bool stop = false;
	system("cls");
	cout << "�̸� �Է� : ";
	cin >> check;
	for (int i = 0; i < m_iStudentCount; i++)
	{
		stop = m_StudentList[i]->SelectStudent_Name(check);
		if (stop == true)
			break;
		if (i == m_iStudentCount-1 && stop == false)
			cout << "�л��� �����ϴ�." << endl;
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
		cout << "����" << endl;
	}
	else
		cout << "������ �һ��� �����ϴ�." << endl;
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
		cout << "����" << endl;
	}
	else
		cout << "������ �һ��� �����ϴ�." << endl;
	system("pause");
}





StudentManager::~StudentManager()
{
}
