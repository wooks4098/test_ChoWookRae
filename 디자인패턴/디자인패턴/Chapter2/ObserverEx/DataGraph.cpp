#include "DataGraph.h"



DataGraph::DataGraph()
{
}

void DataGraph::Update(int kor, int mat, int eng) 
{
	m_kor = kor;
	m_mat = mat;
	m_eng = eng;

	Print();
}

void DataGraph::Print()
{
	for (unsigned int i = 0; i<m_kor; i++)
	{
		if (i == 0)
		{
			cout << "���   ";
		}
		cout << "��";

	}

	cout << endl;

	for (int i = 0; i<m_mat; i++)
	{
		if (i == 0)
		{
			cout << "����   ";
		}
		cout << "��";
	}

	cout << endl;

	for (int i = 0; i<m_eng; i++)
	{
		if (i == 0)
		{
			cout << "�ܱ��� ";
		}
		cout << "��";
	}
	cout << endl;

}


DataGraph::~DataGraph()
{
}
