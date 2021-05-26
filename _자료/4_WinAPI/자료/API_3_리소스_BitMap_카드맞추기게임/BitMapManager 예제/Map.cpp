#include "Map.h"


Map::Map()
{
	m_iHeight = 20;
	m_iWidth = 20;
}

void Map::MapDraw()
{
	m_DrawManager.ConsoleSet(m_iWidth, m_iHeight);
	m_DrawManager.BoxDraw(0,0,m_iWidth, m_iHeight, MAP);
}

void Map::BoxDraw()
{
	m_DrawManager.ConsoleSet(m_iWidth, m_iHeight);
	m_DrawManager.BoxDraw(0,0,m_iWidth, m_iHeight, BOX);
}
void Map::PointMoveOut()
{
	m_DrawManager.gotoxy(0, m_iHeight);
}
void Map::SetSize(int Width, int Height)
{
	m_iHeight = Height;
	m_iWidth = Width;
}

Map::~Map()
{
}