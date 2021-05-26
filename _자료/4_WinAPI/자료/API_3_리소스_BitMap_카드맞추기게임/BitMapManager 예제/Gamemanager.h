#pragma once
#include<fstream>
#include"Mecro.h"
#include"MapDraw.h"
#include"Map.h"
#include"PlayerManager.h"
#define START 1
#define OPTION 2
#define END 3
#define MAPSIZE 1
#define CURSORCUSTOM 2
#define STONECUSTOM 3
#define UNDOCOUNTSET 4
#define RETURN 5
#define LEFT 0
#define RIGHT 1
#define ROOF 0
#define GROUND 1
#define ENTER 13
#define ESC 27
#define ONE 0
#define TWO 1
#define X 0
#define Y 1
struct CURSOR {
	int x;
	int y;
	int x_range[2];
	int y_range[2];
	string Icon[2];
	
};
struct StartOption {
	string strOption_1;
	string strOption_2;
	string strOption_3;
	string strOption_4;
	string strOption_5;
};
struct Menustring {
	string Gamename;
	string MainMenu_1;
	string MainMenu_2;
	string MainMenu_3;
};
class Gamemanager
{
private:
	bool m_GameEnd;
	bool m_GamePlaying;
	Map m_map;
	StartOption m_Optionstring;
	Menustring m_MainMenustring;
	MapDraw m_Draw;
	PlayerManager Players;
	CURSOR m_Cursor;
	ICONTYPE m_IconType;
	int m_iSelect;
	int m_istandard_x;
	int m_istandard_y;
	int m_Turn;
	XY m_XY_tmp;
	ofstream m_save;
	ifstream m_Load;
public:
	void IconLoad();
	void SettingLoad();
	void SaveCursorIcon();
	void StoneAllLoad(bool Replay);
	void ClearFile();
	void SaveFile(int x,int y);
	void Setting_Icon(string type);
	void CursorIconSetting(ICONTYPE Icon);
	void ReDraw(int x, int y);
	void PrintAdvice2(int i);
	void CursorPositionSetting(int Width, int Height);
	void CursorMove();
	void Option(bool InGame);
	void GamePlay();
	void Setting();
	void Setting_Map_Size();
	void PrintAdvice();
	int PrintOption();
	void UndoSetting();
	void WinnerPrint(int i);
	void DrawCursor(string icon);
	int Menu();
	void Play();
	Gamemanager();
	~Gamemanager();
};