#include "Weapon.h"
#include"Character.h"



Weapon::Weapon()
{

}


void Weapon::Save(ofstream& Save)
{
	switch (m_eType)
	{
	case WEAPON_DAGGER:
		Save << "��� ";
		break;
	case WEAPON_GUN:
		Save << "�� ";
		break;
	case WEAPON_SWORD:
		Save << "��� ";
		break;
	case WEAPON_WAND:
		Save << "������ ";
		break;
	case WEAPON_BOW:
		Save << "Ȱ ";
		break;
	case WEAPON_HAMMER:
		Save << "��ġ ";
		break;
	}
	Save << m_strName << " " << m_iDamage << " " << m_iGold;
}
void Weapon::ShowShopInfo(int x, int y)
{
	string Type;
	switch (m_eType)
	{
	case WEAPON_DAGGER:
		Type = "���";
		break;
	case WEAPON_GUN:
		Type = "��";
		break;
	case WEAPON_SWORD:
		Type = "���";
		break;
	case WEAPON_WAND:
		Type = "������";
		break;
	case WEAPON_BOW:
		Type = "Ȱ";
		break;
	case WEAPON_HAMMER:
		Type = "��ġ";
		break;
	}
	YELLOW
	m_DrawManager.DrawMidText("���� : " + to_string(m_iGold) +  " ����Ÿ�� : " + Type, x, y);
	m_DrawManager.DrawMidText(" �����̸� : " + m_strName + " ���ݷ� : " + to_string(m_iDamage), x, y + 1);
	ORIGINAL
}
void Weapon::ShowInfo(int x, int y)
{
	string Type;
	switch (m_eType)
	{
	case WEAPON_DAGGER:
		Type = "���";
		break;
	case WEAPON_GUN:
		Type = "��";
		break;
	case WEAPON_SWORD:
		Type = "���";
		break;
	case WEAPON_WAND:
		Type = "������";
		break;
	case WEAPON_BOW:
		Type = "Ȱ";
		break;
	case WEAPON_HAMMER:
		Type = "��ġ";
		break;
	}
	YELLOW
	m_DrawManager.DrawMidText("����Ÿ�� : " + Type + " �����̸� : " + m_strName + " ���ݷ� : " + to_string(m_iDamage),x,y);
	ORIGINAL
}

Weapon::~Weapon()
{

}

void Bow::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 10)
	{
		m_DrawManager.DrawMidText("��弦!!(Damage : " + to_string(Damage*10) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 10);
	}
	else
		LoseCharacter->Hit(Damage);
}
Bow::Bow()
{

}
Bow::Bow(Bow* bow)
{
	m_strName = bow->m_strName;
	m_iDamage = bow->m_iDamage;
	m_iGold = bow->m_iGold;
	m_eType = bow->m_eType;
}

Bow::Bow(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_BOW;
}
Bow::~Bow()
{

}


void Dagger::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 20)
	{
		m_DrawManager.DrawMidText("ũ��Ƽ�ü�!!(Damage : " + to_string(Damage * 5) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 5);
		getch();
		m_DrawManager.DrawMidText("ũ��Ƽ�ü�!!(Damage : " + to_string(Damage * 5) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 5);
	}
	else
		LoseCharacter->Hit(Damage);
}
Dagger::Dagger()
{

}
Dagger::Dagger(Dagger* dagger)
{
	m_strName = dagger->m_strName;
	m_iDamage = dagger->m_iDamage;
	m_iGold = dagger->m_iGold;
	m_eType = dagger->m_eType;
}

void Save(ofstream& Save)
{

}
Dagger::Dagger(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_DAGGER;
}
Dagger::~Dagger()
{

}

void Gun::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 50)
	{
		m_DrawManager.DrawMidText("��弦!!(Damage : " + to_string(Damage * 2) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 2);
	}
	else
		LoseCharacter->Hit(Damage);
}
Gun::Gun()
{

}
Gun::Gun(Gun* gun)
{
	m_strName = gun->m_strName;
	m_iDamage = gun->m_iDamage;
	m_iGold = gun->m_iGold;
	m_eType = gun->m_eType;
}
Gun::Gun(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_GUN;
}
Gun::~Gun()
{

}

void Sword::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 30)
	{
		m_DrawManager.DrawMidText("�˱�!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
		getch();
		m_DrawManager.DrawMidText("�˱�!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
		getch();
		m_DrawManager.DrawMidText("�˱�!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
	}
	else
		LoseCharacter->Hit(Damage);
}
Sword::Sword()
{

}
Sword::Sword(Sword* sword)
{
	m_strName = sword->m_strName;
	m_iDamage = sword->m_iDamage;
	m_iGold = sword->m_iGold;
	m_eType = sword->m_eType;
}

Sword::Sword(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_SWORD;
}

Sword::~Sword()
{

}

void Wand::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 5)
	{
		m_DrawManager.DrawMidText("���!!(Damage : " + to_string(Damage * 1000) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 1000);
	}
	else
		LoseCharacter->Hit(Damage);
}

Wand::Wand()
{

}

Wand::Wand(Wand* wand)
{
	m_strName = wand->m_strName;
	m_iDamage = wand->m_iDamage;
	m_iGold = wand->m_iGold;
	m_eType = wand->m_eType;
}

Wand::Wand(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_WAND;
}

Wand::~Wand()
{

}

void Hammer::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_DrawManager.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 50)
	{
		m_DrawManager.DrawMidText("������!!(Damage : " + to_string(Damage * 1.2f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.2f));
	}
	else
		LoseCharacter->Hit(Damage);
}

Hammer::Hammer()
{

}

Hammer::Hammer(Hammer* hammer)
{
	m_strName = hammer->m_strName;
	m_iDamage = hammer->m_iDamage;
	m_iGold = hammer->m_iGold;
	m_eType = hammer->m_eType;
}

Hammer::Hammer(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WEAPON_WAND;
}

Hammer::~Hammer()
{

}