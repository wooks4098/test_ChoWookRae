#include "Login.h"



Login::Login()
{
}




void Login::MainMenu(int member_count)
{
	system("cls");
	cout << "=====Login=====(ȸ����[" << member_count << "��])" << endl;
	cout << "   1.ȸ�� ����" << endl;
	cout << "   2.�α���" << endl;
	cout << "   3.����" << endl;
	cout << "�Է�:";
}

bool Login::StreamCheck(char start, char end, char check)
{
	if (check >= start && check <= end)
		return true;
	else
		return false;
}

void Login::CreateID(People P[], int* member_count)
{
	string pwcheck;
	bool check = true;
	bool pw_number, pw_string;
	//id �߰�
	do
	{
		check = true;

		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]):";
		cin >> P[*member_count].id;
		if (*member_count != 0)
		{
			for (int i = 0; i < *member_count; i++)
			{
				if (P[i].id == P[*member_count].id)
				{
					cout << "�ߺ��Ǵ� ���̵� �ֽ��ϴ�." << endl;
					check = false;
				}
			}
		}
		if (P[*member_count].id.length() <= 2)
		{
			cout << "���̵� ������ ���� �Դϴ�." << endl;
			check = false;
		}
		for (int i = 0; i < P[*member_count].id.length(); i++)
		{
			if (StreamCheck('a', 'z', P[*member_count].id[i]) == false &&
				StreamCheck('A', 'Z', P[*member_count].id[i]) == false &&
				StreamCheck('0', '1', P[*member_count].id[i]) == false)
			{
				cout << "���̵� ���� �Ǵ� ���ڰ� �ƴմϴ�." << endl;
				check = false;
				break;
			}
		}

		if (check == true)
		{

			break;
		}

		system("pause");
	} while (1);
	//pw �߰�
	do
	{
		check = true;
		pw_number = false;
		pw_string = true;
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�] AND[����]AND[��������]}):";
		cin >> P[*member_count].password;
		cout << "��й�ȣ Ȯ�� : ";
		cin >> pwcheck;
		if (pwcheck != P[*member_count].password)
		{
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
			check = false;
		}
		if (P[*member_count].password.length() <= 7)
		{
			cout << "��й�ȣ�� 8���� ���� �Դϴ�." << endl;
			check = false;
		}

		for (int i = 0; i < P[*member_count].password.length(); i++)
		{
			if (StreamCheck('a', 'z', P[*member_count].password[i]) == false &&
				StreamCheck('A', 'Z', P[*member_count].password[i]) == false &&
				StreamCheck('0', '1', P[*member_count].password[i]) == false)
			{
				pw_string = false;
				check = false;
			}
			if (StreamCheck('0', '1', P[*member_count].password[i]) == true)
			{
				pw_number = true;
			}
		}
		if (pw_string == false)
			cout << "��й�ȣ�� ���� �Ǵ� ���� �ܿ� �ٸ� ���ڰ� ���ԵǾ� �ֽ��ϴ�." << endl;
		if (pw_number == false)
		{
			cout << "��й�ȣ�� ���ڰ� ���ԵǾ������ʽ��ϴ�." << endl;
			check = false;
		}
		if (check == true)
		{
			break;
		}
		system("pause");
	} while (1);
	//�г����߰�
	cout << "�г��� �Է� :";
	cin >> P[*member_count].nickname;
	//�����߰�
	cout << "���� �Է� :";
	cin >> P[*member_count].age;
	//�޴�����ȣ �߰�
	cout << "�޴��ȣ �Է� :";
	cin >> P[*member_count].phonenumber;
	//���ϸ��� ����
	cout << "ȸ������ ���� !! 1000���ϸ��� ����" << endl;
	P[*member_count].mileage = 1000;
	system("pause");
	*member_count += 1;
}

int Login::Login_try(People P[], int member_count)
{
	int member_number;
	string ID;
	string PW;
	bool check;
	bool IDcheck;
	while (1)
	{
		system("cls");
		IDcheck = false;
		check = false;
		cout << "���̵� �Է����ּ��� : ";
		cin >> ID;
		cout << "��й�ȣ�� �Է����ּ��� : ";
		cin >> PW;
		for (int i = 0; i < MAX; i++)
		{
			if (ID == P[i].id)
			{
				member_number = i;
				IDcheck = true;
				break;
			}
		}
		if (IDcheck == false)
			cout << "���� ���̵��Դϴ�" << endl;
		if (IDcheck == true)
		{
			if (PW == P[member_number].password)
			{
				check = true;
			}
			else
				cout << "�߸��� ��й�ȣ�Դϴ�" << endl;
		}
		if (check == true)
			break;
		system("pause");
	}
	return member_number;
}

void Login::LoginMenu()
{
	system("cls");
	cout << "=====Menu=====" << endl;
	cout << "   1.ȸ�� ����" << endl;
	cout << "   2.ȸ�� ���� ����" << endl;
	cout << "   3.�α׾ƿ�" << endl;
	cout << "�Է�:";
}

void Login::Member_info(People P[], int login_number)
{
	system("cls");
	cout << "===========ȸ������===========" << endl;
	cout << "ID : " << P[login_number].id << "	�г��� :	" << P[login_number].nickname << endl;
	cout << "���� : " << P[login_number].age << "	�޴��� ��ȣ :	" << P[login_number].phonenumber << endl;
	cout << "���ϸ��� : " << P[login_number].mileage << endl;
	system("pause");
}

void Login::Change_memberinfo(People P[], int login_number)
{
	int select;
	do
	{
		Member_info(P, login_number);
		cout << "======================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է�:";
		cin >> select;

		switch (select)
		{
		case 1:
			cout << endl << "���� �г���: " << P[login_number].nickname << endl;
			cout << "������ �г����Է� : ";
			cin >> P[login_number].nickname;
			break;
		case 2:
			cout << endl << "���� ����: " << P[login_number].age << endl;
			cout << "������ ���� �Է� : ";
			cin >> P[login_number].age;
			break;
		case 3:
			cout << endl << "���� �޴��� ��ȣ: " << P[login_number].phonenumber << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> P[login_number].phonenumber;
			break;

		}
	} while (select != 4);
}

int Login::Start()
{
	MainMenu(member_count);
	cin >> select;
	switch (select)
	{
	case 1:
		if (member_count == MAX)
		{
			cout << "ȸ������ 10���̹Ƿ� ȸ�������� �Ұ��մϴ�" << endl;
			system("pause");
		}
		else
			CreateID(member, &member_count);
		return LOGIN_CREAT_ID;
	case 2:
		login_number = Login_try(member, member_count);
		return LOGIN_LOGIN_TRY;
		break;
	case 3:
		return LOGIN_OFF;
		break;
	}
}


Login::~Login()
{
}
