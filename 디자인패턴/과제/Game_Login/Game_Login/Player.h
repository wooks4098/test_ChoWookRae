#pragma once
#include "Observer.h"
#include <vector>
#include <string>
//using namespace std;

class Player : public Observer
{
private:
	bool isBoot;
	string Name;
public:

	void Login();
	void subscribe(Player* player);
	string Return_Name()
	{
		return Name;
	}
	void Alarm(string name);
	Player(string name);
	~Player();
};

