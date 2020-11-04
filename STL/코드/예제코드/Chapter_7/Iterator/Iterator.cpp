#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

//Exam_1
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v[iterator �б� ����] : ";
//	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	cout << "v[const iterator �б� ����] : ";
//	for (vector<int>::const_iterator citer = v.begin(); citer != v.end(); ++citer)
//		cout << *citer << " ";
//	cout << endl;
//
//	vector<int>::iterator iter = v.begin();
//	vector<int>::const_iterator citer = v.begin();
//
//	*iter = 100; // ���� ����!
//	//*citer = 100; ���� �Ұ���! ����- ��� iterator�� ����Ű�� ���� ���� �Ұ�!
//}

//Exam_2
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//
//	vector<int>::iterator iter = v.begin();
//	vector<int>::const_iterator citer = v.begin() + 1;
//	const vector<int>::iterator const_iter = v.begin() + 2;
//	const vector<int>::const_iterator const_citer = v.begin() + 3;
//
//	//iter�� ��� ����
//	*iter = 100; // ����Ű�� ���� ���� ����
//	++iter; // �ݺ��� ���� ����
//
//	//citer
//	*citer = 200; // ����Ű�� ���� ���� �Ұ���
//	++citer; // �ݺ��� ���� ����
//
//	//const_iter
//	*const_iter = 300; // ����Ű�� ���� ���� ����
//	++const_iter; // �ݺ��� ���� �Ұ���
//
//	//const_citer
//	*const_citer = 400; // ����Ű�� ���� ���� �Ұ���
//	++const_citer; // �ݺ��� ���� �Ұ���
//}

//Exam_3
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
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//
//	list<int> lt;
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//
//	vector<int>::iterator viter = v.begin();
//	list<int>::iterator liter = lt.begin();
//
//	cout << "vector: " << *viter << endl;
//	cout << "list: " << *liter << endl;
//
//	cout << "vector: " << *viter << endl;
//	cout << "list: " << *liter << endl;
//
//	cout << "vector: " << *++viter << endl;
//	cout << "list: " << *++liter << endl;
//
//	cout << "vector: " << *--viter << endl;
//	cout << "list: " << *--liter << endl;
//
//	viter += 2; // ���� ���� �ݺ��ڴ� [], +=, -= +, -, <, >, <=, >=���� ����
//	//liter += 2; ����� �ݺ��ڴ� �Ұ���
//	cout << "=====================" << endl;
//
//
//	vector<Point> ptVector;
//	ptVector.push_back(Point(2, 5));
//
//	list<Point> ptList;
//	ptList.push_back(Point(2, 5));
//
//	vector<Point>::iterator ptVIter = ptVector.begin();
//	ptVIter->Print();
//	list<Point>::iterator ptLIter = ptList.begin();
//	ptLIter->Print();
//}

//Exam_4
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	cout << "v[iterator] : ";
//	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	cout << "v[reverse_iterator] : ";
//	for (vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); ++riter)
//		cout << *riter << " ";
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
//	//reverse_iterator ����ͷ� ������ �ݺ��ڸ� ������ �ݺ��ڷ� ��ȯ
//	reverse_iterator<vector<int>::iterator> rbiter(v.end());
//	reverse_iterator<vector<int>::iterator> reiter(v.begin());
//
//	cout << "v [rbiter, reiter) : ";
//
//	for (; rbiter != reiter; ++rbiter)
//		cout << *rbiter << " ";
//
//	cout << endl;
//
//	cout << "v [rbegin(), rend()) : ";
//
//	for (vector<int>::const_reverse_iterator riter = v.rbegin(); riter != v.rend(); ++riter)
//		cout << *riter << " ";
//
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
//	vector<int>::iterator iter = v.begin() + 1;
//	vector<int>::const_iterator citer = iter;
//
//	//vector<int>::reverse_iterator riter(iter)�� ����
//	reverse_iterator<vector<int>::iterator> riter(iter);
//	//vector<int>::const_reverse_iterator criter(riter)�� ����
//	reverse_iterator<vector<int>::const_iterator> criter(riter);
//
//	cout << "iter : " << *iter << endl;
//	cout << "citer : " << *citer << endl;
//	cout << "riter : " << *riter << endl;
//	cout << "criter : " << *criter << endl;
//	cout << "===================" << endl;
//	cout << "riter.base() => iter: " << *riter.base() << endl;
//	cout << "criter.base() => citer: " << *criter.base() << endl;
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
//	vector<int> v2; // size: 0�� vector ����
//	//copy(v1.begin(), v1.end(), v2.begin() ); //����!
//	//insert_iterator<vector<int> > insert(v2, v2.begin());
//	//copy(v1.begin(), v1.end(), insert ); ��ü ���� �� ȣ��
//	copy(v1.begin(), v1.end(), inserter<vector<int> >(v2, v2.begin()));
//
//	cout << "v1 : ";
//	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "v2 : ";
//	for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
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
//	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//
//	list<int> lt2;
//	lt2.push_back(1);
//	lt2.push_back(2);
//	lt2.push_back(3);
//
//	copy(v.begin(), v.end(), back_inserter<list<int> >(lt1));
//	copy(v.begin(), v.end(), front_inserter<list<int> >(lt2));
//
//	cout << "v : ";
//	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "lt1 : ";
//	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "lt2 : ";
//	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_9
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
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout));
//	cout << endl;
//
//	cout << "v : ";
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
//	cout << endl;
//
//	list<int> lt;
//	lt.push_back(100);
//	lt.push_back(200);
//	lt.push_back(300);
//
//	cout << "lt+v : ";
//	transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, "  "), plus<int>());
//	cout << endl;
//}

//Exam_10
//void main()
//{
//	vector<int> v;
//
//	//ǥ�� ��Ʈ������ ������ �Է¹޾� v�� ����.
//	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int> >(v));
//
//	cout << "v : ";
//	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	// ������ ��Ʈ�� ��(Ctrl-D)���� �Է� �޾� ȭ�鿡 ����մϴ�.
//	//copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout," ") );
//}

//Exam_11
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//
//	list<int> lt;
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//
//	vector<int>::iterator viter(v.begin());
//	list<int>::iterator liter(lt.begin());
//
//	cout << "viter: " << *viter << endl;
//	cout << "liter: " << *liter << endl;
//
//	advance(viter, 2); // viter += 2
//	advance(liter, 2);
//	cout << "viter: " << *viter << endl;
//	cout << "liter: " << *liter << endl;
//
//	advance(viter, -2); // viter -= 2
//	advance(liter, -2);
//	cout << "viter: " << *viter << endl;
//	cout << "liter: " << *liter << endl;
//}

//Exam_12
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//
//	list<int> lt;
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//
//	cout << "[v.begin(), v.end())�� ���� ����: " <<
//		distance(v.begin(), v.end()) << endl; //v.end()-v.begin()
//	cout << "[lt.begin(), lt.end())�� ���� ����: " <<
//		distance(lt.begin(), lt.end()) << endl;
//}

