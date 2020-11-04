#include <iostream>
using namespace std;

//Exam_1
//void Print()
//{
//	cout << "���� �Լ�!" << endl;
//}

//class Functor
//{
//public:
//	void operator( )()
//	{
//		cout << "�Լ� ��ü!" << endl;
//	}
//};

//void main()
//{
//	Functor functor;
//
//	Print();   // ���� �Լ� ȣ��
//	functor(); // ��� �Լ� ȣ�� functor.operator()( )�� ����;
//}

//Exam_2
//void Print(int a, int b)
//{
//	cout << "���� �Լ�: " << a << ',' << b << endl;
//}
//
//class Functor
//{
//public:
//	void operator( )(int a, int b)
//	{
//		cout << "�Լ� ��ü: " << a << ',' << b << endl;
//	}
//};
//
//void main()
//{
//	Functor functor;
//
//	Print(10, 20);   // ���� �Լ� ȣ��
//	functor(10, 20); // ��� �Լ� ȣ�� functor.operator()(10, 20)�� ����;
//}

//Exam_3
//#include <algorithm> // fo_each() �˰���(����)�� ����ϱ� ���� ���
//
//struct Functor1
//{
//	void operator()(int n) // ������ �̿��Ͽ� ���Ҹ� ���
//	{
//		cout << n << ' ';
//	}
//};
//struct Functor2
//{
//	void operator()(int n) // �� ���Ҹ� �����Ͽ� ���
//	{
//		cout << n * n << " ";
//	}
//};
//struct Functor3
//{
//	void operator()(int n) // ���ڿ��� endl�� �̿��Ͽ� ���Ҹ� ���
//	{
//		cout << "���� : " << n << endl;
//	}
//};
//void main()
//{
//	int arr[5] = { 10,20,30,40,50 };
//
//	for_each(arr, arr + 5, Functor1());//�ӽ� �Լ��� ��ü(Functor1())�� ����� �Լ��� ����
//	cout << endl << endl;
//	for_each(arr, arr + 5, Functor2());//�ӽ� �Լ��� ��ü(Functor2())�� ����� �Լ��� ����
//	cout << endl << endl;
//	for_each(arr, arr + 5, Functor3());//�ӽ� �Լ��� ��ü(Functor3())�� ����� �Լ��� ����
//}

//Exam_4
//bool Pred_less(int a, int b)
//{
//	return a < b;
//}
//
//class Less
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a < b;
//	}
//};
//
//void main()
//{
//	Less less;
//
//	cout << Pred_less(10, 20) << endl;
//	cout << Pred_less(20, 10) << endl;
//	cout << endl;
//	cout << less(10, 20) << endl; // less ��ü�� �Ϲ��� �Լ� ȣ��
//	cout << less(20, 10) << endl; // less ��ü�� �Ϲ��� �Լ� ȣ��   
//	cout << Less()(10, 20) << endl; // �ӽð�ü�� �Ϲ��� �Լ� ȣ��   
//	cout << Less()(20, 10) << endl; // �ӽð�ü�� �Ϲ��� �Լ� ȣ��   
//	cout << endl;
//	cout << less.operator()(10, 20) << endl; // ����� ȣ��
//	cout << Less().operator()(10, 20) << endl; // ����� ȣ��
//}

//Exam_5
//#include <functional> //STL less<>, greater<>
//
//class Less
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a < b;
//	}
//};
//
//class Greater
//{
//public:
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//
//void main()
//{
//	cout << Less()(10, 20) << endl; //����� Less, Greater ���
//	cout << Less()(20, 10) << endl;
//	cout << Greater()(10, 20) << endl;
//	cout << Greater()(20, 10) << endl;
//	cout << endl;
//	cout << less<int>()(10, 20) << endl; //STL�� less, greater ���
//	cout << less<int>()(20, 10) << endl;
//	cout << greater<int>()(10, 20) << endl;
//	cout << greater<int>()(20, 10) << endl;
//}

//Exam_6
#include <functional> //plus<>, minus<>

class Plus
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

class Minus
{
public:
	int operator()(int a, int b)
	{
		return a - b;
	}
};

void main()
{
	cout << Plus()(10, 20) << endl; //����� Plus, Minus ���
	cout << Plus()(20, 10) << endl;
	cout << Minus()(10, 20) << endl;
	cout << Minus()(20, 10) << endl;
	cout << endl;
	cout << plus<int>()(10, 20) << endl; //STL�� plus, minus ���
	cout << plus<int>()(20, 10) << endl;
	cout << minus<int>()(10, 20) << endl;
	cout << minus<int>()(20, 10) << endl;
}