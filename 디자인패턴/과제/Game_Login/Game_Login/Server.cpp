#include "Server.h"



Server::Server()
{

}


void Server::pushPlayer(Player* player)
{
	Player_data* Player = new Player_data;
	Player->player = player;
	player_data.push_back(Player);
}


void Server::Subscribe(Player* Main_player, Player* player)
{
	Player_data *MainPlayer_data, *Subscribe_player;
	for (auto iter = player_data.begin(); iter != player_data.end(); iter++)
	{
		if ((*iter)->player->Return_Name() == Main_player->Return_Name())
		{
			MainPlayer_data = *iter;
			break;
		}
	}

	for (auto iter = player_data.begin(); iter != player_data.end(); iter++)
	{
		if ((*iter)->player->Return_Name() == player->Return_Name())
		{
			Subscribe_player = *iter;
			break;
		}
	}
	MainPlayer_data->I_to_subscribe.push_back(Subscribe_player->player);
	Subscribe_player->to_me_subscribe.push_back(MainPlayer_data->player);

}

void Server::Login(Player* player)
{
	Player_data *Login_player;
	for (auto iter = player_data.begin(); iter != player_data.end(); iter++)
	{
		if ((*iter)->player->Return_Name() == player->Return_Name())
		{
			Login_player = *iter;
			break;
		}
	}
	cout << player->Return_Name() << " 접속완료" << endl << endl;
	Alarm(*Login_player);

}
void Server::Alarm(Player_data Login_Player)
{
	for (auto iter = Login_Player.to_me_subscribe.begin(); iter != Login_Player.to_me_subscribe.end(); iter++)
	{
		(*iter)->Alarm(Login_Player.player->Return_Name());
	}
}



Server::~Server()
{
}
