#include "Gamemanager.h"

Gamemanager::Gamemanager()
{
	m_MainMenustring.Gamename = "★ 오 목 ★";
	m_MainMenustring.MainMenu_1 = "1.게임 시작";
	m_MainMenustring.MainMenu_2 = "2.옵션 설정";
	m_MainMenustring.MainMenu_3 = "3.게임 종료";
	m_Optionstring.strOption_1 = "1.Map Size Set";
	m_Optionstring.strOption_2 = "2.Cursor Custom";
	m_Optionstring.strOption_3 = "3.Stone Custom";
	m_Optionstring.strOption_4 = "4.Undo Count Set";
	m_Optionstring.strOption_5 = "5.Return";
	CursorIconSetting(ICON_NOMAL);
	m_Turn = 1;
	m_GamePlaying = false;
}
void Gamemanager::Option(bool InGame)
{
	bool escape = false;
	while (!escape)
	{
		switch (PrintOption())
		{
		case MAPSIZE:
			Setting_Map_Size();
			break;
		case CURSORCUSTOM:
			Setting_Icon("Cursor");
			break;
		case STONECUSTOM:
			Setting_Icon("Stone");
			break;
		case UNDOCOUNTSET:
			if (InGame)
			{
				m_map.BoxDraw();
				m_Draw.DrawMidText("게임 중에는 무르기 횟수 조정 불가", m_istandard_x - 10, m_istandard_y);
				getch();
				break;
			}
			UndoSetting();
			break;
		case RETURN:
			escape = true;
			break;
		}
	}
}
void Gamemanager::UndoSetting()
{
	int Undo;
	int Select;
	bool Escape = false;
	while (!Escape)
	{
		m_map.BoxDraw();
		m_Draw.TextDraw("= Set Undo =", m_istandard_x, m_istandard_y - 6);
		m_Draw.TextDraw("1.Set Undo Count", m_istandard_x - 2, m_istandard_y - 4);
		m_Draw.TextDraw("2.Undo Off", m_istandard_x - 2, m_istandard_y - 2);
		m_Draw.TextDraw("3.Return", m_istandard_x - 2, m_istandard_y);
		m_Draw.TextDraw("입력 : ", m_istandard_x, m_istandard_y + 2);
		cin >> Select;
		switch (Select)
		{
		case 1:
			while (1)
			{
				m_map.BoxDraw();
				m_Draw.TextDraw("무르기 횟수 입력<최대 10회> : ", m_istandard_x - 10, m_istandard_y);
				m_Draw.gotoxy(m_istandard_x + 20, m_istandard_y);
				cin >> Undo;
				if (Undo >= 0 && Undo <= 10)
					break;
				m_Draw.TextDraw(" 범위가 맞지 않습니다 < 0 ~ 10 > ", m_istandard_x - 9, m_istandard_y + 2);
				getch();
			}
			Players.MooringSet(Undo);
			break;
		case 2:
			m_map.BoxDraw();
			m_Draw.TextDraw("무르기 OFF", m_istandard_x, m_istandard_y);
			Players.MooringSet(0);
			getch();
			break;
		case 3:
			Escape = true;
			break;
		}
	}
}
void Gamemanager::CursorIconSetting(ICONTYPE Icon)
{
	switch (Icon)
	{
	case ICON_NOMAL:
		m_Cursor.Icon[TWO] = "●";
		m_Cursor.Icon[ONE] = "○";
		break;
	case ICON_HEART:
		m_Cursor.Icon[TWO] = "♥";
		m_Cursor.Icon[ONE] = "♡";
		break;
	case ICON_FINGER:
		m_Cursor.Icon[TWO] = "☞";
		m_Cursor.Icon[ONE] = "☜";
		break;
	case ICON_NUMCIR:
		m_Cursor.Icon[TWO] = "②";
		m_Cursor.Icon[ONE] = "①";
		break;
	}
}
void Gamemanager::CursorPositionSetting(int Width, int Height)
{
	m_Cursor.x = Width;
	m_Cursor.y = Height / 2;
	m_Cursor.x_range[LEFT] = 1;
	m_Cursor.x_range[RIGHT] = (Width * 2) - 2;
	m_Cursor.y_range[ROOF] = 0;
	m_Cursor.y_range[GROUND] = Height - 1;
}
int Gamemanager::PrintOption()
{
	m_map.BoxDraw();
	int Select;
	m_Draw.TextDraw("= Option =", m_istandard_x + 1, m_istandard_y - 6);
	m_Draw.TextDraw(m_Optionstring.strOption_1, m_istandard_x - 2, m_istandard_y - 4);
	m_Draw.TextDraw(m_Optionstring.strOption_2, m_istandard_x - 2, m_istandard_y - 2);
	m_Draw.TextDraw(m_Optionstring.strOption_3, m_istandard_x - 2, m_istandard_y);
	m_Draw.TextDraw(m_Optionstring.strOption_4, m_istandard_x - 2, m_istandard_y + 2);
	m_Draw.TextDraw(m_Optionstring.strOption_5, m_istandard_x - 2, m_istandard_y + 4);
	m_Draw.TextDraw("입력 : ", m_istandard_x + 2, m_istandard_y + 6);
	m_Draw.gotoxy(m_istandard_x + 9, m_istandard_y + 6);
	cin >> Select;
	return Select;
}

void Gamemanager::Setting_Icon(string type)
{
	bool Escape = false;
	int Select;
	while (!Escape)
	{
		m_map.BoxDraw();
		m_Draw.DrawMidText("= Set " + type + " =", m_istandard_x, m_istandard_y - 6);
		m_Draw.DrawMidText("1.●,○", m_istandard_x, m_istandard_y - 4);
		m_Draw.DrawMidText("2.♥,♡", m_istandard_x, m_istandard_y - 2);
		m_Draw.DrawMidText("3.☞,☜", m_istandard_x, m_istandard_y);
		m_Draw.DrawMidText("4.①,②", m_istandard_x, m_istandard_y + 2);
		m_Draw.DrawMidText("5.Return", m_istandard_x, m_istandard_y + 4);
		m_Draw.DrawMidText("입력 : ", m_istandard_x, m_istandard_y + 6);
		cin >> Select;
		if (Select == 5)
		{
			Escape = true;
			break;
		}
		if (type == "Stone")
		{
			Players.StoneSetting((ICONTYPE)Select);
		}
		else
		{
			CursorIconSetting((ICONTYPE)Select);
		}
	}
}
void Gamemanager::Setting_Map_Size()
{
	int Width, Height;
	bool Escape = false;
	while (!Escape)
	{
		m_map.BoxDraw();
		m_Draw.TextDraw("Width : ", m_istandard_x + 1, m_istandard_y - 2);
		cin >> Width;
		m_Draw.TextDraw("Height : ", m_istandard_x, m_istandard_y + 2);
		cin >> Height;
		if ((Width >= 20 && Width <= 90) && (Height >= 20 && Height <= 45))
			Escape = true;
		else
		{
			m_map.BoxDraw();
			m_Draw.DrawMidText("변경 불가능", m_map.GetWidth(), m_istandard_y - 1);
			m_Draw.DrawMidText("(가로 : 20 ~ 90 , 세로 : 20 ~ 45)", m_map.GetWidth(), m_istandard_y + 1);
			m_map.PointMoveOut();
			getch();
		}
	}
	m_map.SetSize(Width, Height);
}
int Gamemanager::Menu()//얘내들이 맵드로우에 있는게 좋을까?하지만 맵의 정보아닌가?
//겜메에 넣으려했지만 gotoxy 를 지정해 선택 값  을 리턴해야 하려면 inline 함수로 리턴으로 다 받아내서 해야하니 별로 일 것 같아 그냥 맵에다 넣는다.ㄴㄴ걍 한다 기준값 때문에
{
	m_istandard_x = m_map.GetWidth() - 6;
	m_istandard_y = m_map.GetHiehgt() / 2;
	int Select;
	m_map.MapDraw();
	m_Draw.TextDraw(m_MainMenustring.Gamename, m_istandard_x, m_istandard_y - 4);
	m_Draw.TextDraw(m_MainMenustring.MainMenu_1, m_istandard_x, m_istandard_y - 2);
	m_Draw.TextDraw(m_MainMenustring.MainMenu_2, m_istandard_x, m_istandard_y);
	m_Draw.TextDraw(m_MainMenustring.MainMenu_3, m_istandard_x, m_istandard_y + 2);
	if (Players.WinnerHistoryFileCheck())
	{
		m_Draw.TextDraw("4. 리플레이", m_istandard_x, m_istandard_y + 4);
		m_Draw.BoxDraw(m_map.GetWidth() / 2, m_istandard_y + 6, m_map.GetWidth() / 2, 3, BOX);
		m_Draw.gotoxy(m_map.GetWidth(), m_istandard_y + 7);
	}
	else
	{
		m_Draw.BoxDraw(m_map.GetWidth() / 2, m_istandard_y + 4, m_map.GetWidth() / 2, 3, BOX);

		m_Draw.gotoxy(m_map.GetWidth(), m_istandard_y + 5);
	}
	cin >> Select;
	return Select;
}
void Gamemanager::PrintAdvice()
{
	m_Draw.DrawMidText("=====조작키=====", m_map.GetWidth(), m_map.GetHiehgt());
	m_Draw.DrawMidText("이동 : A,S,W,D 돌 놓기 : ENTER", m_map.GetWidth(), m_map.GetHiehgt() + 1);
	m_Draw.DrawMidText("무르기 : N 옵션 : P 종료 : ESC", m_map.GetWidth(), m_map.GetHiehgt() + 2);
}
void Gamemanager::PrintAdvice2(int i)
{
	m_Draw.DrawMidText("플레이어 : " + Players.GetName(i) + "\t 무르기 : " + to_string(Players.GetMooring(i)), m_map.GetWidth() - 2, m_map.GetHiehgt() + 3);
	m_Draw.DrawMidText("Turn : " + to_string(m_Turn), m_map.GetWidth(), m_map.GetHiehgt() + 4);
}
void Gamemanager::Setting()
{
	string name1, name2;//함수화 시키자
	m_map.BoxDraw();
	m_Draw.DrawMidText("P1 이름", m_map.GetWidth(), m_istandard_y - 4);
	m_Draw.DrawMidText("입력 : ", m_map.GetWidth() - 3, m_istandard_y - 3);
	m_Draw.gotoxy(m_map.GetWidth() + 2, m_istandard_y - 3);
	cin >> name1;
	m_Draw.DrawMidText("P2 이름", m_map.GetWidth(), m_istandard_y + 3);
	m_Draw.DrawMidText("입력 : ", m_map.GetWidth() - 3, m_istandard_y + 4);
	m_Draw.gotoxy(m_map.GetWidth() + 2, m_istandard_y + 4);
	cin >> name2;
	Players.SetName(name1, name2);
}
void Gamemanager::GamePlay()
{
	m_Turn = 1;
	if (!m_GamePlaying && !Players.SaveFileCheck())
	{
		Setting();
	}
	m_GamePlaying = true;
	m_map.MapDraw();	
	SettingLoad();
	Players.StoneAllLoad();
	m_Turn += Players.GetSize();
	PrintAdvice();
	CursorMove();
}
void Gamemanager::WinnerPrint(int i)
{
	m_Draw.TextDraw(Players.GetName(i) + " 승리 ! ", m_istandard_x + 2, m_istandard_y);
	getch();
}
void Gamemanager::SaveFile(int x, int y)
{
	if (m_Turn > 1)
	{
		m_save.open("Save_XY.txt", ios::app);
		m_save << x << " " << y << " ";
		m_save.close();
		return;
	}
	m_save.open("Save_XY.txt");
	m_save << x << " " << y;
	m_save.close();
}
void Gamemanager::ClearFile()
{
	m_save.open("Save_XY.txt");
	m_save << NULL;
	m_save.close();
}
void Gamemanager::CursorMove()
{
	int Player;
	if (m_Turn % 2 == 1)
		Player = ONE;
	else
		Player = TWO;
	bool Escape = false;
	while (!Escape)
	{
		PrintAdvice2(Player);
		DrawCursor(m_Cursor.Icon[Player]);
		char A = getch();
		bool redraw = false;
		int RemovePosition[2];
		RemovePosition[X] = m_Cursor.x;
		RemovePosition[Y] = m_Cursor.y;
		switch (A)
		{
		case MOVELEFT:
			if (m_Cursor.x - 1 >= m_Cursor.x_range[LEFT])
			{
				m_Cursor.x -= 2;
				redraw = true;
			}
			break;
		case MOVEUP:
			if (m_Cursor.y - 1 >= m_Cursor.y_range[ROOF])
			{
				--m_Cursor.y;
				redraw = true;
			}
			break;
		case MOVERIGHT:
			if (m_Cursor.x + 1 <= m_Cursor.x_range[RIGHT])
			{
				m_Cursor.x += 2;
				redraw = true;
			}
			break;
		case MOVEDOWN:
			if (m_Cursor.y + 1 <= m_Cursor.y_range[GROUND])
			{
				++m_Cursor.y;
				redraw = true;
			}
			break;
		case ENTER:
			if (Players.SaveStone(m_Cursor.x, m_Cursor.y, Player))
			{
				m_Turn++;
				Player++;
				SaveFile(m_Cursor.x, m_Cursor.y);
			}
			else
				break;
			if (Players.WinCheck(Player - 1))
			{
				Players.SaveIcon(true);
				WinnerPrint(Player - 1);
				Players.SaveWinHistory();
				Players.Clear();
				ClearFile();
				Escape = true;
				m_GameEnd = true;
			}
			break;
		case MORRING:
			if (Players.GetSize() && Players.GetMooring(Player) > 0)
			{
				--m_Turn;
				Players.MooringMinus(Player);
				m_XY_tmp = Players.LastClear();
				m_Cursor.x = m_XY_tmp.x;
				m_Cursor.y = m_XY_tmp.y;
				ReDraw(RemovePosition[X], RemovePosition[Y]);
				Player++;
			}
			break;
		case SELECTOPTION:
			Option(true);
			m_map.MapDraw();
			Players.StoneAllReDraw();
			PrintAdvice();
			PrintAdvice2(Player);
			break;
		case ESC:
			SaveCursorIcon();
			Players.SaveIcon();
			Players.SavePlayerName();
			Players.SaveMooring();
			Escape = true;
			Players.Clear();
			break;
		}
		if (redraw)
		{
			ReDraw(RemovePosition[X], RemovePosition[Y]);
		}
		Players.Check(RemovePosition[X], RemovePosition[Y]);
		if (Player == 2)
			Player = ONE;
		if (Escape)
			break;
	}
}
void Gamemanager::SettingLoad()
{
	m_Load.open("Save.txt");
	int count[2];
	string info[2];
	if (m_Load.is_open())
	{
		m_Load >> info[ONE];
		if (info[ONE] == "○")
		{
			CursorIconSetting(ICON_NOMAL);
		}
		else if (info[ONE] == "♡")
		{
			CursorIconSetting(ICON_HEART);
		}
		else if (info[ONE] == "☜")
		{
			CursorIconSetting(ICON_FINGER);
		}
		else if (info[ONE] == "①")
		{
			CursorIconSetting(ICON_NUMCIR);
		}
		m_Load >> info[ONE];
		m_Load >> info[TWO];
		Players.LoadandSaveIcon(info[ONE], info[TWO]);
		for (int i = ONE; i <= TWO; i++)
		{
			m_Load >> info[i];
		}
		Players.SetName(info[ONE], info[TWO]);
		for (int i = ONE; i <= TWO; i++)
		{
			m_Load >> count[i];
		}
		Players.MooringSet(count[ONE], count[TWO]);
		m_Load.close();
	}
	else
		return;
}
void Gamemanager::IconLoad()
{
	m_Load.open("Save.txt");
	string info;
	if (m_Load.is_open())
	{
		m_Load >> info;
		if (info == "○")
		{
			Players.StoneSetting(ICON_NOMAL);
		}
		else if (info == "♡")
		{
			Players.StoneSetting(ICON_HEART);
		}
		else if (info == "☜")
		{
			Players.StoneSetting(ICON_FINGER);
		}
		else if (info == "①")
		{
			Players.StoneSetting(ICON_NUMCIR);
		}
	}
	else
		return;
}
void Gamemanager::SaveCursorIcon()
{
	m_save.open("Save.txt", ios::app);
	m_save << m_Cursor.Icon[ONE] << " ";
	m_save.close();
}
void Gamemanager::ReDraw(int x, int y)
{
	if (x == 0 && y == 0)
		m_Draw.TextDraw("┏", x, y);
	else if (x == m_Cursor.x_range[RIGHT] && y == 0)
		m_Draw.TextDraw("┓", x, y);
	else if (x == 0 && y == m_Cursor.y_range[GROUND])
		m_Draw.TextDraw("┗", x, y);
	else if (x == m_Cursor.x_range[RIGHT] && y == m_Cursor.y_range[GROUND])
		m_Draw.TextDraw("┛", x, y);
	else if ((x > 0 || x) < m_Cursor.x_range[RIGHT] && y == 0)
		m_Draw.TextDraw("┳", x, y);
	else if (x == 0 && (y > 0 || y < m_Cursor.y_range[GROUND] - 1))
		m_Draw.TextDraw("┣", x, y);
	else if (x == m_Cursor.x_range[RIGHT] && (y > 0 || y < m_Cursor.y_range[GROUND] - 1))
		m_Draw.TextDraw("┫", x, y);
	else if ((x > 0 || x < m_Cursor.x_range[RIGHT]) && y == m_Cursor.y_range[GROUND])
		m_Draw.TextDraw("┻", x, y);
	else
		m_Draw.TextDraw("╋", x, y);
}
void Gamemanager::DrawCursor(string icon)
{
	m_Draw.TextDraw(icon, m_Cursor.x, m_Cursor.y);
}
void Gamemanager::Play()
{
	while (1)
	{
		m_iSelect = Menu();
		switch (m_iSelect)
		{
		case START:
			CursorPositionSetting(m_map.GetWidth(), m_map.GetHiehgt());
			GamePlay();
			break;
		case OPTION:
			Option(false);
			break;
		case END:
			Players.Clear();
			return;
			break;
		case 4:
			if (Players.WinnerHistoryFileCheck())
			{
				m_map.MapDraw();
				Players.WinHistoryLoad();
				m_map.PointMoveOut();
				system("pause");
			}
			break;
		}
	}
}
Gamemanager::~Gamemanager()
{

}