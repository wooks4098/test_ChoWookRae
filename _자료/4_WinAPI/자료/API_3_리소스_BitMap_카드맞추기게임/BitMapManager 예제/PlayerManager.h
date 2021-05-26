#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include<vector>
#include<fstream>
#include<Windows.h>
#include"Map.h"
#define ONE 0
#define TWO 1
#define DRAWONE 1
#define DRAWTWO 2
#define ENTER 13
#define ESC 27
#define EAST 2
#define NORTH -1
#define SOUTH 1
#define WEST -2

struct Character {
	string name;
	string Icon;
	int Mooring;
};
class PlayerManager
{
private:
	Character m_Player[2];
	vector<XY> m_Player_XY_Vector;
	MapDraw Tool;
	int m_icount;
	XY tmp;
	Map m_Map;///////////////////////////////////////////////
	ifstream m_Load;
	ofstream m_save;
public:
	void SavePlayerName();
	void SaveIcon();
	void SaveIcon(bool Replay);
	void SaveMooring();
	int WinnerHistoryFileCheck();
	void WinHistoryLoad();
	void SaveWinHistory();
	int SaveFileCheck();
	void StoneAllLoad();
	void MooringMinus(int i);
	void StoneAllReDraw();
	inline void LoadandSaveIcon(string one, string two) { m_Player[ONE].Icon = one; m_Player[TWO].Icon = two; };
	inline int GetMooring(int i) { return m_Player[i].Mooring; };
	inline string GetName(int i) { return m_Player[i].name; };
	inline int GetSize() { return m_Player_XY_Vector.size(); };
	void StoneSetting(ICONTYPE Icon);
	int WinCheck(int i);
	int SaveStone(int x, int y, int i);
	void SetName(string name1,string name2);
	void Check(int x, int y);
	int StoneCheck(int x, int y);
	void Clear();
	XY LastClear();
	void StoneLinkCheck(int i, int x, int y, int x_, int y_);
	void MooringSet(int i);
	void MooringSet(int i, int j);//오버로딩
	PlayerManager();
	~PlayerManager();
};

