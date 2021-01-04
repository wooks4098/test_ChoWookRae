#pragma once
#include <iostream>
#include <string>
#include <regex>
//#include "Computer.h"
#define MAX 10
using namespace std;
enum LOGIN
{
	LOGIN_CREAT_ID = 1,
	LOGIN_LOGIN_TRY,
	LOGIN_OFF
};
typedef struct people
{
	string id;
	string password;
	string nickname;
	int age;
	int phonenumber;
	int mileage;
}People;

class Login
{
private:

	int select = 0;
	int login_select;
protected:
	People member[MAX];
	int login_number;
	int member_count = 0;
public:

	int Start();
	void Change_memberinfo(People P[], int login_number);
	void Member_info(People P[], int login_number);
	void LoginMenu();
	int Login_try(People P[], int member_count);
	void CreateID(People P[], int* member_count);
	bool StreamCheck(char start, char end, char check);
	void MainMenu(int member_count);

	Login();
	~Login();
};

