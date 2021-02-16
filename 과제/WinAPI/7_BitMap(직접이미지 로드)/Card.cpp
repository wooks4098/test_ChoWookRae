#include "Card.h"

void Card::SetPos(int x, int y, float spX, float spY)
{
	m_X = x;
	m_Y = y;
	m_Width = spX;
	m_Height = spY;
	m_Rect.left = x;
	m_Rect.top = y;
	m_Rect.right = m_Rect.left +BitMapManager::GetInstans()->GetSize("검은색").cx * m_Width;
	m_Rect.bottom = m_Rect.top +BitMapManager::GetInstans()->GetSize("검은색").cy * m_Height;
	m_State = false;
}

void Card::SetData(int number)
{
	switch (number)
	{
	case card_DOG:
		m_Name = DOG;
		break;
	case card_TIGER:
		m_Name = TIGER;
		break;
	case card_DUCK:
		m_Name = DUCK;
		break;
	case card_ELEPHONT:
		m_Name = ELEPHONT;
		break;
	case card_COW:
		m_Name = COW;
		break;
	case card_HORSE:
		m_Name = HORSE;
		break;
	case card_CAT:
		m_Name = CAT;
		break;
	case card_MONKEY:
		m_Name = MONKEY;
		break;
	case card_FROG:
		m_Name = FROG;
		break;
	case card_CHICKEN:
		m_Name = CHICKEN;
		break;
	case card_BLACK:
		m_Name = BLACK;
		break;

	}
}