
#include "DataTable.h"



DataTable::DataTable()
{
}

void DataTable::Update(int kor, int mat, int eng) 
{
	m_kor = kor;
	m_mat = mat;
	m_eng = eng;

	Print();
}

void DataTable::Print()
{
		cout << "���: " << m_kor << endl;
		cout << "����: " << m_mat << endl;
		cout << "�ܱ���: " << m_eng << endl;
}

DataTable::~DataTable()
{
}
