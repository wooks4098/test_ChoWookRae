#include "School.h"



School::School()
{
}

void School::SetClass()
{
	cout << "�г� �Է� : ";
	cin >> m_iClassNumber;
	cout << "�� �Է� : ";
	cin >> m_iGroupNumber;
	cout << "�л� ��ȣ �Է� : ";
	cin >> m_iStudentNumber;
}
void School::ShowClass()
{
	cout << m_iClassNumber << " �г� " << m_iGroupNumber<< " �� " << m_iStudentNumber << " �� �л�" << endl;
}

School::~School()
{
}
