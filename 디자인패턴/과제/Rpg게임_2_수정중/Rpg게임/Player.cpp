#include "Player.h"
//&inventory->Return_Weapon();


Player::Player()
{
	m_iWidth = 30;
	m_iHeight = 30;
	//m_pWeapon = NULL;
	inventory = new Bag;
	Inventory* item1 = new Item;
	inventory->AddInventory(item1);

}
void Player::SetName()
{
	Map.BoxErase(m_iWidth, m_iHeight);
	Map.DrawMidText("Player 이름 입력 :   ", m_iWidth, 15);
	cin >> m_strName;
}
//string m_strName;//이름
//int m_iLevel;//레벨
//int m_iStr;//공격력
//int m_iNhp;//현재채력
//int m_iMaxhp;//최대채력
//int m_iNExp;//현재경험치
//int m_iMaxExp;//최대 경험치
//int m_iGiveExp;//주는경험치
//int m_iGold;//골드
void Player::LoadDefaultInfo()
{
	ifstream load;
	load.open("DefaultPlayer.txt");
	load >> m_iStr;
	load >> m_iMaxhp;
	m_iNhp = m_iMaxhp;
	load >> m_iMaxExp;
	m_iNExp = 0;
	load >> m_iGiveExp;
	load >> m_iLevel;
	load >> m_iGold;
	load.close();
}
void Player::LoadNewInfo(int FileNumber)
{
	string Weapon_Class, Weapon_Name;
	int Weapon_Str;
	string file;
	ifstream load;
	file = "SavePlayer" + to_string(FileNumber) + ".txt";
	load.open(file);
	load >> m_strName;
	load >> m_iLevel;
	load >> m_iStr;
	load >> m_iNhp;
	load >> m_iMaxhp;
	load >> m_iMaxExp;
	load >> m_iNExp;
	m_iGiveExp = m_iNExp;

	load >> m_iGold;
	if (!load.eof() == true)
	{
		
		load >> Weapon_Class;
		Get_Weapon(Weapon_Class);
		load >> Weapon_Name;
		load >> Weapon_Str;
		inventory->Return_Weapon()->Setdata(Weapon_Name, Weapon_Str, Weapon_Class);
	}
	else
	{
	}
	load.close();

}
void Player::ShowInfo(int TextLine)
{
	string str;
	YELLOW
	Map.BoxErase(m_iWidth, m_iHeight);
	str = "======" + m_strName + "(" + to_string(m_iLevel) + "Lv)======";
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "공격력 = " + to_string(m_iStr) + "	  생명력 = " + to_string(m_iNhp) + "/" + to_string(m_iMaxhp);
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "경험치 = " + to_string(m_iNExp) + "/" + to_string(m_iMaxExp) + "	  GiveExp = " + to_string(m_iGiveExp);
	Map.DrawMidText(str, m_iWidth, TextLine++);
	str = "Gold = " + to_string(m_iGold) + "               ";
	Map.DrawMidText(str, m_iWidth, TextLine++);
	if (inventory->Return_Weapon() != NULL)
	{
		str = "무기타입 : " + inventory->Return_Weapon()->ReturnClass() +" 무기이름 : "
			+ inventory->Return_Weapon()->ReturnName() + " 공격력 : " + to_string(inventory->Return_Weapon()->ReturnStr());
		Map.DrawMidText(str, m_iWidth, TextLine++);
	}
	ORIGINAL
}


int Player::GetRCP()
{
	
	char RCP;
	YELLOW
	Map.DrawMidText("가위 : 1   바위 : 2    보 : 3",m_iWidth, 10);
	while (1)
	{
		RCP = getch();
		switch(RCP)
		{
		case '1':
			Map.DrawMidText("가위", m_iWidth, 12);
			return RCP_SCISSOR;
			break;
		case '2':
			Map.DrawMidText("바위", m_iWidth, 12);
			return RCP_ROCK;
			break;
		case '3':
			Map.DrawMidText("보", m_iWidth, 12);
			return RCP_PAPER;
			break;
			
		}
	}
	ORIGINAL
}
void Player::SaveData(int FileNumber)
{
	ofstream save;
	string file;
	file = "SavePlayer" + to_string(FileNumber) + ".txt";
	save.open(file);
	save << m_strName << " ";
	save << m_iLevel << " ";
	save << m_iStr << " ";
	save << m_iNhp << " ";
	save << m_iMaxhp << " ";
	save << m_iMaxExp << " ";
	save << m_iNExp << " ";
	save << m_iGold;
	if (inventory->Return_Weapon() != NULL)
	{
		save << endl << inventory->Return_Weapon()->ReturnClass() << " " << inventory->Return_Weapon()->ReturnName() << " " << inventory->Return_Weapon()->ReturnStr();
	}
	save.close();
}



int Player::ChangeHP(int Monster_Srt)
{
	m_iNhp -= Monster_Srt;
	if (m_iNhp <= 0)
		return DIE;
	else
		return LIVE;
}

void Player::ChangeEXP(int exp)
{
	if (exp == 0)
		m_iNExp = 0;
	m_iNExp += exp;
	string srt;
	if (m_iMaxExp <= m_iNExp)
	{
		m_iStr += 3;
		m_iMaxhp += 7;
		m_iNhp = m_iMaxhp;
		m_iMaxExp += 5;
		m_iNExp = 0;
		m_iLevel++;
		Map.gotoxy(3, 20);
		system("pause");
		Map.BoxErase(m_iWidth, m_iHeight);

		srt = m_strName + "레벨업!!";
		Map.DrawMidText(srt, m_iWidth, 12);

		srt = m_strName + "공격력 3증가!!";
		Map.DrawMidText(srt, m_iWidth, 15);

		srt = m_strName + "생명력 7증가!!";
		Map.DrawMidText(srt, m_iWidth, 18);
		Map.gotoxy(3, 20);
		system("pause");
	}
}
void Player::ChangeGOLD(int Gold)
{
	m_iGold += Gold;
}

void Player::Get_Weapon(string Weapon_Class)
{
	if (Weapon_Class == "Bow")
	{
		*inventory->Return_Weapon() = new Bow;
	}
	else if (Weapon_Class == "Dagger")
	{
		*inventory->Return_Weapon() = new Dagger;
	}
	else if (Weapon_Class == "Gun")
	{
		*inventory->Return_Weapon() = new Gun;
	}
	else if (Weapon_Class == "Hammer")
	{
		*inventory->Return_Weapon() = new Hammer;
	}
	else if (Weapon_Class == "Sword")
	{
		*inventory->Return_Weapon() = new Sword;
	}
	else if (Weapon_Class == "Wand")
	{
		*inventory->Return_Weapon() = new Wand;
	}
}


int Player::Weapon_Skill()
{
	if (inventory->Return_Weapon() == NULL)
		return 0;
	else
		return inventory->Return_Weapon()->Use_Skill_Check(m_iStr);

}

void Player::Buy_Weapon(Weapon &wp, string Class)
{
	m_iGold -= wp.ReturnPrice();
	if (inventory->Return_Weapon() != NULL)
		delete inventory->Return_Weapon();
	if (Class == "Bow")
		*inventory->Return_Weapon() = new Bow(&wp);
	else if (Class == "Dagger")
		*inventory->Return_Weapon() = new Dagger(&wp);
	else if (Class == "Gun")
		*inventory->Return_Weapon() = new Gun(&wp);
	else if (Class == "Hammer")
		*inventory->Return_Weapon() = new Hammer(&wp);
	else if (Class == "Sword")
		*inventory->Return_Weapon() = new Sword(&wp);
	else if (Class == "Wand")
		*inventory->Return_Weapon() = new Wand(&wp);
}


Player::~Player()
{
	if (inventory->Return_Weapon() != NULL)
		delete inventory->Return_Weapon();


}
