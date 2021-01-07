#include "Player.h"
#include "Server.h"
#include <iostream>

Player::Player(string name)
{
	Name = name;
	isBoot = false;
}

void Player::Login()
{
	Server::GetInstance()->Login(this);
}

void Player::subscribe(Player* player)
{
	Server::GetInstance()->Subscribe(this ,player);
}
void Player::Alarm(string name)
{
	cout << Name << "<-";
	cout << name << "���� �����ϼ̽��ϴ�."<< endl << endl;
}
Player::~Player()
{
}
