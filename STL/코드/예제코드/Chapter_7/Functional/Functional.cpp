#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

//Exam_1
//struct LessFunctor // 1. �Լ� ��ü ������
//{
//	bool operator()(int left, int right) const
//	{
//		return left < right;
//	}
//};
//
//bool LessFun(int left, int right) // 2. �Լ� ������
//{
//	return left < right;
//}
//
//void main()
//{
//	bool(*LessPtr)(int, int) = LessFun; // 3. �Լ� ������ ������
//	LessFunctor lessFunctor;
//
//	//��� bool ������ ��ȯ
//	//1. �Լ� ��ü�� 10�� 20�� ��
//	cout << lessFunctor(10, 20) << endl;
//
//	//2. �Լ��� 10�� 20�� ��
//	cout << LessFun(10, 20) << endl;
//
//	//3. �Լ� �����ͷ� 10�� 20�� ��
//	cout << LessPtr(10, 20) << endl;
//}

//Exam_2
//template<typename T>
//struct Plus
//{
//	T operator( )(const T& left, const T& right) const
//	{
//		return left + right;
//	}
//};
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(2);
//	v2.push_back(3);
//
//	vector<int> v3(3); //size: 3�� vector ����
//
//	//STL ������ plus<int> ���
//	//transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
//	//����� ���� ������ Plus<int> ���
//	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus<int>());
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); i++)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v2 : ";
//	for (vector<int>::size_type i = 0; i < v2.size(); i++)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	cout << "v3 : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_3
//template<typename T>
//struct Plus
//{
//	T operator( )(const T& left, const T& right) const
//	{
//		return left + right;
//	}
//};
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v3(3); //size: 3�� vector ����
//	//STL ������ plus<int> ���
//	transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> >(plus<int>(), 100));
//	//����� ���� ������ Plus<int> ���
//	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> > (Plus<int>(), 100) );
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); i++)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v3 : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_4
//template<typename T>
//struct Plus
//{
//	typedef T first_argument_type;
//	typedef T second_argument_type;
//	typedef T result_type;
//
//
//	T operator( )(const T& left, const T& right) const
//	{
//		return left + right;
//	}
//};
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v3(3); //size: 3�� vector ����
//	//STL ������ plus<int> ���
//	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
//	//����� ���� ������ Plus<int> ���
//	transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> >(Plus<int>(), 100));
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); i++)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v3 : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_5
//template<typename T>
//struct Plus : public binary_function<T, T, T>
//{
//	T operator( )(const T& left, const T& right) const
//	{
//		return left + right;
//	}
//};
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v3(3); //size: 3�� vector ����
//	//STL ������ plus<int> ���
//	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
//	//����� ���� ������ Plus<int> ���
//	transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> >(Plus<int>(), 100));
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); i++)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v3 : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_6
//void main()
//{
//	plus<int> oPlus;
//	//1. oPlus ��ü�� 10, 20 ���ϱ�. �Ϲ��� ȣ��
//	cout << oPlus(10, 20) << endl;
//	//2. oPlus ��ü�� 10, 20 ���ϱ�. ����� ȣ��
//	cout << oPlus.operator()(10, 20) << endl;
//
//	//3. �ӽ� ��ü�� 10, 20 ���ϱ�. �Ϲ��� ȣ��(�Ϲ����� ���)
//	cout << plus<int>()(10, 20) << endl;
//	//4. �ӽ� ��ü�� 10, 20 ���ϱ�. ����� ȣ��
//	cout << plus<int>().operator()(10, 20) << endl;
//}

//Exam_7
//template<typename T>
//struct Plus : public binary_function<T, T, T> //����� ������ �����ϵ���.
//{
//	T operator( )(const T& left, const T& right) const
//	{
//		return left + right;
//	}
//};
//void main()
//{
//	Plus<int> oPlus;
//	cout << oPlus(10, 20) << endl;
//	cout << oPlus.operator()(10, 20) << endl;
//
//	cout << Plus<int>()(10, 20) << endl;
//	cout << Plus<int>().operator()(10, 20) << endl;
//}

//Exam_8
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(2);
//	v2.push_back(3);
//	v2.push_back(4);
//	v2.push_back(5);
//
//	vector<int> v3(5); //size: 5�� vector ����
//
//	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
//	cout << "v3(v1+v2) : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
//	cout << "v3(v1*v2) : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	transform(v1.begin(), v1.end(), v3.begin(), negate<int>());
//	cout << "v3(-v1) : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	adjacent_difference(v1.begin(), v1.end(), v3.begin(), minus<int>());
//	cout << "v3(v1 ���� ���ҿ��� ��) : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//
//	partial_sum(v1.begin(), v1.end(), v3.begin(), multiplies<int>());
//	cout << "v3(v1 ������ �� ����) : ";
//	for (vector<int>::size_type i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	cout << "v1 ��� ������ ��: " << accumulate(v1.begin(), v1.end(), 1, multiplies<int>()) << endl;
//}

//Exam_9
//void main()
//{
//	less<int> oLess;
//	//1. oLess ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��
//	cout << oLess(10, 20) << endl;
//	//2. oLess ��ü�� 10, 20�� �� true.  ����� ȣ��
//	cout << oLess.operator()(10, 20) << endl;
//
//	//3. �ӽ� ��ü�� 10, 20�� �� true. �Ϲ��� ȣ��(�Ϲ����� ���)
//	cout << less<int>()(10, 20) << endl;
//	//4. �ӽ� ��ü�� 10, 20�� �� true. ����� ȣ��
//	cout << less<int>().operator()(10, 20) << endl;
//}

//Exam_10
//template<typename T>
//struct Less : public binary_function<T, T, bool> //����� ������ �����ϵ���.
//{
//	bool operator( )(const T& left, const T& right) const
//	{
//		return left < right;
//	}
//};
//
//void main()
//{
//	Less<int> oLess;
//	cout << oLess(10, 20) << endl;
//	cout << oLess.operator()(10, 20) << endl;
//
//	cout << Less<int>()(10, 20) << endl;
//	cout << Less<int>().operator()(10, 20) << endl;
//}

//Exam_11
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//
//	cout << "20 ���� ���� ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<less<int> >(less<int>(), 20)) << endl;
//	cout << "20 ���� �۰ų� ���� ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<less_equal<int> >(less_equal<int>(), 20)) << endl;
//	cout << "20 ���� ū ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<greater<int> >(greater<int>(), 20)) << endl;
//	cout << "20 ���� ũ�ų� ���� ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<greater_equal<int> >(greater_equal<int>(), 20)) << endl;
//	cout << "20�� ���� ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<equal_to<int> >(equal_to<int>(), 20)) << endl;
//	cout << "20�� �ٸ� ������ ����: " << count_if(v.begin(), v.end(),
//		bind2nd<not_equal_to<int> >(not_equal_to<int>(), 20)) << endl;
//}

//Exam_12
//template<typename T>
//struct Logical_and : public binary_function<T, T, bool> //����� ������ �����ϵ���.
//{
//	bool operator( )(const T& left, const T& right) const
//	{
//		return left && right;
//	}
//};
//
//void main()
//{
//	int n = 30;
//	logical_and<bool> oAnd;
//	1. oAnd ��ü�� 10 < n < 50 �ΰ�? true. �Ϲ��� ȣ��
//	cout << oAnd(greater<int>()(n, 10), less<int>()(n, 50)) << endl;
//	2. oAnd ��ü�� 10 < n < 50 �ΰ�? true.  ����� ȣ��
//	cout << oAnd.operator()(greater<int>()(n, 10), less<int>()(n, 50)) << endl;
//
//	3. �ӽ� ��ü�� 10 < n < 50 �ΰ�? true. �Ϲ��� ȣ��(�Ϲ����� ���)
//	cout << logical_and<bool>()(greater<int>()(n, 10), less<int>()(n, 50)) << endl;
//	4. �ӽ� ��ü�� 10 < n < 50 �ΰ�? true. ����� ȣ��
//	cout << logical_and<bool>().operator()(greater<int>()(n, 10), less<int>()(n, 50)) << endl;
//}

//Exam_13
//void main()
//{
//	//less�� ù ���ڸ� 10���� ������ ���� ������ binder ����.
//	binder1st< less<int> > binder = bind1st(less<int>(), 10);
//
//	// binder�� ù ��° ���ڸ� 10���� ������ less. 
//	cout << binder(5) << ':' << less<int>()(10, 5) << endl; // �� ������ �����մϴ�.
//	cout << binder(10) << ':' << less<int>()(10, 10) << endl;// �� ������ �����մϴ�.
//	cout << binder(20) << ':' << less<int>()(10, 20) << endl;// �� ������ �����մϴ�.
//	cout << "=====���� ����=====" << endl;
//	// �ӽ� ��ü ���
//	cout << bind1st(less<int>(), 10)(5) << ':' << less<int>()(10, 5) << endl;
//	cout << bind1st(less<int>(), 10)(10) << ':' << less<int>()(10, 10) << endl;
//	cout << bind1st(less<int>(), 10)(20) << ':' << less<int>()(10, 20) << endl;
//}

//Exam_14
//void main()
//{
//	//less�� �� ��° ���ڸ� 10���� ������ ���� ������ binder ����.
//	binder2nd< less<int> > binder = bind2nd(less<int>(), 10);
//
//	// binder�� �� ��° ���ڸ� 10���� ������ less. 
//	cout << binder(5) << ':' << less<int>()(5, 10) << endl; // �� ������ �����մϴ�.
//	cout << binder(10) << ':' << less<int>()(10, 10) << endl;// �� ������ �����մϴ�.
//	cout << binder(20) << ':' << less<int>()(20, 10) << endl;// �� ������ �����մϴ�.
//	cout << "=====���� ����=====" << endl;
//	// �ӽ� ��ü ���.
//	cout << bind2nd(less<int>(), 10)(5) << ':' << less<int>()(5, 10) << endl;
//	cout << bind2nd(less<int>(), 10)(10) << ':' << less<int>()(10, 10) << endl;
//	cout << bind2nd(less<int>(), 10)(20) << ':' << less<int>()(20, 10) << endl;
//}

//Exam_15
//void main()
//{
//	less<int> oLess;
//	binary_negate< less<int> > negate = not2(less<int>());
//
//	cout << negate(5, 10) << ':' << not2(oLess)(5, 10) << ':' << not2(less<int>())(5, 10) << endl; //��� ����.
//	cout << negate(10, 10) << ':' << not2(oLess)(10, 10) << ':' << not2(less<int>())(10, 10) << endl; //��� ����.
//	cout << negate(20, 10) << ':' << not2(oLess)(20, 10) << ':' << not2(less<int>())(20, 10) << endl; //��� ����.
//}

//Exam_16
//void main()
//{
//	binder2nd< less<int> > binder = bind2nd(less<int>(), 10);
//	unary_negate< binder2nd<less<int> > > negate = not1(binder);
//
//	cout << negate(5) << ':' << not1(binder)(5) << ':' << not1(bind2nd(less<int>(), 10))(5) << endl; //��� ����.
//	cout << negate(10) << ':' << not1(binder)(10) << ':' << not1(bind2nd(less<int>(), 10))(10) << endl;//��� ����.
//	cout << negate(20) << ':' << not1(binder)(20) << ':' << not1(bind2nd(less<int>(), 10))(20) << endl;//��� ����.
//}

//Exam_17
//bool Pred(int n)
//{
//	return 30 <= n && n <= 40;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//
//	cout << "30�̻� 40������ ���� ����: " << count_if(v.begin(), v.end(), Pred) << endl;
//	//������ �����Դϴ�. not1�� ����ͷ� �Լ� ��ü�� argument_type, result_type�� ���ǵǾ� �־�� ��!
//	cout << "30�̻� 40���ϰ� �ƴ� ���� ����: " << count_if(v.begin(), v.end(), not1(Pred)) << endl;
//}

//Exam_18
//bool Pred(int n)
//{
//	return 30 <= n && n <= 40;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//
//	cout << "30�̻� 40������ ���� ����: " << count_if(v.begin(), v.end(), Pred) << endl;
//	//����~!
//	cout << "30�̻� 40���ϰ� �ƴ� ���� ����: " << count_if(v.begin(), v.end(), not1(ptr_fun(Pred))) << endl;
//}

//Exam_19
////////////////////// server ///////////////////
//// Ŭ���� : ptr_fun()�� �Լ� ��ü Ŭ����
//// �������� ����� ������ �� �ֽ��ϴ�. argument_type, result_type ��....
//template<typename RType, typename AType>
//class Ptr_fun_class :public unary_function<AType, RType>
//{
//	RType(*pf)(AType);
//public:
//	Ptr_fun_class(RType(*_pf)(AType)) :pf(_pf) { }
//	RType operator()(AType n) const
//	{
//		return pf(n);
//	}
//};
//
//// �Ϲ� �Լ��� �Լ� ��ü�� ��ȯ�ϴ� ptr_fun() �Լ�
//template <typename RType, typename AType>
//Ptr_fun_class<RType, AType> Ptr_fun(RType(*pf)(AType))
//{
//	return Ptr_fun_class<RType, AType>(pf);
//}
//
///////////// client ///////////////////
//bool Pred(int n)
//{
//	return 30 <= n && n <= 40;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//
//	cout << "30�̻� 40������ ���� ����: " << count_if(v.begin(), v.end(), Pred) << endl;
//	//����~!
//	cout << "30�̻� 40���ϰ� �ƴ� ���� ����: " << count_if(v.begin(), v.end(), not1(Ptr_fun(Pred))) << endl;
//}

//Exam_20
class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	int GetX() const { return x; }
	int GetY() const { return y; }
};

void main()
{
	vector<Point> v;
	v.push_back(Point(1, 1));
	v.push_back(Point(2, 2));
	v.push_back(Point(3, 3));
	v.push_back(Point(4, 4));
	v.push_back(Point(5, 5));

	// ȣ�� �Ұ���
	//for_each(v.begin(), v.end(), &Point::Print );
	// ȣ�� ����
	for_each(v.begin(), v.end(), mem_fun_ref(&Point::Print));
}

//Exam_21
///////////////////////server////////////////////////
//��ü�� ��� �Լ��� ȣ���� �� �ִ� �Լ� ��ü Ŭ����
template <typename RType, typename CType>
class Mem_fun_ref_class : public unary_function<CType, RType>
{
	RType(CType::*pf)() const;
public:
	Mem_fun_ref_class(RType(CType::*_pf)() const) :pf(_pf) {}
	RType operator()(const CType& o) const
	{
		return (o.*pf)();
	}
};

// ����� �Լ� : ��� �Լ��� �ּҸ� �����ϴ� �Լ� ��ü�� ��ȯ
template <typename RType, typename CType>
Mem_fun_ref_class<RType, CType> Mem_fun_ref(RType(CType::*pf) () const)
{
	return Mem_fun_ref_class<RType, CType>(pf);
}

////////////////////////client/////////////////////////////
class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	int GetX() const { return x; }
	int GetY() const { return y; }
};

void main()
{
	vector<Point> v;
	v.push_back(Point(1, 1));
	v.push_back(Point(2, 2));
	v.push_back(Point(3, 3));
	v.push_back(Point(4, 4));
	v.push_back(Point(5, 5));

	for_each(v.begin(), v.end(), Mem_fun_ref(&Point::Print));
}

//Exam_22
///////////////////////server////////////////////////
//��ü�� ��� �Լ��� ȣ���� �� �ִ� �Լ� ��ü Ŭ����
template <typename RType, typename CType>
class Mem_fun_class : public unary_function<CType, RType>
{
	RType(CType::*pf)() const;
public:
	Mem_fun_class(RType(CType::*_pf)() const) :pf(_pf) {}
	RType operator()(const CType* p) const
	{
		return (p->*pf)();
	}
};

// ����� �Լ� : ��� �Լ��� �ּҸ� �����ϴ� �Լ� ��ü�� ��ȯ
template <typename RType, typename CType>
Mem_fun_class<RType, CType> Mem_fun(RType(CType::*pf) () const)
{
	return Mem_fun_class<RType, CType>(pf);
}

////////////////////////client/////////////////////////////
class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	int GetX() const { return x; }
	int GetY() const { return y; }
};

void main()
{
	vector<Point*> v;
	v.push_back(new Point(1, 1));
	v.push_back(new Point(2, 2));
	v.push_back(new Point(3, 3));
	v.push_back(new Point(4, 4));
	v.push_back(new Point(5, 5));

	//STL ����
	for_each(v.begin(), v.end(), mem_fun(&Point::Print));
	//����� ����
	for_each(v.begin(), v.end(), Mem_fun(&Point::Print));
	// ��ü delete ����
}