#include <iostream>
using namespace std;

//Exam_1
//void main()
//{
//	int n1 = 10, n2 = 20;
//
//	cout << n1 + n2 << endl;
//}

//Exam2
//����ڰ� ������ Ŭ����
//class Point
//{
//public:
//	int x, y;
//
//	Point()
//	{
//
//	}
//
//	Point(int x, int y)
//	{
//
//	}
//
//};
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//
//	p1 + p2; // �����Ϸ��� �� ��ü�� ������ �˰� ���� �ʽ��ϴ�. ����!!
//}

//Exam_3
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//
//	void Print() const { cout << x << ',' << y << endl; }
//};
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//
//	p1 + p2; // => p1.operator+( p2 ); �� �����ϴ�.
//}

//Exam_4
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//
//	void Print() const { cout << x << ',' << y << endl; }
//
//	void operator+(Point arg)
//	{
//		cout << "operator+() �Լ�ȣ��" << endl;
//	}
//};
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//
//	p1 + p2; // => p1.operator+( p2 ); �� �����ϴ�.
//}

//Exam_5
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//
//	void Print() const { cout << x << ',' << y << endl; }
//
//	void operator+(Point arg)
//	{
//		Point pt;
//		pt.x = this->x + arg.x;
//		pt.y = this->y + arg.y;
//
//		cout << "X : " << pt.x << ", Y : " << pt.y << endl;
//	}
//};
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//
//	p1 + p2; // => p1.operator+( p2 ); �� �����ϴ�.
//}

//Exam_6
//class Point
//{
//	int x;
//	int y;
//
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//
//	void Print() const { cout << x << ',' << y << endl; }
//
//	const Point operator+(const Point& arg) const
//	{
//		Point pt;
//		pt.x = this->x + arg.x;
//		pt.y = this->y + arg.y;
//
//		return pt;
//	}
//};
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//	Point p3;
//
//	p3 = p1 + p2; // �����Ϸ��� p1.operator+(p2)�� �ؼ��ؼ� ȣ����!
//	p3.Print();
//	p3 = p1.operator+(p2); // ���� ȣ����!
//	p3.Print();
//}

//Exam_7
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//
//	const Point operator++ () // ���� ++
//	{
//		++x;
//		++y;
//
//		return *this;
//	}
//
//	const Point operator++(int) // ���� ++
//	{
//		x++;
//		y++;
//
//		return *this;
//	}
//};
//
//void main()
//{
//	Point p1(2, 3), p2(2, 3);
//	Point result;
//
//	result = ++p1; // p1.operator++(); �� �����ϴ�.
//	p1.Print();
//	result.Print();
//
//	result = p2++; // p2.operator++(0); �� �����ϴ�. 
//	p2.Print();
//	result.Print();
//}

//Exam_8
//class Point
//{
//	int x;
//	int y;
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print()const { cout << x << ',' << y << endl; }
//	const Point& operator-- () // ���� --
//	{
//		x--;
//		y--;
//		return *this;
//	}
//	const Point operator--(int) // ���� --
//	{
//		Point pt(x, y);
//		--x;
//		--y;
//		return pt;
//	}
//};
//void main()
//{
//	Point p1(2, 3), p2(2, 3);
//	Point result;
//
//	result = --p1; // p1.operator--(); �� �����ϴ�.
//	p1.Print();
//	result.Print();
//
//	result = p2--; // p2.operator--(0); �� �����ϴ�.   
//	p2.Print();
//	result.Print();
//}

//Exam_9
//class Point
//{
//    int x;
//    int y;
//public:
//    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
//    void Print( ) const { cout << x <<',' << y << endl; }
//    bool operator== (const Point& arg) const
//    {
//      return x==arg.x && y==arg.y ? true : false;
//    }
//};
//void main( )
//{
//    Point p1(2,3), p2(5,5), p3(2,3);
//    
//    if( p1 == p2 )  // p1.operator== (p2) �� �����ϴ�.
//      cout << "p1 == p2" << endl;
//    if( p1 == p3 )  // p1.operator== (p3) �� �����ϴ�.
//      cout << "p1 == p3" << endl;
//}

//Exam_10
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//
//	bool operator== (const Point& arg) const
//	{
//		return x == arg.x && y == arg.y ? true : false;
//	}
//	bool operator!= (const Point& arg) const
//	{
//		return !(*this == arg);
//	}
//};
//void main()
//{
//	Point p1(2, 3), p2(5, 5), p3(2, 3);
//
//	if (p1 != p2)  // p1.operator!= (p2) �� �����ϴ�.
//		cout << "p1 != p2" << endl;
//	if (p1 != p3)  // p1.operator!= (p3) �� �����ϴ�.
//		cout << "p1 != p3" << endl;
//}

//Exam_11
//class Point
//{
//	int x;
//	int y;
//
//public:
//
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//
//	bool operator== (const Point& arg) const
//	{
//		return x == arg.x && y == arg.y ? true : false;
//	}
//	bool operator!= (const Point& arg) const
//	{
//		return !(*this == arg);
//	}
//};
//
//void main()
//{
//	Point pt1(1, 2);
//
//	k + pt1; // k.operator(pt1)���� ����� �����ϰ� �ȴ�.
//}

//Exam_12
//class Point
//{
//	int x;
//	int y;
//
//public:
//	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//
//	const Point operator-(const Point& arg)const
//	{
//		return Point(this->x - arg.x, this->y - arg.y);
//	}
//};
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//	Point p3;
//
//	p3 = p1 - p2;
//
//	p3.Print();
//}

//Exam13
//class Point
//{
//	int x;
//	int y;
//
//public:
//	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	//friend const Point operator- (const Point& argL, const Point& argR);
//};
//
//const Point operator-(const Point& argL, const Point& argR)
//{
//	return Point(argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
//}
//
////friend �Լ��� �̿��� ���
////const Point operator- (const Point& argL, const Point& argR)
////{
////    return Point( argL.x-argR.x, argL.y-argR.y );
////}
//
//void main()
//{
//	Point p1(2, 3), p2(5, 5);
//	Point p3;
//
//	p3 = p1 - p2;
//
//	p3.Print();
//}

//Exam14
//class FuncObject
//{
//public:
//	void operator()(int arg) const
//	{
//		cout << "���� : " << arg << endl;
//	}
//};
//
//void Print1(int arg)
//{
//	cout << "���� : " << arg << endl;
//}
//
//void main()
//{
//	void(*Print2)(int) = Print1;
//	FuncObject Print3;
//
//	Print1(10); // ù°, �Լ� ȣ��
//	Print2(10); // ��°, �Լ� ȣ�� 
//	Print3(10); // ù°, �Լ� ȣ�� Print3.operator(10)�� ȣ��
//}

//Exam_15
//class FuncObject
//{
//public:
//	void operator()(int arg) const
//	{
//		cout << "���� : " << arg << endl;
//	}
//	void operator()(int arg1, int arg2) const
//	{
//		cout << "���� : " << arg1 << ',' << arg2 << endl;
//	}
//	void operator()(int arg1, int arg2, int arg3) const
//	{
//		cout << "���� : " << arg1 << ',' << arg2 << ',' << arg3 << endl;
//	}
//};
//
//void main()
//{
//	FuncObject print;
//	print(10); //��ü ���� �� ȣ��(�Ͻ���)
//	print(10, 20);
//	print(10, 20, 30);
//	cout << endl;
//
//	print.operator()(10); //��ü ���� �� ȣ��(�����)
//	print.operator()(10, 20);
//	print.operator()(10, 20, 30);
//	cout << endl;
//
//	FuncObject()(10); //�ӽ� ��ü�� ȣ��(�Ͻ���)
//	FuncObject()(10, 20);
//	FuncObject()(10, 20, 30);
//	cout << endl;
//
//	FuncObject().operator()(10); //��ü ���� �� ȣ��(�����)
//	FuncObject().operator()(10, 20);
//	FuncObject().operator()(10, 20, 30);
//}

//Exam_16
//class Array
//{
//	int *arr;
//	int size;
//	int capacity;
//public:
//	Array(int cap = 100) :arr(0), size(0), capacity(cap)
//	{
//		arr = new int[capacity];
//	}
//	~Array()
//	{
//		delete[] arr;
//	}
//	void Add(int data)
//	{
//		if (size < capacity)
//			arr[size++] = data;
//	}
//	int Size() const
//	{
//		return size;
//	}
//	int operator[](int idx) const
//	{
//		return arr[idx];
//	}
//};
//
//void main()
//{
//	Array ar(10);
//
//	ar.Add(10);
//	ar.Add(20);
//	ar.Add(30);
//	for (int i = 0; i < ar.Size(); i++)
//		cout << ar[i] << endl; // ar.operator[](i) �� �����ϴ�.
//}

//Exam_17
//class Array
//{
//	int *arr;
//	int size;
//	int capacity;
//	// ���� �Լ� ����(���� ������,���� ���� ������)
//public:
//	Array(int cap = 100) :arr(0), size(0), capacity(cap)
//	{
//		arr = new int[capacity];
//	}
//	~Array()
//	{
//		delete[] arr;
//	}
//	void Add(int data)
//	{
//		if (size < capacity)
//			arr[size++] = data;
//	}
//	int Size() const
//	{
//		return size;
//	}
//	int operator[](int idx) const
//	{
//		return arr[idx];
//	}
//	int& operator[](int idx)
//	{
//		return arr[idx];
//	}
//};
//
//void main()
//{
//	Array ar(10);
//	ar.Add(10);
//	ar.Add(20);
//	ar.Add(30);
//
//
//	cout << ar[0] << endl; // ar.operator[](int) �� ȣ���մϴ�.
//	cout << endl;
//
//	const Array& ar2 = ar;	// ar�� ����
//	cout << ar2[0] << endl; // ar.operator[](int) const �� ȣ���մϴ�.
//	cout << endl;
//
//	ar[0] = 100; // ar.operator[](int) �� ȣ���մϴ�.
//	//ar[1] = 100; ����! ��� ��ü(��)�� �����ϹǷ� ������ �� �����ϴ�.
//}

//Exam_18
//class Point
//{
//	int x;
//	int y;
//
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//};
//
//class PointPtr
//{
//	Point *ptr;
//
//public:
//	PointPtr(Point *p) :ptr(p) { }
//	~PointPtr()
//	{
//		delete ptr;
//	}
//
//	Point* operator->() const
//	{
//		return ptr;
//	}
//
//	Point& operator*() const
//	{
//		return *ptr;
//	}
//};
//
//void main()
//{
//	Point* p1 = new Point(2, 3); //�Ϲ� ������
//	PointPtr p2 = new Point(5, 5); //����Ʈ ������
//
//	p1->Print(); //p1->Print() ȣ�� 
//	p2->Print(); //p2.operator->()->Print() ȣ�� 
//	cout << endl;
//
//	(*p1).Print(); //(*p1).Print() ȣ��
//	(*p2).Print(); //p1.operator*().Print() ȣ��
//
//	delete p1;
//	//p2�� �Ҹ��ڿ��� Point ���� ��ü�� �ڵ� �޸� �����մϴ�.
//}

//Exam_19
//class A
//{
//};
//class B
//{
//public:
//	B() { cout << "B() ������" << endl; }
//	B(A& _a) { cout << "B(A _a) ������" << endl; }
//	B(int n) { cout << "B(int n) ������" << endl; }
//	B(double d) { cout << "B(double d) ������" << endl; }
//};
//void main()
//{
//	A a;
//	int n = 10;
//	double d = 5.5;
//
//	B b;   // B() ������ ȣ��
//	b = a; // b = B(a) �Ͻ��� ������ ȣ�� �� ����
//	b = n; // b = B(n) �Ͻ��� ������ ȣ�� �� ����
//	b = d; // b = B(d) �Ͻ��� ������ ȣ�� �� ����
//}

//Exam_20
//class Point
//{
//	int x;
//	int y;
//public:
//	Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//};
//
//void main()
//{
//	Point pt;
//	pt.Print();
//
//	pt = 10; // Point(10,0) �Ͻ��� ������ ȣ��
//	pt.Print();
//}

//Exam_21
//class Point
//{
//	int x;
//	int y;
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	void Print() const { cout << x << ',' << y << endl; }
//};
//
//void main()
//{
//	Point pt;
//	pt.Print();
//
//	//pt = 10; // ����! �Ͻ��� ������ ȣ���� �Ұ���!
//	pt = Point(10); // �̷��� ����� ������ ȣ�⸸ ����!
//	pt.Print();
//}

//Exam_22
//class A
//{
//};
//class B
//{
//public:
//	operator A()
//	{
//		cout << "operator A() ȣ��" << endl;
//		return A();
//	}
//	operator int()
//	{
//		cout << "operator int() ȣ��" << endl;
//		return 10;
//	}
//	operator double()
//	{
//		cout << "operator double() ȣ��" << endl;
//		return 5.5;
//	}
//};
//void main()
//{
//	A a;
//	int n;
//	double d;
//
//	B b;
//	a = b; //b.operator A() �Ͻ��� ȣ��
//	n = b; //b.operator int() �Ͻ��� ȣ��
//	d = b; //b.operator double() �Ͻ��� ȣ��
//
//	cout << endl;
//	a = b.operator A(); // ����� ȣ��
//	n = b.operator int(); // ����� ȣ��
//	d = b.operator double(); // ����� ȣ��
//}

//Exam_23
class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	operator int() const
	{
		return x;
	}
};
void main()
{
	int n = 10;

	Point pt(2, 3);
	n = pt; // pt.operator int() �Ͻ��� ȣ��
	cout << n << endl;
}