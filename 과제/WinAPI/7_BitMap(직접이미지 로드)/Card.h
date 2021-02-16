#pragma once
#include "Mecro.h"
#include "BitMapManager.h"
class Card
{
private:
	int m_X;
	int m_Y;
	int m_Width;
	int m_Height;

	bool m_State;

	std::string m_Name;

	RECT m_Rect;

public:

	void SetData(int number);
	void SetPos(int x, int y, float spX = 0.5, float = 0.5);
	void Draw(HDC hdc);

	inline bool Get_State() { return m_State; }
	inline RECT Get_Rect() { return m_Rect; }


};

