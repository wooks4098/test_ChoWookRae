#pragma once
#include "Mecro.h"
class Map
{
#pragma region �̱���
private:

	static Map* m_pThis;
public:
	static Map* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new Map;
		}
		return m_pThis;
	}

#pragma endregion
public:
	Map();
	~Map();
};

