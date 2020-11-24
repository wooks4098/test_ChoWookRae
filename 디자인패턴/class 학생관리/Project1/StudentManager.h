#pragma once
#include"Student.h"

#define MAX 10

class StudentManager
{
	static StudentManager *instance;
private:
	int m_iStudentCount = 0;
	Student *m_StudentList[MAX];

public:
	static StudentManager *GetInstance()
	{
		if (instance == NULL)
			instance = new StudentManager;
		return instance;
	}


	int i = 0;
	void AddStudent();
	void ShowStudentList_number();
	void ShowStudentList_Grade();
	void SelectStudentList_Grade();
	void SelectStudentList_number();
	void DeleteStudent();
	void DeleteAllStudent();
	inline int GetStudentCount()
	{
		return m_iStudentCount;
	}
	StudentManager();
	~StudentManager();
};

