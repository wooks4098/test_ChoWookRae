#include "Login.h"



Login::Login()
{
	m_iIdCount = 0;
}
void Login::SimpleShowID()
{
	cout << "============ȸ�� ����============" << endl;
	cout << "ID : " << m_Id_List[m_iCurIdIndex].m_strID << "   �г��� : " << m_Id_List[m_iCurIdIndex].m_strName << endl;
}
void Login::ShowID()
{
	system("cls");
	SimpleShowID();
	cout << " ���� : " << m_Id_List[m_iCurIdIndex].m_iAge << "��" << "   �޴��� ��ȣ : " << m_Id_List[m_iCurIdIndex].m_strPhonNumber << endl;
	cout << "���ϸ��� : " << m_Id_List[m_iCurIdIndex].m_iMileage << "��" << endl;
}

void Login::Setstring(string* str, string tmp)
{
	string tmpstr;
	tmpstr = *str;
	cout << "���� " << tmp << ": " << tmpstr << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *str;
	cout << tmpstr << " -> " << *str << endl;
	system("pause");
}

void Login::Setint(int* num, string tmp)
{
	int tmpint;
	tmpint = *num;
	cout << "���� " << tmp << " : " << tmpint << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *num;
	cout << tmpint << " -> " << *num << endl;
	system("pause");
}

void Login::SetID()
{
	int Select;
	while (1)
	{
		ShowID();
		cout << "===================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Setstring(&m_Id_List[m_iCurIdIndex].m_strName, "�г���");
			break;
		case 2:
			Setint(&m_Id_List[m_iCurIdIndex].m_iAge, "����");
			break;
		case 3:
			Setstring(&m_Id_List[m_iCurIdIndex].m_strPhonNumber, "�޴��� ��ȣ");
			break;
		case 4:
			return;
		}
	}
}

bool Login::LoginDisplay()
{

	string TmpId, TmpPassword;
	int Select;
	bool Id_Flag, PasswordFlag, LoginFlag;
	while (1)
	{
		LoginFlag = false;
		system("cls");
		cout << "=====Login=====(ȸ����[" << m_iIdCount << "��])" << endl;
		cout << "   1.ȸ�� ����" << endl;
		cout << "   2.�α���" << endl;
		cout << "   3.����" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (m_iIdCount >= IDMAX)
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�." << endl;
				system("pause");
				break;
			}
			Join();
			break;
		case 2:
			while (!LoginFlag)
			{
				Id_Flag = false;
				PasswordFlag = false;
				system("cls");
				cout << "���̵� �Է� : ";
				cin >> TmpId;
				cout << "��й�ȣ �Է� : ";
				cin >> TmpPassword;
				for (int i = 0; i < m_iIdCount; i++)
				{
					if (TmpId == m_Id_List[i].m_strID)
					{
						Id_Flag = true;
						if (TmpPassword == m_Id_List[i].m_strPassword)
						{
							PasswordFlag = true;
							LoginFlag = true;
							m_iCurIdIndex = i;
							return true;
						}
					}
				}
				if (!Id_Flag)
					cout << "�ش� ���̵� �����ϴ�." << endl;
				else if (!PasswordFlag)
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			}
			break;
		case 3:
			return false;
		}
	}
}
void Login::Join()
{
	bool Flag, Flag2, Flag3;
	int CountNum = 0;
	string CheckPassword;
	while (1)
	{
		Flag = true;
		Flag3 = true;
		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]) : ";
		cin >> m_Id_List[m_iIdCount].m_strID;
		for (int i = 0; i < m_Id_List[m_iIdCount].m_strID.length(); i++)
		{
			if (m_Id_List[m_iIdCount].m_strID[i] <'A' || (m_Id_List[m_iIdCount].m_strID[i] > 'Z' && m_Id_List[m_iIdCount].m_strID[i] < 'a') || m_Id_List[m_iIdCount].m_strID[i] > 'z')
			{
				if (m_Id_List[m_iIdCount].m_strID[i] >= '0' &&m_Id_List[m_iIdCount].m_strID[i] <= '9')
					Flag = true;
				else
					Flag = false;
			}
		}
		for (int i = 0; i < m_iIdCount; i++)
		{
			if (i != m_iIdCount && m_Id_List[i].m_strID == m_Id_List[m_iIdCount].m_strID)
				Flag3 = false;
		}
		if (!Flag3)
		{
			cout << "������ ���̵� �����մϴ�." << endl;
			system("pause");
			continue;
		}
		if (Flag && m_Id_List[m_iIdCount].m_strID.length() >= IDLEN)
			break;
		if (!Flag)
			cout << "id�� ������ �ƴմϴ�." << endl;
		if (m_Id_List[m_iIdCount].m_strID.length() < IDLEN)
			cout << "id�� ������ ���� �Դϴ�." << endl;
		system("pause");
	}
	while (1)
	{
		Flag = true;
		Flag2 = true;
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
		cin >> m_Id_List[m_iIdCount].m_strPassword;
		for (int i = 0; i < m_Id_List[m_iIdCount].m_strPassword.length(); i++)
		{
			if (m_Id_List[m_iIdCount].m_strPassword[i] <'A' || (m_Id_List[m_iIdCount].m_strPassword[i] > 'Z' && m_Id_List[m_iIdCount].m_strPassword[i] < 'a') || m_Id_List[m_iIdCount].m_strPassword[i] > 'z')
			{
				if (m_Id_List[m_iIdCount].m_strPassword[i] >= '0' && m_Id_List[m_iIdCount].m_strPassword[i] <= '9')
					CountNum++;
				else
					Flag = false;
			}
		}
		cout << "��й�ȣ Ȯ�� : ";
		cin >> CheckPassword;
		if (CheckPassword != m_Id_List[m_iIdCount].m_strPassword)
			Flag2 = false;
		if (Flag && Flag2 && m_Id_List[m_iIdCount].m_strPassword.length() >= PASSWORDLEN && CountNum >= 1)
			break;
		if (!Flag)
			cout << "password�� ������ �ƴմϴ�." << endl;
		if (m_Id_List[m_iIdCount].m_strPassword.length() < PASSWORDLEN)
			cout << "Password�� �������� ���� �Դϴ�." << endl;
		if (CountNum == 0)
			cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
		if (!Flag2)
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("pause");
	}
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> m_Id_List[m_iIdCount].m_strName;
	cout << "���� �Է� :";
	cin >> m_Id_List[m_iIdCount].m_iAge;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> m_Id_List[m_iIdCount].m_strPhonNumber;
	cout << "ȸ������ ���� !! ���ϸ��� 1000�� ���" << endl;
	m_Id_List[m_iIdCount].m_iMileage = 1000;
	m_iIdCount++;
	system("pause");
}

Login::~Login()
{

}
