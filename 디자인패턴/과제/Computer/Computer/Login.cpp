#include "Login.h"



Login::Login()
{
}




void Login::MainMenu(int member_count)
{
	system("cls");
	cout << "=====Login=====(회원수[" << member_count << "명])" << endl;
	cout << "   1.회원 가입" << endl;
	cout << "   2.로그인" << endl;
	cout << "   3.종료" << endl;
	cout << "입력:";
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
	//id 추가
	do
	{
		check = true;

		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]):";
		cin >> P[*member_count].id;
		if (*member_count != 0)
		{
			for (int i = 0; i < *member_count; i++)
			{
				if (P[i].id == P[*member_count].id)
				{
					cout << "중복되는 아이디가 있습니다." << endl;
					check = false;
				}
			}
		}
		if (P[*member_count].id.length() <= 2)
		{
			cout << "아이디가 세글자 이하 입니다." << endl;
			check = false;
		}
		for (int i = 0; i < P[*member_count].id.length(); i++)
		{
			if (StreamCheck('a', 'z', P[*member_count].id[i]) == false &&
				StreamCheck('A', 'Z', P[*member_count].id[i]) == false &&
				StreamCheck('0', '1', P[*member_count].id[i]) == false)
			{
				cout << "아이디가 영문 또는 숫자가 아닙니다." << endl;
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
	//pw 추가
	do
	{
		check = true;
		pw_number = false;
		pw_string = true;
		system("cls");
		cout << "비밀번호 입력([8글자↑] AND[영문]AND[숫자포함]}):";
		cin >> P[*member_count].password;
		cout << "비밀번호 확인 : ";
		cin >> pwcheck;
		if (pwcheck != P[*member_count].password)
		{
			cout << "비밀번호가 일치하지 않습니다" << endl;
			check = false;
		}
		if (P[*member_count].password.length() <= 7)
		{
			cout << "비밀번호가 8글자 이하 입니다." << endl;
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
			cout << "비밀번호에 영문 또는 숫자 외에 다른 문자가 포함되어 있습니다." << endl;
		if (pw_number == false)
		{
			cout << "비밀번호에 숫자가 포함되어있지않습니다." << endl;
			check = false;
		}
		if (check == true)
		{
			break;
		}
		system("pause");
	} while (1);
	//닉네임추가
	cout << "닉네임 입력 :";
	cin >> P[*member_count].nickname;
	//나이추가
	cout << "나이 입력 :";
	cin >> P[*member_count].age;
	//휴대폰번호 추가
	cout << "휴대번호 입력 :";
	cin >> P[*member_count].phonenumber;
	//마일리지 지급
	cout << "회원가입 성공 !! 1000마일리지 지급" << endl;
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
		cout << "아이디를 입력해주세요 : ";
		cin >> ID;
		cout << "비밀번호를 입력해주세요 : ";
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
			cout << "없는 아이디입니다" << endl;
		if (IDcheck == true)
		{
			if (PW == P[member_number].password)
			{
				check = true;
			}
			else
				cout << "잘못된 비밀번호입니다" << endl;
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
	cout << "   1.회원 정보" << endl;
	cout << "   2.회원 정보 변경" << endl;
	cout << "   3.로그아웃" << endl;
	cout << "입력:";
}

void Login::Member_info(People P[], int login_number)
{
	system("cls");
	cout << "===========회원정보===========" << endl;
	cout << "ID : " << P[login_number].id << "	닉네임 :	" << P[login_number].nickname << endl;
	cout << "나이 : " << P[login_number].age << "	휴대폰 번호 :	" << P[login_number].phonenumber << endl;
	cout << "마일리지 : " << P[login_number].mileage << endl;
	system("pause");
}

void Login::Change_memberinfo(People P[], int login_number)
{
	int select;
	do
	{
		Member_info(P, login_number);
		cout << "======================" << endl;
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력:";
		cin >> select;

		switch (select)
		{
		case 1:
			cout << endl << "현재 닉네임: " << P[login_number].nickname << endl;
			cout << "변경할 닉네임입력 : ";
			cin >> P[login_number].nickname;
			break;
		case 2:
			cout << endl << "현재 나이: " << P[login_number].age << endl;
			cout << "변경할 나이 입력 : ";
			cin >> P[login_number].age;
			break;
		case 3:
			cout << endl << "현재 휴대폰 번호: " << P[login_number].phonenumber << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
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
			cout << "회원수가 10명이므로 회원가입이 불가합니다" << endl;
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
