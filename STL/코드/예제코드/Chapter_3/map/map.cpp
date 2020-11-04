#include <iostream>
#include <map>
using namespace std;

//Exam_1
//void main()
//{
//	//key, value ��� �������� �����̳� ����
//	//�⺻ ���� ���� less
//	map<int, int> m;
//
//	m.insert(pair<int, int>(5, 100)); // �ӽ� pair ��ü ���� �� ����
//	m.insert(pair<int, int>(3, 100));
//	m.insert(pair<int, int>(8, 30));
//	m.insert(pair<int, int>(4, 40));
//	m.insert(pair<int, int>(1, 70));
//	m.insert(pair<int, int>(7, 100));
//
//	pair<int, int> pr(9, 50);
//	m.insert(pr); // pr ��ü ���� �� ����
//
//	map<int, int>::iterator iter;
//	for (iter = m.begin(); iter != m.end(); ++iter)
//		cout << "(" << (*iter).first << ',' << (*iter).second << ")" << " ";
//	cout << endl;
//
//	// �ݺ��ڴ� -> �����ڰ� ������ �����ε��Ǿ� �����Ƿ� 
//	//������ó�� ����� -> �����ڷ� ������ �� �ֽ��ϴ�. 
//	for (iter = m.begin(); iter != m.end(); ++iter)
//		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
//	cout << endl;
//}

//Exam_2
//void main()
//{
//	map<int, int> m;
//	pair<map<int, int>::iterator, bool> pr; // insert() ��� pair ��ü
//
//	m.insert(pair<int, int>(5, 100));
//	m.insert(pair<int, int>(3, 100));
//	m.insert(pair<int, int>(8, 30));
//	m.insert(pair<int, int>(4, 40));
//	m.insert(pair<int, int>(1, 70));
//	m.insert(pair<int, int>(7, 100));
//
//	pr = m.insert(pair<int, int>(9, 50)); // ����!
//	if (true == pr.second)
//		cout << "key: " << pr.first->first << ", value: " << pr.first->second << " ���� �Ϸ�!" << endl;
//	else
//		cout << "key 9�� �̹� m�� �ֽ��ϴ�." << endl;
//
//	pr = m.insert(pair<int, int>(9, 50)); // ����!
//	if (true == pr.second)
//		cout << "key: " << pr.first->first << ", value: " << pr.first->second << "���� �Ϸ�!" << endl;
//	else
//		cout << "key: 9�� �̹� m�� �ֽ��ϴ�." << endl;
//}

//Exam_3
//void main()
//{
//	map<int, int> m;
//
//	m[5] = 100; //key 5, value 100�� ���Ҹ� m�� �����Ѵ�.
//	m[3] = 100;
//	m[8] = 30;
//	m[4] = 40;
//	m[1] = 70;
//	m[7] = 100;
//	m[9] = 50;
//
//	map<int, int>::iterator iter;
//	for (iter = m.begin(); iter != m.end(); ++iter)
//		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
//	cout << endl;
//
//	m[5] = 200; //key 5�� value�� 200���� �����Ѵ�.
//
//	for (iter = m.begin(); iter != m.end(); ++iter)
//		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
//	cout << endl;
//}

//Exam_4
//#include <string>
//
//void main()
//{
//	// greater ���� ������ key:int, value:string Ÿ���� ���״Ͼ� m ����.
//	map<int, string, greater<int> > m;
//
//	m[5] = "five"; // ���� �߰�
//	m[3] = "three";
//	m[8] = "eight";
//	m[4] = "four";
//	m[1] = "one";
//	m[7] = "seven";
//	m[9] = "nine";
//
//	map<int, string, greater<int> >::iterator iter;
//	for (iter = m.begin(); iter != m.end(); ++iter)
//		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
//	cout << endl;
//
//	//map�� ����� ���Ҹ� ���� ����ϴ� ��� �����ڸ� �������� �ʱ� ������
//	//string �����̳ʸ� include���ؼ� ����ؼ� �����ڸ� �����´�.
//	cout << m[9] << " "; //key�� ���ε� value�� ����մϴ�.
//	cout << m[8] << " ";
//	cout << m[7] << " ";
//	cout << m[5] << " ";
//	cout << m[4] << " ";
//	cout << m[3] << " ";
//	cout << m[1] << endl;
//}

//Exam_5
void main()
{
	map<int, int> m;

	m[5] = 100;
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;

	iter = m.find(5);
	if (iter != m.end())
		cout << "key 5�� ���ε� value: " << iter->second << endl;

	map<int, int>::iterator lower_iter;
	map<int, int>::iterator upper_iter;
	lower_iter = m.lower_bound(5);
	upper_iter = m.upper_bound(5);

	cout << "���� [lower_iter, upper_iter)�� ������: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
	iter_pair = m.equal_range(5);

	cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;
}
