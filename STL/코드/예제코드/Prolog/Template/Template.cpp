#include <iostream>
using namespace std;

//Exam_1
//template <typename T>
//void Print(T a, T b)
//{
//	cout << a << ", " << b << endl;
//}
//void main()
//{
//	Print(10, 20); //�Ͻ��� ȣ�� ���� ���
//	Print(0.123, 1.123); //�Ͻ��� ȣ�� �Ǽ� ���
//	Print("ABC", "abcde"); //�Ͻ��� ȣ�� ���ڿ� ���
//}

//Exam_2
//template <typename T>
//void Print(T a, T b)
//{
//	cout << a << ", " << b << endl;
//}
//void main()
//{
//	Print<int>(10, 20); //����� ȣ�� ���� ���
//	Print<double>(0.123, 1.123); //���ô ȣ�� �Ǽ� ���
//	Print<const char*>("ABC", "abcde"); //����� ȣ�� ���ڿ� ���
//}

//Exam_3
//template <typename T1, typename T2>
//void Print(T1 a, T2 b)
//{
//	cout << a << ", " << b << endl;
//}
//void main()
//{
//	Print(10, 1.5); // ����, �Ǽ� ���
//	Print("Hello!", 100); // ���ڿ�, ���� ���
//	Print(1.5, "Hello!"); // �Ǽ�, ���ڿ� ���
//}

//Exam_4
//template <typename T>
//void Swap(T &a, T &b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void main()
//{
//	int n1 = 10, n2 = 20;
//	double d1 = 1.1, d2 = 2.2;
//
//	cout << n1 << ", " << n2 << endl;
//	Swap(n1, n2);
//	cout << n1 << ", " << n2 << endl;
//	cout << endl;
//
//	cout << d1 << ", " << d2 << endl;
//	Swap(d1, d2);
//	cout << d1 << ", " << d2 << endl;
//}

//Exam_5
//template <typename T, int size>
//void PrintArray(T* arr)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cout << "[" << i << "]: " << arr[i] << endl;
//	}
//	cout << endl;
//}
//void main()
//{
//	int arr1[5] = { 10, 20, 30, 40, 50 };
//	PrintArray<int, 5>(arr1); // ����� ȣ��
//
//	double arr2[3] = { 1.1, 2.2, 3.3 };
//	PrintArray<double, 3>(arr2); // ����� ȣ��
//}

//Exam_6
//class Point
//{
//	int x; int y;
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//};
//// �Ϲ�ȭ �Լ� ���ø�
//template <typename T>
//void Print(T a)
//{
//	cout << a << endl;
//}
//// Ư��ȭ �Լ� ���ø�
//template < >
//void Print(Point a) // ������� �ڵ�: void Print<Point>(Point a)
//{
//	cout << "Print Ư��ȭ ����: ";
//	a.Print();
//}
//void main()
//{
//	int n = 10;
//	double d = 2.5;
//	Point pt(2, 3);
//
//	Print(n);  // Print<int>( n )    �Ϲ�ȭ ���� ȣ��
//	Print(d);  // Print<double>( d ) �Ϲ�ȭ ���� ȣ��
//	Print(pt); // Print<Point>( pt ) Ư��ȭ ���� ȣ��
//}

//Exam_7
#include <string> //���ڿ� string Ŭ���� ���

//class IntArray //���� Array
//{
//	int *buf;
//	int size;
//	int capacity;
//public:
//	explicit IntArray(int cap = 100) :buf(0), size(0), capacity(cap)
//	{
//		buf = new int[capacity];
//	}
//	~IntArray() { delete[] buf; }
//	void Add(int data) { buf[size++] = data; }
//	int operator[](int idx) const { return buf[idx]; }
//	int GetSize() const { return size; }
//};
//class DoubleArray //�Ǽ� Array
//{
//	double *buf;
//	int size;
//	int capacity;
//public:
//	explicit DoubleArray(int cap = 100) :buf(0), size(0), capacity(cap)
//	{
//		buf = new double[capacity];
//	}
//	~DoubleArray() { delete[] buf; }
//	void Add(double data) { buf[size++] = data; }
//	double operator[](int idx) const { return buf[idx]; }
//	int GetSize() const { return size; }
//};
//class StringArray //���ڿ� Array
//{
//	string *buf;
//	int size;
//	int capacity;
//public:
//	explicit StringArray(int cap = 100) :buf(0), size(0), capacity(cap)
//	{
//		buf = new string[capacity];
//	}
//	~StringArray() { delete[] buf; }
//	void Add(string data) { buf[size++] = data; }
//	string operator[](int idx) const { return buf[idx]; }
//	int GetSize() const { return size; }
//};
//void main()
//{
//	IntArray iarr; // ���� Array ��ü
//	iarr.Add(10);
//	iarr.Add(20);
//	iarr.Add(30);
//
//	for (int i = 0; i < iarr.GetSize(); ++i)
//		cout << iarr[i] << " ";
//	cout << endl;
//
//	DoubleArray darr; // �Ǽ� Array ��ü
//	darr.Add(10.12);
//	darr.Add(20.12);
//	darr.Add(30.12);
//
//	for (int i = 0; i < darr.GetSize(); ++i)
//		cout << darr[i] << " ";
//	cout << endl;
//
//	StringArray sarr; // ���ڿ� Array ��ü
//	sarr.Add("abc");
//	sarr.Add("ABC");
//	sarr.Add("Hello!");
//
//	for (int i = 0; i < sarr.GetSize(); ++i)
//		cout << sarr[i] << " ";
//	cout << endl;
//}

//Exam_8
//template <typename T> // Ŭ���� ���ø� Array ����
//class Array
//{
//	T *buf;
//	int size;
//	int capacity;
//public:
//	explicit Array(int cap = 100) :buf(0), size(0), capacity(cap)
//	{
//		buf = new T[capacity];
//	}
//	~Array() { delete[] buf; }
//	void Add(T data)
//	{
//		buf[size++] = data;
//	}
//	T operator[](int idx) const
//	{
//		return buf[idx];
//	}
//	int GetSize() const
//	{
//		return size;
//	}
//};
//void main()
//{
//	Array<int> iarr; //����(Ŭ���̾�Ʈ�� T Ÿ�� ����) Array ��ü
//	iarr.Add(10);
//	iarr.Add(20);
//	iarr.Add(30);
//
//	for (int i = 0; i < iarr.GetSize(); ++i)
//		cout << iarr[i] << " ";
//	cout << endl;
//
//	Array<double> darr; //�Ǽ�(Ŭ���̾�Ʈ�� T Ÿ�� ����) Array ��ü
//	darr.Add(10.12);
//	darr.Add(20.12);
//	darr.Add(30.12);
//
//	for (int i = 0; i < darr.GetSize(); ++i)
//		cout << darr[i] << " ";
//	cout << endl;
//
//	Array<string> sarr; //���ڿ�(Ŭ���̾�Ʈ�� T Ÿ�� ����) Array ��ü
//	sarr.Add("abc");
//	sarr.Add("ABC");
//	sarr.Add("Hello!");
//
//	for (int i = 0; i < sarr.GetSize(); ++i)
//		cout << sarr[i] << " ";
//	cout << endl;
//}

//Exam_9
//template <typename T = int, int capT = 100> // int, 100 ����Ʈ �Ű� ���� �� ����
//class Array
//{
//	T *buf;
//	int size;
//	int capacity;
//public:
//	explicit Array(int cap = capT) :buf(0), size(0), capacity(cap)
//	{
//		buf = new T[capacity];
//	}
//	~Array() { delete[] buf; }
//	void Add(T data)
//	{
//		buf[size++] = data;
//	}
//	T operator[](int idx) const
//	{
//		return buf[idx];
//	}
//	int GetSize() const
//	{
//		return size;
//	}
//};
//
//void main()
//{
//	Array<> iarr; // ����Ʈ �Ű� ���� �� int, 100 ���
//	iarr.Add(10);
//	iarr.Add(20);
//	iarr.Add(30);
//
//	for (int i = 0; i < iarr.GetSize(); ++i)
//		cout << iarr[i] << " ";
//	cout << endl;
//
//	Array<double> darr; // ����Ʈ �Ű� ���� �� 100 ���
//	darr.Add(10.12);
//	darr.Add(20.12);
//	darr.Add(30.12);
//
//	for (int i = 0; i < darr.GetSize(); ++i)
//		cout << darr[i] << " ";
//	cout << endl;
//
//	Array<string, 10> sarr; // ����Ʈ �Ű� ���� �� ������� ����
//	sarr.Add("abc");
//	sarr.Add("ABC");
//	sarr.Add("Hello!");
//
//	for (int i = 0; i < sarr.GetSize(); ++i)
//		cout << sarr[i] << " ";
//	cout << endl;
//}

//Exam_10
//template <typename IterT, typename Func>
//void For_each(IterT begin, IterT end, Func pf)
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}
//
//void PrintInt(int data)
//{
//	cout << data << " ";
//}
//
//void PrintString(string data)
//{
//	cout << data << " ";
//}
//
//void main()
//{
//	int arr[5] = { 10, 20, 30, 40, 50 };
//	For_each(arr, arr + 5, PrintInt); // ���� ���
//	cout << endl;
//
//	string sarr[3] = { "abc","ABCDE","Hello!" };
//	For_each(sarr, sarr + 3, PrintString); // ���ڿ� ���
//	cout << endl;
//}

//Exam_11
//template <typename IterT, typename Func>
//void For_each(IterT begin, IterT end, Func pf)
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}
//void PrintInt(int data)
//{
//	cout << data << " ";
//}
//void PrintString(string data)
//{
//	cout << data << " ";
//}
//void main()
//{
//	int arr[5] = { 10, 20, 30, 40, 50 };
//	For_each<int*, void(*)(int) >(arr, arr + 5, PrintInt); // ���� ���
//	cout << endl;
//
//	string sarr[3] = { "abc","ABCDE","Hello!" };
//	For_each<string*, void(*)(string) >(sarr, sarr + 3, PrintString); // ���ڿ� ���
//	cout << endl;
//}

//Exam_12
//template <typename IterT, typename Func>
//void For_each(IterT begin, IterT end, Func pf)
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}
//template <typename T>
//void Print(T data)
//{
//	cout << data << " ";
//}
//void main()
//{
//	int arr[5] = { 10, 20, 30, 40, 50 };
//	For_each(arr, arr + 5, Print<int>); // ���� ���
//	cout << endl;
//
//	string sarr[3] = { "abc","ABCDE","Hello!" };
//	For_each(sarr, sarr + 3, Print<string>); // ���ڿ� ���
//	cout << endl;
//}

//Exam_13
//template <typename IterT, typename Func>
//void For_each(IterT begin, IterT end, Func pf)
//{
//	while (begin != end)
//	{
//		pf(*begin++);
//	}
//}
//
//template <typename T>
//class PrintFunctor
//{
//	string sep; // ��� ������ ����
//public:
//	explicit PrintFunctor(const string& s = " ") :sep(s) { }
//	void operator()(T data) const
//	{
//		cout << data << sep;
//	}
//};
//
//void main()
//{
//	int arr[5] = { 10, 20, 30, 40, 50 };
//	For_each(arr, arr + 5, PrintFunctor<int>());
//	cout << endl;
//
//	string sarr[3] = { "abc","ABCDE","Hello!" };
//	For_each(sarr, sarr + 3, PrintFunctor<string>("*\n"));
//	cout << endl;
//}

//Exam_14
template <typename RetType, typename ArgType>
class Functor
{
public:
	RetType operator( ) (ArgType data)
	{
		cout << data << endl;
		return RetType();
	}
};
void main()
{
	Functor< void, int > functor1;
	functor1(10);
	Functor< bool, string > functor2;
	functor2("Hello!");
}