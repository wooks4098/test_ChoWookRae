#include <iostream>
#include <set>
using namespace std;

//Exam_1
//void main()
//{
//	set<int> s; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ less�� �� �����̳� ����
//
//	s.insert(50); //�������� ����(key)�� �����Ѵ�.
//	s.insert(30);
//	s.insert(80);
//	s.insert(40);
//	s.insert(10);
//	s.insert(70);
//	s.insert(90);
//
//	set<int>::iterator iter; // �⺻ ���� ������ less�� set�� ����� �ݺ���
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " "; // inorder 2�� Ʈ�� Ž�� ������ ��µȴ�.
//	cout << endl;
//
//	s.insert(50); //�ߺ��� ����(key)�� �����Ѵ�. ����!!
//	s.insert(50);
//
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " "; // ����� ����.
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	set<int> s;
//
//	pair<set<int>::iterator, bool> pr;
//
//	pr = s.insert(50); // 50 ������ ù ��° ����
//	s.insert(40);
//	s.insert(80);
//
//	if (true == pr.second)
//		cout << *pr.first << " ���� ����!" << endl;
//	else
//		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����!" << endl;
//
//	set<int>::iterator iter;
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	pr = s.insert(50); // 50 ������ �� ��° ����. ����!!
//
//	if (true == pr.second)
//		cout << *pr.first << " ���� ����!" << endl;
//	else
//		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����!" << endl;
//
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_3
//void main()
//{
//	set<int> s;
//	pair<set<int>::iterator, bool> pr;
//
//	s.insert(50);
//	s.insert(30);
//	s.insert(80);
//	s.insert(40);
//	s.insert(10);
//	s.insert(70);
//	pr = s.insert(90); //pr.first�� 90������ �ݺ���
//
//
//	set<int>::iterator iter;
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	s.insert(pr.first, 85); //90������ �ݺ��ڿ��� �˻� ���� �� �����Ѵ�. 
//
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_4
//void main()
//{
//	set<int, greater<int> > s; // ���� �������� greater<int> �����ڸ� ���.
//
//	s.insert(50);
//	s.insert(30);
//	s.insert(80);
//	s.insert(40);
//	s.insert(10);
//	s.insert(70);
//	s.insert(90);
//
//
//	// greater<int> �����ڸ� ����ϴ� �ݺ��� ����
//	set<int, greater<int> >::iterator iter;
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_5
//void main()
//{
//	set<int> s;
//
//	s.insert(50);
//	s.insert(30);
//	s.insert(80);
//	s.insert(40);
//	s.insert(10);
//	s.insert(70);
//	s.insert(90);
//
//	set<int>::iterator iter;
//	for (iter = s.begin(); iter != s.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	iter = s.find(30); // 30�� �ݺ��ڸ� ��ȯ
//	if (iter != s.end())
//		cout << *iter << "�� s�� �ִ�!" << endl;
//	else
//		cout << "30�� s�� ����!" << endl;
//}

//Exam_6
//void main()
//{
//	set<int, less<int> > s; // ���� ���� less
//
//	// 30�� 50�� ��
//	cout << (!s.key_comp()(30, 50) 
//			&& !s.key_comp()(50, 30)) << endl; //�ٸ���
//	// 30�� 30�� ��
//	cout << (!s.key_comp()(30, 30) 
//			&& !s.key_comp()(30, 30)) << endl; //����(equivalence)
//}
