/*
플레이어 온기능
플레이어끼리 구독기능
플레이어가 온 되면 서버에서 해당 플레이어를 구독한 플레이어에게 접속했다고 알려줌

서버
로그인
알림

플레이어
로그인
알람
친구등록


*/

#include "Player.h"
#include "Server.h"
#include <iostream>
using namespace std;

void main()
{
	Server sever;

	Player *p1 = new Player;
	Player *p2 = new Player;
	sever.pushPlayer(p1);
	sever.pushPlayer(p2);

}