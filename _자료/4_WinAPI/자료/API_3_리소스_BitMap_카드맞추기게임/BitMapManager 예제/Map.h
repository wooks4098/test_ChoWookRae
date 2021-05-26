#pragma once
#include"Mecro.h"
#include"MapDraw.h"
class Map
{
private:
	int m_iWidth;
	int m_iHeight;
	MapDraw m_DrawManager;
public:
	inline int GetHiehgt() { return m_iHeight; };
	inline int GetWidth() { return m_iWidth; };
	void MapDraw();
	void BoxDraw();
	void PointMoveOut();
	void SetSize(int Width, int Height);
	Map();
	~Map();
};

