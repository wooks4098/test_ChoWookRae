#include <iostream>
#include <set>
using namespace std;

//Exam_1
//void main()
//{
//	multiset<int> ms;
//	multiset<int>::iterator iter;
//
//	ms.insert(50);
//	ms.insert(30);
//	ms.insert(80);
//	ms.insert(80); // 80 �ߺ�
//	ms.insert(30); // 30 �ߺ�
//	ms.insert(70);
//	iter = ms.insert(10);
//
//	cout << "iter�� ����: " << *iter << endl;
//
//	for (iter = ms.begin(); iter != ms.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	multiset<int> ms;
//
//	ms.insert(50);
//	ms.insert(30);
//	ms.insert(80);
//	ms.insert(80); // 80 �ߺ�
//	ms.insert(30); // 30 �ߺ�
//	ms.insert(70);
//	ms.insert(10);
//
//	multiset<int>::iterator iter;
//	for (iter = ms.begin(); iter != ms.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	cout << "30 ������ ����: " << ms.count(30) << endl; // 30 ������ ����
//
//	iter = ms.find(30); // 30 ù ��° ������ �ݺ���
//	cout << "iter: " << *iter << endl;
//
//	multiset<int>::iterator lower_iter;
//	multiset<int>::iterator upper_iter;
//
//	lower_iter = ms.lower_bound(30); // 30 �������� ���� �ݺ���
//	upper_iter = ms.upper_bound(30); // 30 �������� �� ǥ�� �ݺ���
//	cout << "lower_iter: " << *lower_iter << ",  " << "upper_iter: " << *upper_iter << endl;
//
//	cout << "���� [lower_iter, upper_iter)�� ������: ";
//	for (iter = lower_iter; iter != upper_iter; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_3
void main()
{
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 �ߺ�
	ms.insert(30); // 30 �ߺ�
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//multiset�� �ݺ��� ��(pair) ��ü ����
	pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
	iter_pair = ms.equal_range(30);

	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << *iter << " "; //[iter_pair.first, iter_pair.second) ������ ������
	cout << endl;
}