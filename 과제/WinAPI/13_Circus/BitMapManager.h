#pragma once
#include "Mecro.h"
#include "BitMap.h"

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
private:
	BitMap bitmap[RESOURCE];

public:
	BitMapManager();
	~BitMapManager();
	void Draw(HDC hdc, RECT rect,int FileName ,int Frame, int Direction);
	void Draw(HDC hdc, RECT rect, int FileName);

	void CreatImage(HWND hWnd);
};

