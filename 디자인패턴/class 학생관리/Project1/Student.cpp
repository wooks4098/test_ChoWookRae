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
	cout << "	" << m_iNumber << "번 학생 정보" << endl;
	cout << "이름 : ";
	cin >> m_strName;
	cout << "나이 : ";
	cin >> m_iAge;

	Check = true;
	while (Check)
	{
		cout << "학년 : ";
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
			cout << "잘못 입력하셨습니다(1~3)" << endl;
			break;
		}
	}Check = true;
	while (Check)
	{
		cout << "성별(남자 0,여자 1) : ";
		cin >> Tmp;
		m_eGender = (GENDER)Tmp;
		switch (m_eGender)
		{
		case GENDER_MAN:
		case GENDER_WOMAN:
			Check = false;
			break;
		default:
			cout << "잘못 입력하셧습니다.(0,1)" << endl;
			break;
		}
	}

}
void Student::ShowStudent_number()
{
	cout << "	====" << m_iNumber << "번 학생====" << endl;
	cout << "	이름 : " << m_strName << endl;
	cout << "	나이 : " << m_iAge << endl;
	cout << "	성별 : ";
	switch (m_eGender)
	{
	case GENDER_MAN:
		cout << "남자" << endl;
		break;
	case GENDER_WOMAN:
		cout << "여자" << endl;
		break;
	}
	cout << "	학년 : " << (int)m_eGrade << endl << endl;

}

void Student::ShowStudent_Grade(int count)
{
	if (m_eGrade == count)
		ShowStudent_number();
	else
		cout << "학생이 없습니다";
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
