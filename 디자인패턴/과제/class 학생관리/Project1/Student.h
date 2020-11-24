#pragma once
#include<iostream>
#include<string>
using namespace std;

enum GENDER
{
	GENDER_MAN,
	GENDER_WOMAN
};

enum CLASS
{
	CLASS_START = 1,
	CLASS_1 = 1,
	CLASS_2,
	CLASS_3,
	CLASS_END = 3
};


class Student
{
private:
	string m_strName;
	int m_iAge;
	CLASS m_eGrade;//1~3
	GENDER m_eGender;
	int m_iNumber;

public:

	void SetStudent(int Number);
	void ShowStudent_number();
	
	void ShowStudent_Grade(int count);
	bool SelectStudent_Grade(int check);
	bool SelectStudent_Name(string check);
	Student();
	~Student();
};

