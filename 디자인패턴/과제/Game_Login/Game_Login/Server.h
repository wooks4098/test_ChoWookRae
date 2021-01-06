#pragma once
#include "Singleton.h"
#include "Player.h"
#include <vector>
using namespace std;
struct Player_data 
{
	Player* player;
	vector<Observer*> I_to_subscribe;// 내가 구독한 플레이어
	vector<Observer*> to_me_subscribe;// 나를 구독한 플레이어
};

class Server : public Singleton<Server>
{
private:
	vector<Player_data> player_data;
	//Player_data player_data;
public:

	void pushPlayer(Player* player);
	void Subscribe(Player* this_player,Player* player);
	Server();
	~Server();
};

