#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//Exam_1
//void main()
//{
//	deque<int> dq;
//
//	for (deque<int>::size_type i = 0; i < 10; ++i)
//		dq.push_back((i + 1) * 10);
//
//	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
//		cout << dq[i] << ' ';
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	vector<int> v(4, 100); //100���� �ʱ�ȭ�� 4���� ���Ҹ� ���� �����̳� v
//	deque<int> dq(4, 100); //100���� �ʱ�ȭ�� 4���� ���Ҹ� ���� �����̳� dq
//
//	v.push_back(200); // v�� 200 �߰�
//	dq.push_back(200); // dq�� 200 �߰�
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
//		cout << dq[i] << " ";
//	cout << endl;
//}

//Exam_3
//void main()
//{
//	deque<int> dq;
//
//	dq.push_back(10);
//	dq.push_back(20);
//	dq.push_back(30);
//	dq.push_back(40);
//	dq.push_back(50);
//
//	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
//		cout << dq[i] << " ";
//	cout << endl;
//
//	dq.push_front(100); // ���ʿ� �߰��մϴ�.
//	dq.push_front(200);
//	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
//		cout << dq[i] << " ";
//	cout << endl;
//}

//Exam_4
//void main()
//{
//	deque<int> dq;
//
//	dq.push_back(10);
//	dq.push_back(20);
//	dq.push_back(30);
//	dq.push_back(40);
//	dq.push_back(50);
//
//	deque<int>::iterator iter;
//	for (iter = dq.begin(); iter != dq.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	iter = dq.begin() + 2; //�ݺ��ڿ� +2�մϴ�.
//	cout << *iter << endl;
//
//	iter += 2; //�ݺ��ڿ� +2�մϴ�.
//	cout << *iter << endl;
//
//	iter -= 3; //�ݺ��ڿ� -3�մϴ�.
//	cout << *iter << endl;
//}

//Exam_5
void main()
{
	deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);

	deque<int>::iterator iter;
	deque<int>::iterator iter2;
	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;


	iter = dq.begin() + 2;
	iter2 = dq.insert(iter, 500);
	cout << *iter2 << endl;

	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}