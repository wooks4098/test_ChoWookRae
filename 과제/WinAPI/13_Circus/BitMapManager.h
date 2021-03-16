#pragma once
#include "Mecro.h"

class BitMapManager
{
#pragma region ΩÃ±€≈Ê
private:

	static BitMapManager* m_pThis;
public:
	static BitMapManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new BitMapManager;
		}
		return m_pThis;
	}

#pragma endregion
public:
	BitMapManager();
	~BitMapManager();

	void CreatImage(HWND hWnd);
};

