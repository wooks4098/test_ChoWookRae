/*
�÷��̾� �±��
�÷��̾�� �������
�÷��̾ �� �Ǹ� �������� �ش� �÷��̾ ������ �÷��̾�� �����ߴٰ� �˷���

����
�α���
�˸�

�÷��̾�
�α���
�˶�
ģ�����


*/

#include "Player.h"
#include "Server.h"
#include <iostream>
using namespace std;

void main()
{

	Player *p1 = new Player("�÷��̾�");
	Player *p2 = new Player("���");
	Server::GetInstance()->pushPlayer(p1);
	Server::GetInstance()->pushPlayer(p2);

	p1->subscribe(p2);

	p1->Login();
	p2->Login();

}