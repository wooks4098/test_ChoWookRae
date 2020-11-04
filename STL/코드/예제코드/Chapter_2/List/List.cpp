//Exam_1
#include <iostream>
#include <vector>
#include <list>
using namespace std;

//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.push_front(100);
//	lt.push_front(200);
//
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//
//	list<int>::iterator iter = lt.begin();
//	list<int>::iterator iter2;
//	++iter;
//	++iter;
//
//	iter2 = lt.erase(iter); //iter(30)�� ���Ҹ� �����մϴ�.
//
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	cout << "iter2 : " << *iter2 << endl;
//
//	iter = iter2;
//	iter2 = lt.insert(iter, 300); //iter2(40)�� ����Ű�� ��ġ�� 300�� �����մϴ�.
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	cout << "iter2 : " << *iter2 << endl;
//}

//Exam_3
//void main()
//{
//	vector<int> v;
//	list<int> lt;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//
//	vector<int>::iterator viter = v.begin();
//	++viter; // 20���Ҹ� ����Ŵ
//	list<int>::iterator liter = lt.begin();
//	++liter; // 20���Ҹ� ����Ŵ
//
//	viter = v.insert(viter, 600); // v�� �� ��° ��ҷ� ����
//	liter = lt.insert(liter, 600); // lt�� �� ��° ��ҷ� ����
//
//	cout << "vector: " << *viter << endl;
//	cout << "list: " << *liter << endl;
//
//	cout << "vector : ";
//	for (viter = v.begin(); viter != v.end(); ++viter)
//		cout << *viter << ' ';
//	cout << endl;
//
//	cout << "list : ";
//	for (liter = lt.begin(); liter != lt.end(); ++liter)
//		cout << *liter << ' ';
//	cout << endl;
//}

//Exam_4
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(10);
//	lt.push_back(40);
//	lt.push_back(50);
//	lt.push_back(10);
//	lt.push_back(10);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.remove(10); // 10 ������ ��带 ��� ����
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_5
//bool Predicate(int n) // ���� ������
//{
//	return 10 <= n && n <= 30;
//}
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//	lt.push_back(10);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.remove_if(Predicate); // �����ڰ� ���� ��� ���Ҹ� �����մϴ�.
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_6
//void main()
//{
//	list<int> lt1;
//	list<int> lt2;
//
//	lt1.push_back(10);
//	lt1.push_back(20);
//	lt1.push_back(30);
//	lt1.push_back(40);
//	lt1.push_back(50);
//
//	lt2.push_back(100);
//	lt2.push_back(200);
//	lt2.push_back(300);
//	lt2.push_back(400);
//	lt2.push_back(500);
//
//	list<int>::iterator iter1;
//	list<int>::iterator iter2;
//	cout << "lt1: ";
//	for (iter1 = lt1.begin(); iter1 != lt1.end(); ++iter1)
//		cout << *iter1 << ' ';
//	cout << endl;
//
//	cout << "lt2: ";
//	for (iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
//		cout << *iter2 << ' ';
//	cout << endl << "=============" << endl;
//
//	iter1 = lt1.begin();
//	++iter1;
//	++iter1; // 30 ������ ��ġ�� ����Ŵ
//
//	iter2 = lt2.begin();
//	++iter2; // 200 ������ ��ġ�� ����Ŵ
//
//	//iter1�� ����Ű�� ��ġ�� iter2�� ����Ű�� ��ġ�� lt2�� ���Ҹ� �߶� ����
//	lt1.splice(iter1, lt2, iter2);
//
//	cout << "lt1: ";
//	for (iter1 = lt1.begin(); iter1 != lt1.end(); ++iter1)
//		cout << *iter1 << ' ';
//	cout << endl;
//
//	cout << "lt2: ";
//	for (iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
//		cout << *iter2 << ' ';
//	cout << endl << "=============" << endl;
//
//	//lt1.end()�� ����Ű�� ��ġ�� ������ [lt2.begin(), lt2.end())�� �߶� ����
//	lt1.splice(lt1.end(), lt2, lt2.begin(), lt2.end());
//
//	cout << "lt1: ";
//	for (iter1 = lt1.begin(); iter1 != lt1.end(); ++iter1)
//		cout << *iter1 << ' ';
//	cout << endl;
//
//	cout << "lt2: ";
//	for (iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
//		cout << *iter2 << ' ';
//	cout << endl;
//}

//Exam_7
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(30);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//	lt.push_back(10);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.unique();
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_8
//bool Predicate(int first, int second)
//{
//	return second - first <= 0;
//}
//
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_back(30);
//	lt.push_back(30);
//	lt.push_back(40);
//	lt.push_back(50);
//	lt.push_back(10);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.unique(Predicate);
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_9
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(20);
//	lt.push_back(10);
//	lt.push_back(50);
//	lt.push_back(30);
//	lt.push_back(40);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.sort(); // ��������( less, < ����) ����
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_10
//struct Greater
//{
//	bool operator () (int left, int right) const
//	{
//		return left > right;
//	}
//};
//
//void main()
//{
//	list<int> lt;
//
//	lt.push_back(20);
//	lt.push_back(10);
//	lt.push_back(50);
//	lt.push_back(30);
//	lt.push_back(40);
//
//	list<int>::iterator iter;
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.sort(greater<int>()); // ������ greater�� ����Ͽ� �������� ����
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.sort(less<int>()); // ������ less�� ����Ͽ� �ٽ� �������� ����
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	lt.sort(Greater()); // ����� ���� �����ڸ� ����Ͽ� �������� ����
//	for (iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_11
//void main()
//{
//	list<int> lt1;
//	list<int> lt2;
//
//	lt1.push_back(10);
//	lt1.push_back(20);
//	lt1.push_back(30);
//	lt1.push_back(40);
//	lt1.push_back(50);
//
//	lt2.push_back(25);
//	lt2.push_back(35);
//	lt2.push_back(60);
//
//
//	list<int>::iterator iter;
//	cout << "lt1: ";
//	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	cout << "lt2: ";
//	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl << "===============" << endl;
//
//	lt1.merge(lt2); // lt2�� lt1���� �պ� �����մϴ�. ���� ������ less
//
//	cout << "lt1: ";
//	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//
//	cout << "lt2: ";
//	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
//		cout << *iter << ' ';
//	cout << endl;
//}

//Exam_12
void main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(50);
	lt1.push_back(40);
	lt1.push_back(30);
	lt1.push_back(20);
	lt1.push_back(10);

	//lt2.push_back(25); //lt1�� lt2�� ���� ����� �ٸ��Ƿ� ����
	//lt2.push_back(35);
	//lt2.push_back(60);

	// lt1�� lt2�� ���� ����� ����.
	// greater ������( > ���� ) ���� ������ �����
	lt2.push_back(60);
	lt2.push_back(35);
	lt2.push_back(25);


	list<int>::iterator iter;
	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << "===============" << endl;

	// lt2�� lt1���� �պ� �����մϴ�. 
	// �� list�� ���� ������ > ������ greater��� ���� predicate�� �����մϴ�.
	lt1.merge(lt2, greater<int>());

	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}