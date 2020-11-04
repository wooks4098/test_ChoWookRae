#include <iostream>
#include <vector>
#include <algorithm> //�˰��� ���
using namespace std;

//Exam_1
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(40);
//	v.push_back(50);
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter;
//	//���� [v.begin(), v.end())���� ���� ���ҿ� ���� ���Ұ� �������� ù ��° �ݺ��ڸ� ��ȯ
//	iter = adjacent_find(v.begin(), v.end());
//
//	if (iter != v.end()) //���� ���Ұ� ���ٸ� ������ �� �ݺ��� ��ȯ
//		cout << *iter << endl;
//
//	for (; iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter;
//	vector<int>::iterator iter_b = v.begin();
//	vector<int>::iterator iter_e = v.begin() + 2;
//	//���� [iter_b, iter_e)�� �������� 10, 20�̹Ƿ� 
//	//ã�� ���Ұ� ���� iter�� ������ ���� iter_e�Դϴ�.
//	iter = adjacent_find(iter_b, iter_e);
//
//	if (iter != iter_e) //ã�� ���Ұ� ������ Ȯ�� <<�´� ǥ��>> 
//		cout << *iter << endl;
//
//	cout << "==============" << endl;
//	if (iter != v.end()) //ã�� ���Ұ� ������ Ȯ�� <<Ʋ�� ǥ��>> 
//		cout << *iter << endl;
//
//	iter_b = v.begin();
//	iter_e = v.end();
//	iter = adjacent_find(iter_b, iter_e);
//
//	//��� �´� Ȯ��
//	if (iter != iter_e)
//		cout << *iter << endl;
//	if (iter != v.end())
//		cout << *iter << endl;
//}

//Exam_3
//���� ������
//bool Pred(int a, int b)
//{
//	return abs(b - a) > 10;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(50);
//	v.push_back(90);
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter;
//	iter = adjacent_find(v.begin(), v.end(), Pred);
//
//	if (iter != v.end())
//		cout << *iter << endl;
//
//	for (; iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exma_4
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(30);
//	v.push_back(50);
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	// ���� [v.begin(), v.end())���� 30 ������ ������ ��ȯ
//	int n = count(v.begin(), v.end(), 30);
//	cout << "30�� ����: " << n << endl;
//}

//Exam_5
//bool Pred(int n)
//{
//	return 25 < n;
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	// ���� [v.begin(), v.end())���� 25 ���� ū ������ ������ ��ȯ
//	int n = count_if(v.begin(), v.end(), Pred);
//	cout << "25���� ū ������ ���� :" << n << endl;
//}

//Exam_6
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(20);
//	v2.push_back(30);
//	v2.push_back(40);
//	v2.push_back(50);
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v2 : ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	//���� [v1.being(), v1.end)�� ���� [v2.begin(), v2.begin()+3)�� �� �մϴ�.
//	if (equal(v1.begin(), v1.end(), v2.begin()))
//		cout << "�� �������� �����ϴ�." << endl;
//}

//Exam_7
//bool Pred(int left, int right)
//{
//	return abs(right - left) < 5;
//}
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(21);
//	v1.push_back(30);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(20);
//	v2.push_back(33);
//
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	cout << "v2 : ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	//���� [v1.being(), v1.end)�� ���� [v2.begin(), v2.begin()+3)�� �� �մϴ�.
//	if (equal(v1.begin(), v1.end(), v2.begin(), Pred))
//		cout << "�� �������� �����ϴ�." << endl;
//}

//Exam_8
//bool Pred(int n)
//{
//	return 35 < n;
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	// ���� [v.begin(), v.end())���� 25 ���� ū ������ ������ ��ȯ
//	vector<int>::iterator iter;
//	iter = find(v.begin(), v.end(), 20);
//	if (iter != v.end())
//		cout << *iter << "�� ã��!" << endl;
//
//	iter = find_if(v.begin(), v.end(), Pred);
//	if (iter != v.end())
//		cout << "���������� 35���� ū ù ��° ����: " << *iter << endl;
//}

//Exam_9
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	v1.push_back(60);
//	v1.push_back(70);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(30);
//	v2.push_back(40);
//	v2.push_back(50);
//
//	vector<int>::iterator iter;
//	iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
//	if (iter != v1.end())
//	{
//		// ��ġ�ϴ� ������ �������� ù ������ �ݺ��� iter
//		cout << "iter : " << *iter << endl;
//		cout << "iter-1 : " << *(iter - 1) << endl;
//		cout << "iter+1 : " << *(iter + 1) << endl;;
//	}
//}

//Exam_10
//bool Pred(int left, int right)
//{
//	return left <= right;
//}
//
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(15);
//	v1.push_back(20);
//	v1.push_back(40);
//	v1.push_back(50);
//	v1.push_back(60);
//	v1.push_back(10);
//	v1.push_back(11);
//	v1.push_back(12);
//	v1.push_back(80);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(15);
//	v2.push_back(25);
//
//	vector<int>::iterator iter;
//	iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred);
//	if (iter != v1.end())
//	{
//		// ��ġ�ϴ� ������ �������� ù ������ �ݺ��� iter
//		cout << "iter : " << *iter << endl;
//		cout << "iter-1 : " << *(iter - 1) << endl;
//		cout << "iter+1 : " << *(iter + 1) << endl;;
//	}
//}

//Exam_11
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
//	v2.push_back(40);
//	v2.push_back(80);
//	v2.push_back(20);
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//	cout << "v2 : ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter;
//	iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
//	if (iter != v1.end())
//		cout << "iter : " << *iter << endl;
//}

//Exam_12
//bool Pred(int left, int right)
//{
//	return left > right;
//}
//
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
//	v2.push_back(40);
//	v2.push_back(80);
//	v2.push_back(20);
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//	cout << "v2 : ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter;
//	iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred);
//	if (iter != v1.end())
//		cout << "iter : " << *iter << endl;
//}

//Exam_13
//void Print(int n)
//{
//	cout << n << " ";
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
//	for_each(v.begin(), v.begin() + 2, Print);
//	cout << endl;
//	for_each(v.begin(), v.begin() + 4, Print);
//	cout << endl;
//	//[v.begin(), v.end()) ������ ���� ���
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//}

//Exam_14
//class PrintFunctor
//{
//	char fmt;
//public:
//	explicit PrintFunctor(char c = ' ') :fmt(c) { }
//	void operator ()(int n) const
//	{
//		cout << n << fmt;
//	}
//};
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
//	for_each(v.begin(), v.end(), PrintFunctor()); // ������ ������ ' '��
//	cout << endl;
//	for_each(v.begin(), v.end(), PrintFunctor(','));// ������ ������ ','��
//	cout << endl;
//	for_each(v.begin(), v.end(), PrintFunctor('\n'));// ������ ������ '\n'��
//	cout << endl;
//}

//Exam_15
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(20);
//	v2.push_back(50);
//
//	vector<int> v3;
//	v3.push_back(10);
//	v3.push_back(20);
//	v3.push_back(30);
//
//	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
//		cout << "v1 < v2" << endl;
//	else
//		cout << "v1 >= v2" << endl;
//
//	if (lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()))
//		cout << "v1 < v3" << endl;
//	else
//		cout << "v1 >= v3" << endl;
//}

//Exam_16
//template< typename T>
//struct Less
//{
//	bool operator()(const T& left, const T& right) const
//	{
//		return left < right;
//	}
//};
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(25);
//	v2.push_back(30);
//
//	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>()))
//		cout << "���� less v1�� v2�� ��: true" << endl;
//	else
//		cout << "���� less v1�� v2�� ��: false" << endl;
//
//
//	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()))
//		cout << "���� greater v1�� v2�� ��: true" << endl;
//	else
//		cout << "���� greater v1�� v2�� ��: false" << endl;
//
//
//	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), Less<int>()))
//		cout << "����� ���� Less v1�� v2�� ��: true" << endl;
//	else
//		cout << "����� ���� Less v1�� v2�� ��: false" << endl;
//}

//Exam_17
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	int GetX() const { return x; }
//	int GetY() const { return y; }
//	void Print() const { cout << '(' << x << ',' << y << ')' << endl; }
//};
//bool XCompare(const Point& left, const Point& right)
//{
//	return left.GetX() < right.GetX();
//}
//bool YCompare(const Point& left, const Point& right)
//{
//	return left.GetY() < right.GetY();
//}
//void main()
//{
//	int a = 10, b = 20;
//	int r;
//
//	r = max(a, b);
//	cout << "max: " << r << endl;
//	r = min(a, b);
//	cout << "min: " << r << endl;
//
//	Point pt1(5, 8), pt2(3, 9);
//	Point pt3;
//
//	pt3 = max(pt1, pt2, XCompare);
//	cout << "x max: "; pt3.Print();
//	pt3 = max(pt1, pt2, YCompare);
//	cout << "y max: "; pt3.Print();
//}

//Exam_18
//void main()
//{
//	vector<int> v;
//
//	v.push_back(30);
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(40);
//
//	vector<int>::iterator iter;
//	iter = max_element(v.begin(), v.end());
//	cout << *iter << endl;
//
//	iter = min_element(v.begin(), v.end());
//	cout << *iter << endl;
//}

//Exam_19
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	int GetX() const { return x; }
//	int GetY() const { return y; }
//	void Print() const { cout << '(' << x << ',' << y << ')' << endl; }
//};
//bool Compare(const Point& left, const Point& right)
//{
//	if (left.GetX() < right.GetX())
//		return true;
//	else if (left.GetX() > right.GetX())
//		return false;
//	else
//		return left.GetY() < right.GetY();
//}
//void main()
//{
//	vector<Point> v;
//
//	v.push_back(Point(3, 2));
//	v.push_back(Point(2, 5));
//	v.push_back(Point(1, 5));
//	v.push_back(Point(3, 3));
//	v.push_back(Point(3, 2));
//
//	vector<Point>::iterator iter;
//	iter = max_element(v.begin(), v.end(), Compare);
//	cout << "max: "; iter->Print(); //�ݺ��ڰ� ����Ű�� ��ü�� ����� -> �����ڷ� ����
//	cout << "max: "; (*iter).Print(); //���� ����
//}

//Exam_20
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
//	v2.push_back(10);
//	v2.push_back(20);
//	v2.push_back(30);
//	v2.push_back(80);
//	v2.push_back(90);
//
//	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
//	iter_pair = mismatch(v1.begin(), v1.end(), v2.begin());
//
//	cout << "v1: " << *iter_pair.first << ", " << "v2: " << *iter_pair.second << endl;
//}

//Exam_21
//bool Pred(int left, int right)
//{
//	return abs(right - left) <= 5;
//}
//
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
//	v2.push_back(11);
//	v2.push_back(25);
//	v2.push_back(33);
//	v2.push_back(46);
//	v2.push_back(50);
//
//	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
//	iter_pair = mismatch(v1.begin(), v1.end(), v2.begin(), Pred);
//
//	cout << "v1: " << *iter_pair.first << ", " << "v2: " << *iter_pair.second << endl;
//}

//Exam_22
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	v1.push_back(60);
//	v1.push_back(70);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(30);
//	v2.push_back(40);
//	v2.push_back(50);
//
//	vector<int>::iterator iter;
//	iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());
//	if (iter != v1.end())
//	{
//		// ��ġ�ϴ� ù ��° �������� ù ������ �ݺ��� iter
//		cout << "iter : " << *iter << endl;
//		cout << "iter-1 : " << *(iter - 1) << endl;
//		cout << "iter+1 : " << *(iter + 1) << endl;;
//	}
//}

//Exam_23
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//
//	vector<int>::iterator iter;
//	iter = search_n(v.begin(), v.end(), 3, 30);
//	if (iter != v.end())
//	{
//		cout << "iter : " << *iter << endl;
//		cout << "iter-1 : " << *(iter - 1) << endl;
//		cout << "iter+1 : " << *(iter + 1) << endl;;
//	}
//}

//Exam_24
bool Pred(int left, int right)
{
	return abs(right - left) <= 5;
}

void main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(32);
	v.push_back(28);
	v.push_back(33);
	v.push_back(40);
	v.push_back(50);


	vector<int>::iterator iter;
	iter = search_n(v.begin(), v.end(), 3, 30, Pred);
	if (iter != v.end())
	{
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;;
	}
}