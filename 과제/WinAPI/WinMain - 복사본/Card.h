#pragma once
#include "Mecro.h"

class Card
{
private:
	int m_X;
	int m_Y;
	int m_Width;
	int m_Height;
	bool m_State;
	RECT m_Rect;

public:

	void SetData(int x, int y, int Width, int Height);
	void SetPos();


	inline bool Get_State() { return m_State; }
	inline RECT Get_Rect() { return m_Rect; }


};

