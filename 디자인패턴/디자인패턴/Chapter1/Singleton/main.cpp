#include"IntManager.h"
#include<Windows.h>

void main()
{
	int Select;
	while (true)
	{
		system("cls");
		cout << "�ڷ� ���� :" << IntManager::GetInstance()->GetSize() << endl;
		cout << "===�޴�===" << endl;
		cout << "1.�� �߰�" << endl;
		cout << "2.����" << endl;
		cout << "3.����" << endl;
		cin >> Select;
		switch (Select)
		{
			case 1:
				IntManager::GetInstance()->Insert();
				break;
			case 2:
				IntManager::GetInstance()->ShowList();
				system("pause");
				break;
			case 3:
			{
				IntManager::DestroyInstance();
				return;
			}
		}
	}
}