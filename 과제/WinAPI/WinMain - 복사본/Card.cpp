#include "Card.h"

void Card::SetData(int x, int y, int Width, int Height)
{
	m_X = x;
	m_Y = y;
	m_Width = Width;
	m_Height = Height;
	m_State = false;
}