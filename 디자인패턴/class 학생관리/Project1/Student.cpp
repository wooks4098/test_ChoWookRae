#include "Student.h"



Student::Student()
{
}


void Student::SetStudent(int Number)
{
	system("cls");
	int Tmp;
	bool Check = true;
	m_iNumber = Number;
	cout << "	" << m_iNumber << "�� �л� ����" << endl;
	cout << "�̸� : ";
	cin >> m_strName;
	cout << "���� : ";
	cin >> m_iAge;

	Check = true;
	while (Check)
	{
		cout << "�г� : ";
		cin >> Tmp;
		m_eGrade = (CLASS)Tmp;
		switch (m_eGrade)
		{
		case CLASS_1:
		case CLASS_2:
		case CLASS_3:
			Check = false;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�(1~3)" << endl;
			break;
		}
	}Check = true;
	while (Check)
	{
		cout << "����(���� 0,���� 1) : ";
		cin >> Tmp;
		m_eGender = (GENDER)Tmp;
		switch (m_eGender)
		{
		case GENDER_MAN:
		case GENDER_WOMAN:
			Check = false;
			break;
		default:
			cout << "�߸� �Է��ϼ˽��ϴ�.(0,1)" << endl;
			break;
		}
	}

}
void Student::ShowStudent_number()
{
	cout << "	====" << m_iNumber << "�� �л�====" << endl;
	cout << "	�̸� : " << m_strName << endl;
	cout << "	���� : " << m_iAge << endl;
	cout << "	���� : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "����" << endl;
		break;
	case GENDER_WOMAN:
		cout << "����" << endl;
		break;
	}
	cout << "	�г� : " << (int)m_eGrade << endl << endl;

}

void Student::ShowStudent_Grade(int count)
{
	if (m_eGrade == count)
		ShowStudent_number();
	else
		cout << "�л��� �����ϴ�";
}
bool Student::SelectStudent_Grade(int check)
{
	if (m_eGrade == check)
	{
		ShowStudent_number();
		return true;
	}
	else
		return false;
}
bool Student::SelectStudent_Name(string check)
{
	if (m_strName == check)
	{
		ShowStudent_number();
		return true;
	}
	else
		return false;
}
Student::~Student()
{
}
