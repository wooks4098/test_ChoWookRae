#include"IntManager.h"
#include"Test.h"
#include<Windows.h>

void main()
{
	int Select;
	while (true)
	{
		system("cls");
		cout << "�ڷ� ���� :" << IntManager::GetInstace()->GetSize() << endl;
		cout << "===�޴�===" << endl;
		cout << "1.�� �߰�" << endl;
		cout << "2.����" << endl;
		cout << "3.����" << endl;
		cin >> Select;
		switch (Select)
		{
		case 1:
			IntManager::GetInstace()->Insert();
			break;
		case 2:
			IntManager::GetInstace()->ShowList();
			system("pause");
			break;
		case 3:
		{
			Test t;
			delete IntManager::GetInstace();
			return;
		}
		}
	}
}

//Ŭ������ ��𼭵� �� �� �ְ� ����� ����
//�ϳ� �̻� ��������Ϸ���
//Ŭ���� ��ü�� ��üȭ �Ǵ� ��.