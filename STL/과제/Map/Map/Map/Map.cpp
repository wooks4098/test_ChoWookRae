#include <iostream>
#include <map>
#include <string>
using namespace std;

void main()
{
	map<string, int> item;
	map<string, int>::iterator iter;
	item.insert(pair<string, int>("Į", 300));
	item.insert(pair<string, int>("��", 600));
	item.insert(pair<string, int>("���", 1600));

	cout << "����" << endl;
	cout << "���� : ";
	for (iter = item.begin(); iter != item.end(); ++iter)
		cout << iter->first << "   ";
	cout << endl;
	string str;
	cin >> str;

	
	iter = item.find(str);
	if(iter != item.end())
		cout << iter->first << ": " << iter->second << "GOLD" << endl;
	else
		cout << "�ش� �������� �����ϴ�" << endl;
	
}