#include <iostream>
using namespace std;

//Exam_1
//void Print(int n)
//{
//	cout << "����: " << n << endl;
//}
//void main()
//{
//	// void Print(int n)�� �Լ� ������ ����
//	void(*pf)(int);
//	// �Լ��� �̸��� �Լ��� ���� �ּ�
//	pf = Print;
//
//	Print(10); //1. �Լ� ȣ��
//	pf(10); //2. �����͸� �̿��� �Լ� ȣ��, ù ��° ���
//	(*pf)(10); //3. �����͸� �̿��� �Լ� ȣ��, �� ��° ���
//
//	cout << endl;
//	cout << Print << endl;
//	cout << pf << endl;
//	cout << *pf << endl;
//}

//Exam_2
//void Print()
//{
//	cout << "���� �Լ� Print()" << endl;
//}
//class Point
//{
//public:
//	void Print()
//	{
//		cout << "��� �Լ� Print()" << endl;
//	}
//};
//void main()
//{
//	Point pt;
//	Point * p = &pt;
//
//	Print(); // ù°, ���� �Լ� ȣ��
//	pt.Print(); // ��°, ��ü�� ����Լ� ȣ��
//	p->Print(); // ��°, �ּҷ� ����Լ� ȣ��
//}

//Exam_3
//void Print(int n)
//{
//	cout << "���� �Լ�: " << n << endl;
//}
//namespace A
//{
//	void Print(int n)
//	{
//		cout << "namespace A ���� �Լ�: " << n << endl;
//	}
//}
//class Point
//{
//public:
//	static void Print(int n)
//	{
//		cout << "Point Ŭ������ ���� ��� �Լ�: " << n << endl;
//	}
//};
//void main()
//{
//	void(*pf)(int);
//
//	Print(10); // 1. namespace ���� ���� �Լ� ȣ��
//	A::Print(10); // 2, namespace A�� ���� �Լ� ȣ��
//	Point::Print(10); // 3, Point Ŭ������ ���� ��� �Լ� ȣ��
//	cout << endl;
//
//	pf = Print;
//	pf(10);  // 1. �Լ� �����ͷ� namespace ���� ���� �Լ� ȣ��
//	pf = A::Print;
//	pf(10);  // 2. �Լ� �����ͷ� namespace A�� ���� �Լ� ȣ��
//	pf = Point::Print;
//	pf(10);  // 3. �Լ� �����ͷ� Point Ŭ������ ���� ��� �Լ� ȣ��
//}

//Exam_4
class Point
{
	int x;
	int y;

public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "�׽�Ʈ ���� : " << n << endl; }
};

void main()
{
	Point pt(2, 3);
	Point *p = &pt;

	void (Point::*pf1)() const; // ��� �Լ� ������ ����
	pf1 = &Point::Print;

	void (Point::*pf2)(int); // ��� �Լ� ������ ����
	pf2 = &Point::PrintInt;

	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	(pt.*pf1)();  // ��ü�� ��� �Լ� �����͸� �̿��� ȣ��
	(pt.*pf2)(10);// ��ü�� ��� �Լ� �����͸� �̿��� ȣ��  
	cout << endl;

	(p->*pf1)();  // �ּҷ� ��� �Լ� �����͸� �̿��� ȣ��
	(p->*pf2)(10);// �ּҷ� ��� �Լ� �����͸� �̿��� ȣ��
}