#include "Person.h"



Person::Person()
{
}

void Person::SetPerson()
{
	cout << "���� �Է� : ";
	cin >> m_iAge;
	cout << "�̸� �Է� : ";
	cin >> m_strName;
	cout << "���� �Է� : ";
	cin >> m_strGender;
}
void Person::ShowPerson()
{
	cout << "���� : " << m_iAge<< endl;
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_strGender << endl;
}

Person::~Person()
{
}
