#pragma once
#include "Mecro.h"
class GameManager
{
private:

	static GameManager* m_pThis;
public:
	static GameManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new GameManager;
		}
		return m_pThis;
	}
};

