#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Exam_1
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	// ������ �����̹Ƿ� next_permutation()�� false ��ȯ
//	cout << next_permutation(v.begin(), v.end()) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//}

//Exam_2
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
//	int GetX() const { return x; }
//	int GetY() const { return y; }
//};
//
//ostream& operator<<(ostream& out, const Point& arg)
//{   //Point ��ü cout ����� ���� ������ �����ε�
//	out << "(" << arg.GetX() << "," << arg.GetY() << ")";
//	return out;
//}
//
//bool Pred(const Point& left, const Point& right)
//{   //������ �� �������� ���� ���� ������
//	return left.GetY() < right.GetY();
//}
//
//void main()
//{
//	vector<Point> v;
//	v.push_back(Point(5, 1));
//	v.push_back(Point(7, 2));
//	v.push_back(Point(5, 3));
//
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//	// Point�� y�� �������� ������ �����̹Ƿ� next_permutation()�� false ��ȯ
//	cout << next_permutation(v.begin(), v.end(), Pred) << endl;;
//	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
//}

//Exam_3
//bool Pred(int n)
//{
//	return n < 40;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(60);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter_sep;
//	// 40 ���Ҹ� �������� �̸��� �̻��� �з��Ѵ�.
//	iter_sep = partition(v.begin(), v.end(), Pred);
//
//	cout << "40�̸��� ������: ";
//	for (vector<int>::iterator iter = v.begin(); iter != iter_sep; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "40�̻��� ������: ";
//	for (vector<int>::iterator iter = iter_sep; iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_4
//bool Pred(int n)
//{
//	return n < 40;
//}
//
//void main()
//{
//	vector<int> v;
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(60);
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter_sep;
//	// ���ҵ��� ������� ������ �����ϸ� 40 ���Ҹ� �������� �̸��� �̻��� �з��Ѵ�.
//	iter_sep = stable_partition(v.begin(), v.end(), Pred);
//
//	cout << "40�̸��� ������: ";
//	for (vector<int>::iterator iter = v.begin(); iter != iter_sep; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "40�̻��� ������: ";
//	for (vector<int>::iterator iter = iter_sep; iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_5
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	//#include <ctime>, #include <cstdlib> �߰� ���� �ʱⰪ
//	//srand( (unsigned)time(NULL) ); 
//
//	// ���Ҹ� �ڼ��´�.
//	random_shuffle(v.begin(), v.end());
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	// ���Ҹ� �ڼ��´�.
//	random_shuffle(v.begin(), v.end());
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}

//Exam_6
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	// [v.begin(), v.end()) ������ ������.
//	reverse(v.begin(), v.end());
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}

//Exam_7
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	cout << "v1 : ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	vector<int> v2(5); //size : 5 �� vector ���� (������̹Ƿ�)
//
//	vector<int>::iterator iter_end;
//	iter_end = reverse_copy(v1.begin(), v1.end(), v2.begin());
//
//	cout << "v2 : ";
//	for (vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_8
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator middle = v.begin() + 2;
//	// ��� ���Ҹ� �������� 2��ŭ�� ȸ���Ѵ�.
//	rotate(v.begin(), middle, v.end());
//
//	cout << "v : ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//}

//Exam_9
void main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5);
	vector<int>::iterator middle = v1.begin() + 2;
	vector<int>::iterator iter_end;
	// ��� ���Ҹ� �������� 2��ŭ�� ȸ���Ͽ� [v2.begin(), iter_end) �������� �����Ѵ�.
	iter_end = rotate_copy(v1.begin(), middle, v1.end(), v2.begin());

	cout << "v2 : ";
	for (vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}