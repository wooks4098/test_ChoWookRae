

#include "Player.h"
#include "Server.h"
#include <iostream>
using namespace std;

void main()
{

	Player *p1 = new Player("플레이어");
	Player *p2 = new Player("디모");
	Server::GetInstance()->pushPlayer(p1);
	Server::GetInstance()->pushPlayer(p2);

	p1->subscribe(p2);

	p1->Login();
	p2->Login();

}