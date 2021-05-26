#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	m_Player[ONE].Icon = "○";
	m_Player[TWO].Icon = "●";
	m_icount = 1;
  	m_Player[ONE].Mooring = 5;
	m_Player[TWO].Mooring = 5;
}
void PlayerManager::StoneSetting(ICONTYPE Icon)
{
	switch (Icon)
	{
	case ICON_NOMAL:
		m_Player[TWO].Icon = "●";
		m_Player[ONE].Icon = "○";
		break;
	case ICON_HEART:	
		m_Player[TWO].Icon = "♥";
		m_Player[ONE].Icon = "♡";
		break;
	case ICON_FINGER:
		m_Player[TWO].Icon = "☞";
		m_Player[ONE].Icon = "☜";
		break;
	case ICON_NUMCIR:
		m_Player[ONE].Icon = "①";
		m_Player[TWO].Icon = "②";
		break;
	}
}
void PlayerManager::SetName(string name1, string name2)
{
	m_Player[ONE].name = name1;
	m_Player[TWO].name = name2;
}

int PlayerManager::StoneCheck(int x, int y)
{
	for (int i = 0; i < m_Player_XY_Vector.size(); i += 2)
	{
		if (m_Player_XY_Vector[i].x == x && m_Player_XY_Vector[i].y == y)
		{
			return DRAWONE;
		}
	}
	for (int i = 1; i < m_Player_XY_Vector.size(); i += 2)
	{
		if (m_Player_XY_Vector[i].x == x && m_Player_XY_Vector[i].y == y)
		{
			return DRAWTWO;
		}
	}
	return 0;
}
void PlayerManager::StoneAllReDraw()
{
	for (int i = 0; i < m_Player_XY_Vector.size(); i += 2)
	{
		Tool.TextDraw(m_Player[ONE].Icon, m_Player_XY_Vector[i].x, m_Player_XY_Vector[i].y);
	}
	for (int i = 1; i < m_Player_XY_Vector.size(); i += 2)
	{
		Tool.TextDraw(m_Player[TWO].Icon, m_Player_XY_Vector[i].x, m_Player_XY_Vector[i].y);
	}
}
int PlayerManager::SaveFileCheck()
{
	int x, y;
	m_Load.open("Save_XY.txt");/////////////////////////////////////////////////////////
	m_Load >> x;
	m_Load >> y;
	if (x < 0 || y < 0)
	{
		m_Load.close();
		return 0;
	}
	else
		m_Load.close();
	return 1;
}
int PlayerManager::WinnerHistoryFileCheck()
{
	string icon;
	int x, y;
	m_Load.open("WinnerHistory.txt");/////////////////////////////////////////////
	m_Load >> icon;
	m_Load >> icon;
	m_Load >> x;
	m_Load >> y;
	if (x < 0 || y < 0)
	{
		m_Load.close();
		return 0;
	}
	else
		m_Load.close();
	return 1;
}
void PlayerManager::WinHistoryLoad()
{
	int Turn = 1;
	int x, y;
	string icon[2];
	int Player = ONE;
	m_Load.open("WinnerHistory.txt");
	m_Load >> icon[ONE];
	m_Load >> icon[TWO];
	while (m_Load.is_open() && !(m_Load.eof()))
	{
		for (int i = ONE; i <= TWO; !(m_Load.eof()))
		{
			m_Load >> x;
			m_Load >> y;
			if (x < 0 || y < 0 && !(m_Load.eof()))
			{
				m_Load.close();
				return;
			}
			Sleep(200);
			Tool.TextDraw(icon[i], x, y);
			m_Map.PointMoveOut();/////////////////////////////////////////////////////
			cout << to_string(Turn) + "턴";
			i++;
			++Turn;
		}
	};
}
void PlayerManager::StoneAllLoad()//다시 저장을 해야겠지? 벡터의 0번째 부터?
{
	int Turn = 1;
	int x, y;
	int Player = ONE;
	m_Load.open("Save_XY.txt");
	while (m_Load.is_open() && !(m_Load.eof()))
	{
		m_Load >> x;
		m_Load >> y;
		if (x < 0 || y < 0)
			break;
		SaveStone(x, y, Player);
		Player++;
		if (Player == 2)
			Player = ONE;
	}
	m_Load.close();
}
void PlayerManager::StoneLinkCheck(int i, int x, int y, int x_, int y_)
{
	bool escape = true;
	for (int j = i; j < m_Player_XY_Vector.size(); j += 2)
	{
		if (x == m_Player_XY_Vector[j].x && y == m_Player_XY_Vector[j].y)
		{
			escape = false;
			m_icount++;
		}
	}
	if (escape)
		return;
	StoneLinkCheck(i, x + x_, y + y_, x_, y_);
}

int PlayerManager::WinCheck(int i)
{
	m_icount = 1;
	if (m_Player_XY_Vector.size() < 9)
		return 0;
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + WEST, m_Player_XY_Vector.back().y + 0, WEST, 0);
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + EAST, m_Player_XY_Vector.back().y + 0, EAST, 0);
	if (m_icount == 5)
		return 1;
	else
		m_icount = 1;
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + 0, m_Player_XY_Vector.back().y + NORTH, 0, NORTH);
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + 0, m_Player_XY_Vector.back().y + SOUTH, 0, SOUTH);
	if (m_icount == 5)
		return 1;
	else
		m_icount = 1;
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + WEST, m_Player_XY_Vector.back().y + SOUTH, WEST, SOUTH);
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + EAST, m_Player_XY_Vector.back().y + NORTH, EAST, NORTH);
	if (m_icount == 5)
		return 1;
	else
		m_icount = 1;
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + EAST, m_Player_XY_Vector.back().y + SOUTH, EAST, SOUTH);
	StoneLinkCheck(i, m_Player_XY_Vector.back().x + WEST, m_Player_XY_Vector.back().y + NORTH, WEST, NORTH);
	if (m_icount == 5)
		return 1;
	else
		return 0;
}
void PlayerManager::SaveMooring()
{
	m_save.open("Save.txt", ios::app);
	for (int i = ONE; i <= TWO; i++)
	{
		m_save << m_Player[i].Mooring << " ";
	}
	m_save.close();
}
void PlayerManager::SavePlayerName()
{
	m_save.open("Save.txt", ios::app);
	for (int i = ONE; i <= TWO; i++)
	{
		m_save << m_Player[i].name << " ";
	}
	m_save.close();
}
void PlayerManager::SaveIcon()
{
	m_save.open("Save.txt",ios::app);
	m_save << m_Player[ONE].Icon << " ";
	m_save << m_Player[TWO].Icon << " ";
	m_save.close();
}
void PlayerManager::SaveIcon(bool Replay)
{
	m_save.open("WinnerHistory.txt");
	m_save << m_Player[ONE].Icon << " ";
	m_save << m_Player[TWO].Icon << " ";
	m_save.close();
}
void PlayerManager::SaveWinHistory()
{
	m_save.open("WinnerHistory.txt",ios::app);
	for (int i = 0; i < m_Player_XY_Vector.size(); i++)
	{
		if (i == m_Player_XY_Vector.size() - 1)//버그에 대한 처리 ///////////////////////////////
		{
			m_save << m_Player_XY_Vector[i].x << " " << m_Player_XY_Vector[i].y;
		}
		else
			m_save << m_Player_XY_Vector[i].x << " " << m_Player_XY_Vector[i].y << " ";
	}
	m_save.close();
}
int PlayerManager::SaveStone(int x, int y, int i)
{
	if (StoneCheck(x, y))
		return 0;
	Tool.TextDraw(m_Player[i].Icon, x, y);
	tmp.x = x;
	tmp.y = y;
	m_Player_XY_Vector.push_back(tmp);
	return 1;
}
XY PlayerManager::LastClear()
{
	m_save.open("Save_XY.txt");
	tmp.x = m_Player_XY_Vector.back().x;
	tmp.y = m_Player_XY_Vector.back().y;
	m_Player_XY_Vector.pop_back();
	for (int i = 0; i < m_Player_XY_Vector.size(); i++)
	{
		m_save << m_Player_XY_Vector[i].x << " " << m_Player_XY_Vector[i].y << " ";
	}
	m_save.close();
	return tmp;

}
void PlayerManager::Clear()
{
	m_Player_XY_Vector.clear();
}
void PlayerManager::Check(int x, int y)
{
	switch (StoneCheck(x, y))
	{
	case DRAWONE:
		Tool.TextDraw(m_Player[ONE].Icon, x, y);
		break;
	case DRAWTWO:
		Tool.TextDraw(m_Player[TWO].Icon, x, y);
		break;
	}
}
void PlayerManager::MooringSet(int i)
{
	m_Player[ONE].Mooring = i;
	m_Player[TWO].Mooring = i;
}
void PlayerManager::MooringSet(int i, int j)
{
	m_Player[ONE].Mooring = i;
	m_Player[TWO].Mooring = i;
}
void PlayerManager::MooringMinus(int i)
{
	m_Player[i].Mooring--;
}

PlayerManager::~PlayerManager()
{
}
