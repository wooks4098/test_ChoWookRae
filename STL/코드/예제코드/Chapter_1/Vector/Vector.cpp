#include <iostream>
#include <vector>
using namespace std;

//Exam_1
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	for (int i = 0; i < v.size(); ++i)
//		cout << v[i] << endl;
//}

//Exam_2
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << endl;
//
//	cout << typeid(vector<int>::size_type).name() << endl;
//}

//Exam_3
//void main()
//{
//	vector<int> v;
//
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
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	cout << v.max_size() << endl;
//}

//Exam_4
//void main()
//{
//	vector<int> v;
//
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(10);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(20);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(30);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(40);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(50);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(60);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(70);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(80);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(90);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//}

//Exam_5
//void main()
//{
//	vector<int> v;
//
//	v.reserve(8);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(10);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(20);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(30);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(40);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(50);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(60);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(70);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(80);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//	v.push_back(90);
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//}

//Exam_6
//void main()
//{
//	vector<int> v1(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
//	v1.push_back(10); //10 �߰�
//	v1.push_back(20); //20 �߰�
//	v1.push_back(30); //30 �߰�
//	v1.push_back(40); //40 �߰�
//	v1.push_back(50); //50 �߰�
//
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	vector<int> v2(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
//	v2[0] = 10; // 0���� 10�� ����
//	v2[1] = 20; // 0���� 20�� ����
//	v2[2] = 30; // 0���� 30�� ����
//	v2[3] = 40; // 0���� 40�� ����
//	v2[4] = 50; // 0���� 50�� ����
//
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//}

//Exam_7
//void main()
//{
//	vector<int> v1(5); //�⺻�� 0���� �ʱ�ȭ�� size�� 5�� �����̳�
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//
//	vector<int> v2(5, 0); //������ 0���� �ʱ�ȭ�� size�� 5�� �����̳�    
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//
//	vector<int> v3(5, 10); //������ 10���� �ʱ�ȭ�� size�� 5�� �����̳�    
//	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_8
//void main()
//{
//	vector<int> v(5); //�⺻�� 0���� �ʱ�ȭ�� size�� 5�� �����̳�
//
//	v[0] = 10;
//	v[1] = 20;
//	v[2] = 30;
//	v[3] = 40;
//	v[4] = 50;
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	v.resize(10); //�⺻�� 0���� �ʱ�ȭ�� size�� 10�� �����̳ʷ� Ȯ��
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	v.resize(5); //size�� 5�� �����̳ʷ� ��� capacity�� ��ȭ ����.
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//}

//Exam_9
//void main()
//{
//	vector<int> v(5);
//
//	v[0] = 10;
//	v[1] = 20;
//	v[2] = 30;
//	v[3] = 40;
//	v[4] = 50;
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	v.clear(); // v�� ����.
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	if (v.empty()) // v�� ����°�?
//	{
//		cout << "v�� ���Ұ� �����ϴ�." << endl;
//	}
//}

//Exam_10
//void main()
//{
//	vector<int> v(5);
//
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
//
//	vector<int>().swap(v);// �⺻ �����ڷ� ���� vector�����̳ʿ� v ���׾�ʸ� swap�Ѵ�.
//	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
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
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	cout << v[0] << ", " << v.front() << endl; // ù ��° ����
//	cout << v[4] << ", " << v.back() << endl; // ������ ����
//}

//Exam_12
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
//	v[0] = 100; //���� ���� ���� 0 index ������ ����
//	v[4] = 500; //���� ���� ���� 4 index ������ ����
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	v.at(0) = 1000; //���� ���� �ִ� 0 index ������ ����
//	v.at(4) = 5000; //���� ���� �ִ� 4 index ������ ����
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v.at(i) << " ";
//	cout << endl;
//}

//Exam_13
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	try
//	{
//		cout << v.at(0) << endl;
//		cout << v.at(3) << endl;
//		cout << v.at(6) << endl; //throw out_of_range ����
//	}
//	catch (out_of_range &e)
//	{
//		cout << e.what() << endl;
//	}
//}

//Exam_14
//void main()
//{
//	vector<int> v(5, 1); // �ʱⰪ 1�� 5���� ���Ҹ� ���� �����̳� ����
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//
//	v.assign(5, 2); // 5���� ���Ұ��� 2�� �Ҵ�
//	cout << v.size() << ',' << v.capacity() << endl;
//
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//
//	cout << endl;
//}

//Exam_15
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter = v.begin(); // ���� ����(10)�� ����Ų��.
//	cout << *iter << endl;
//
//	iter += 2; // +2�� ��ġ�� ����(30)�� ����Ų��.
//	cout << *iter << endl;
//
//	iter -= 1; // -1�� ��ġ�� ����(20)�� ����Ų��.
//	cout << *iter << endl;
//}

//Exam_16
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter = v.begin();
//	vector<int>::const_iterator citer = v.begin();
//
//	cout << *iter << endl; //����Ű�� ������ ����
//	cout << *citer << endl; //����Ű�� ������ ��� ����
//
//	cout << *++iter << endl; //���� ���ҷ� �̵��� ������ ����
//	cout << *++citer << endl; //���� ���ҷ� �̵��� ������ ��� ����
//
//	*iter = 100;  // �Ϲ� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����.
//	//*citer = 100; // ��� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����.
//}

//Exam_17
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter = v.begin() + 2;
//	vector<int>::iterator iter2;
//
//	// iter�� ����Ű�� ��ġ�� ���� 100�� ����.
//	// iter2�� ������ ������ ����Ű�� �ݺ���.
//	iter2 = v.insert(iter, 100);
//
//	for (iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//	cout << "iter2: " << *iter2 << endl;
//}

//Exam_18
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter = v.begin() + 2;
//
//	// iter�� ����Ű�� ��ġ�� ���� 100�� 3�� ����.   
//	v.insert(iter, 3, 100);
//
//	for (iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	/////////////////////////////////////////////////////
//	vector<int> v2;
//	v2.push_back(100);
//	v2.push_back(200);
//	v2.push_back(300);
//
//	iter = v2.begin() + 1;
//	// iter�� ����Ű�� ��ġ�� [v.begin(), v.end()) ������ ���Ҹ� ����.   
//	v2.insert(iter, v.begin(), v.end());
//
//	for (iter = v2.begin(); iter != v2.end(); ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_19
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter;
//	vector<int>::iterator iter2;
//	for (iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//
//	cout << endl;
//
//	iter = v.begin() + 2;
//	// iter�� ����Ű�� ��ġ�� ���Ҹ� �����մϴ�. iter2�� ���� ���� 40
//	iter2 = v.erase(iter);
//
//	for (iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//
//	cout << endl;
//
//	// [v.begin()+1, v.end()) ������ ���Ҹ� �����մϴ�.   
//	iter2 = v.erase(v.begin() + 1, v.end()); // iter2�� ���� ���� v.end()
//
//	for (iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << " ";
//
//	cout << endl;
//}

//Exam_20
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int> v2(v.begin(), v.end()); // ������ [v.begin(), v.end())�� v2�� �ʱ�ȭ.
//
//	vector<int>::iterator iter;
//
//	for (iter = v2.begin(); iter != v2.end(); ++iter)
//		cout << *iter << " "; // v2 ���
//
//	cout << endl;
//
//	vector<int> v3;
//	v3.assign(v.begin(), v.end());  // v3�� ������ [v.begin(), v.end())�� �Ҵ�.
//
//	for (iter = v3.begin(); iter != v3.end(); ++iter)
//		cout << *iter << " "; // v3 ���
//
//	cout << endl;
//}

//Exam_21
void main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(50);

	if (v1 == v2)
		cout << "v1 == v2" << endl;

	if (v1 != v2)
		cout << "v1 != v2" << endl;

	if (v1 < v2)
		cout << "v1 < v2" << endl;
}