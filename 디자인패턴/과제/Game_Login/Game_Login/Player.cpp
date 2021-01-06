#include "Player.h"
#include "Server.h"


Player::Player()
{
	isBoot = false;
}

void Player::subscribe(Player* player)
{
	Server::GetInstance()->Subscribe(this ,player);
}

Player::~Player()
{
}
