#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;
template<typename T>
struct Logical_and : public binary_function<T, T, bool> //����� ������ �����ϵ���.
{
	bool operator( )(const T& left, const T& right) const
	{
		return left && right;
	}
};
void main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	cout << "v[iterator] : ";
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "v[reverse_iterator] : ";
	for (vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); ++riter)
		cout << *riter << " ";
	cout << endl;
}