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
	Server sever;

	Player *p1 = new Player;
	Player *p2 = new Player;
	sever.pushPlayer(p1);
	sever.pushPlayer(p2);

}