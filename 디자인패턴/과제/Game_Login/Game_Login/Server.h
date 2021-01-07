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
	vector<Player_data*> player_data;
	//Player_data player_data;
public:
	void Login(Player* player);
	void pushPlayer(Player* player);
	void Subscribe(Player* Main_player, Player* player);
	void Alarm(Player_data Login_Player);
	Server();
	~Server();
};

