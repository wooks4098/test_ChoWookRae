#include <iostream>
#include <map>
#include <string>
using namespace std;

void main()
{
	map<string, int> item;
	map<string, int>::iterator iter;
	item.insert(pair<string, int>("칼", 300));
	item.insert(pair<string, int>("총", 600));
	item.insert(pair<string, int>("헤머", 1600));

	cout << "상점" << endl;
	cout << "종류 : ";
	for (iter = item.begin(); iter != item.end(); ++iter)
		cout << iter->first << "   ";
	cout << endl;
	string str;
	cin >> str;

	
	iter = item.find(str);
	if(iter != item.end())
		cout << iter->first << ": " << iter->second << "GOLD" << endl;
	else
		cout << "해당 아이템이 없습니다" << endl;
	
}