#include <iostream>
#include "Set.h"
using namespace std;

void main()
{
	Set *wafer = new Wafer();
	wafer->Creat(new Monster_original, new Cola, new Original);

	Set *monster = new Monster();
	monster->Creat(new Monster_original, new Fanta, new Seasoned);

	cout << endl;
}
