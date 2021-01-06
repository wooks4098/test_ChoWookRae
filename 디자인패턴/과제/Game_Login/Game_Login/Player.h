#pragma once
#include "Observer.h"
#include <vector>
#include <string>
//using namespace std;

class Player : public Observer
{
private:
	bool isBoot;
public:

	void Login();
	void subscribe(Player* player);
	

	Player();
	~Player();
};

