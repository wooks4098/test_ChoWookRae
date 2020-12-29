#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�˶� ����� �ۼ��ϰ� �˶��� ������ Ŭ����
class Observer
{
public:
	virtual void Notify(string name) = 0;
};

//���� �˶� ���� Ŭ����
class BossAlarm
{
	//Observer
	vector<Observer*> players;
	string name;

public:
	BossAlarm(string name) : name(name) { }

	//������ ������ ���
	void AddPlayer(Observer* player)
	{
		players.push_back(player);
	}

	//���ð� ���� ������ ����
	void RemovePlayer(Observer* player)
	{
		vector<Observer*>::iterator seek = find(players.begin(), players.end(), player);
		players.erase(seek);
	}

	//��Ƽ�� ���̼� ���
	void Notification()
	{
		vector<Observer*>::iterator seek = players.begin();
		vector<Observer*>::iterator end = players.end();

		while (seek != end)
		{
			(*seek)->Notify(name);
			seek++;
		}
	}

	void Notification(Observer* player)
	{
		if (isAppear)
		{
			player->Notify(name);
		}
	}

protected:
	bool isAppear;
};

//�巡�� ���� Ŭ����
class BossDragon : public BossAlarm
{
public:
	BossDragon() : BossAlarm("�巡��")
	{
		isAppear = false;
	}

	//���� ��ȭ�� �˷��� �Լ�
	void SpawnBoss()
	{
		isAppear = true;
		Notification();
	}
};

//Ʈ�� ��� ��ũ ���� Ŭ����
class BossTwinHeadOrc : public BossAlarm
{
public:
	BossTwinHeadOrc() : BossAlarm("Ʈ�� ��� ��ũ")
	{
		isAppear = false;
	}

	//���� ��ȭ�� �˷��� �Լ�
	void SpawnBoss()
	{
		isAppear = true;
		Notification();
	}
};

class Player : public Observer
{
	string name;
	BossAlarm* bossAlarm;
	bool alarmState;

public:
	Player(string name) : name(name) { }

	//��ϵ� ��Ƽ�� ���̼� ȣ��
	void Notify(string name) override
	{
		if (alarmState)
		{
			cout << "# " << this->name.c_str() << "���� �˸� #" << endl;
			cout << name.c_str() << " ���� ����!" << endl << endl;
		}
		else
		{
			cout << "# " << this->name.c_str() << " �˶� ���� ���� #" << endl << endl;
		}
	}

	//���� �˶� ����
	void SetBossAlarm(BossAlarm* alarm, bool alarmOn = true)
	{
		bossAlarm = alarm;
		alarmState = alarmOn;

		bossAlarm->AddPlayer(this);
	}

	//���� �˶� ȣ��
	void GetBossState()
	{
		cout << "# " << name.c_str() << " ���� �˸� ��û #" << endl;
		alarmState = true;
		bossAlarm->Notification(this);
	}
};
