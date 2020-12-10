#include "Store.h"



Store::Store()
{
	BowCount = 0;
	DaggerCount = 0;
	Guncount = 0;
	SwordCount = 0;
	WandCount = 0;
	HammerCount = 0;
	SetWeaponData();

	m_iWidth = 30;
	m_iHeight = 30;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", m_iHeight + 1, m_iWidth * 2);
	system(buf);
	add = NULL;
	tmp = NULL;
}

void Store::StoreShow(Player *player)
{
	//Map.BoxErase();
	do
	{
		Map.BoxErase(m_iWidth, m_iHeight);
		Map.DrawMidText(" ◆ ◇ S H O P  ◇ ◆", m_iWidth, 8);
		Map.DrawMidText("Dagger", m_iWidth, 10);
		Map.DrawMidText("Gum", m_iWidth, 12);
		Map.DrawMidText("Sword", m_iWidth, 14);
		Map.DrawMidText("Wand", m_iWidth, 16);
		Map.DrawMidText("Bow", m_iWidth, 18);
		Map.DrawMidText("Hammer", m_iWidth, 20);
		Map.DrawMidText("돌아가기", m_iWidth, 22);
		m_iSelelct = Map.MenuSelectCursor(7, 2, 5, 10);
		switch (m_iSelelct)
		{
		case 1:
			WeaponShow("Dagger", player);
			break;
		case 2:
			WeaponShow("Gun", player);
			break;
		case 3:
			WeaponShow("Sword", player);
			break;
		case 4:
			WeaponShow("Wand", player);
			break;
		case 5:
			WeaponShow("Bow", player);
			break;
		case 6:
			WeaponShow("Hammer", player);
			break;
		}
	} while (m_iSelelct != 7);
}
void Store::WeaponShow(string Class, Player *player)
{
	string str;
	int Page = 0;
	int textLine = 6;
	int WeaponNumber = 1;
	int Weapon_Show_Count = 0;
	int EndCount;
	//BowCount, DaggerCount, Guncount, SwordCount, WandCount, HammerCount;
	if (Class == "Bow")
		EndCount = BowCount;
	else if (Class == "Dagger")
		EndCount = DaggerCount;
	else if (Class == "Gun")
		EndCount = Guncount;
	else if (Class == "Sword")
		EndCount = SwordCount;
	else if (Class == "Wand")
		EndCount = WandCount;
	else if (Class == "Hammer")
		EndCount = HammerCount;
	do
	{
		Map.BoxErase(m_iWidth, m_iHeight);

		textLine = 3;
		//Map.BoxErase();
		str = "GOLD : " + to_string(player->ReturnGold());
		YELLOW
		Map.DrawMidText(str, m_iWidth, textLine++);
		ORIGINAL
		//보우골드 출력
		str = Class + "Shop";
		Map.DrawMidText(str, m_iWidth, textLine);
		textLine += 2;
		tmp = weapon;
		Weapon_Show_Count = 0;
		while(tmp->Next != NULL)
		{
			if (tmp->Class == Class && WeaponNumber == tmp->Number)
			{
				str = "가격 : " + to_string(tmp->weapon->ReturnPrice())
					+ " 무기타입 : " + tmp->Class;
				HIGH_GREEN
				Map.DrawMidText(str, m_iWidth, textLine);
				str = "무기이름 : " + tmp->weapon->ReturnName()
					+ " 공격력 : " + to_string(tmp->weapon->ReturnStr());
				Map.DrawMidText(str, m_iWidth, textLine+1);
				ORIGINAL
				textLine += 3;
				WeaponNumber++;
				Weapon_Show_Count++;
				if (WeaponNumber % 5 == 0)
					break;
				tmp = tmp->Next;
				continue;
			}
			tmp = tmp->Next;
			
		}
		str = "이전페이지";
		Map.DrawMidText(str, m_iWidth, textLine);
		textLine += 3;

		str = "다음페이지";
		Map.DrawMidText(str, m_iWidth, textLine);
		textLine += 3;

		str = "나가기";
		Map.DrawMidText(str, m_iWidth, textLine);
		m_iSelelct = Map.MenuSelectCursor(Weapon_Show_Count+3, 3, 3, 6);
		
		if (m_iSelelct == 1 || (m_iSelelct == 2 && Weapon_Show_Count % 4 != 1)
			|| (m_iSelelct == 3 && (Weapon_Show_Count >= 3 || Weapon_Show_Count == 0)) || (m_iSelelct == 4 && Weapon_Show_Count % 4 == 0))
		{
			WeaponNumber -= Weapon_Show_Count;
			add = weapon;
			while (add->Next != NULL)
			{
				if (add->Class == Class && m_iSelelct + (Page * 4) == add->Number && player->ReturnGold() >= add->weapon->ReturnPrice())
				{
					player->Buy_Weapon(*add->weapon , add->weapon->ReturnClass());
					break;
				}
				add = add->Next;
			}
		}
		else if (m_iSelelct == Weapon_Show_Count + 1)//이전페이지
		{
			Page--;
			WeaponNumber -= Weapon_Show_Count + 4;
			if (WeaponNumber <= 1)
				WeaponNumber = 1;

		}
		else if (m_iSelelct == Weapon_Show_Count + 2 && WeaponNumber == EndCount + 1)//다음페이지 마지막페이지
		{
			WeaponNumber -= Weapon_Show_Count;
		}
		else if (m_iSelelct == Weapon_Show_Count + 2)//다음페이지
			Page++;

	} while (m_iSelelct != Weapon_Show_Count+3);
	m_iSelelct = 0;
}

void Store::SetWeaponData()
{
	ifstream load;
	string name;
	int str, price;
	load.open("WeaponList.txt");
	weapon = NULL;

	while (!load.eof())
	{
		
		add = new WeaponData;
		load >> add->Class;
		load >> name >> str >> price;
		if (add->Class == "Bow")
		{
			add->weapon = new Bow;
			BowCount++;
			add->Number = BowCount;
		}
		else if (add->Class == "Dagger")
		{
			add->weapon = new Dagger;
			DaggerCount++;
			add->Number = DaggerCount;
		}
		else if (add->Class == "Gun")
		{
			add->weapon = new Gun;
			Guncount++;
			add->Number = Guncount;
		}
		else if (add->Class == "Sword")
		{
			add->weapon = new Sword;
			SwordCount++;
			add->Number = SwordCount;
		}
		else if (add->Class == "Wand")
		{
			add->weapon = new Wand;
			WandCount++;
			add->Number = WandCount;
		}
		else if (add->Class == "Hammer")
		{
			add->weapon = new Hammer;
			HammerCount++;
			add->Number = HammerCount;
		}
		add->weapon->Setdata(name, str, price, add->Class);
		add->Next = NULL;
		if (weapon == NULL)
			weapon = add;
		else
		{
			tmp = weapon;
			while (tmp->Next != NULL)
			{
				tmp = tmp->Next;
			}
			tmp->Next = add;

		}

	}
	
}

void Store::Weapon_Release(WeaponData* Node)
{
	{
		if (Node == NULL)
			return;
		Weapon_Release(Node->Next);
		delete Node->weapon;
		delete Node;
	}
}
Store::~Store()
{
	Weapon_Release(weapon);
}
