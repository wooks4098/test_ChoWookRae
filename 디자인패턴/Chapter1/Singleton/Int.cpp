#include "Int.h"

Int::Int()
{
	cout << "�Է�" << endl;
	cout << "x : ";
	cin >> x;
	cout << "y : ";
	cin >> y;
}

void Int::Show()
{
	cout << "=============================================" << endl;
	cout << "x : " << x << endl << "y : " << y << endl;
	cout << "=============================================" << endl;

}

Int::~Int()
{
}
