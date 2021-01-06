#include "Server.h"



Server::Server()
{

}


void Server::pushPlayer(Player* player)
{
	Player_data d;
	player_data.push_back(d);

	player_data.Players.push_back(player);
}


void Server::Subscribe(Player* this_player, Player* player)
{
	
}






Server::~Server()
{
}
