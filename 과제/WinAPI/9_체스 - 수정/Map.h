#pragma once
#include "Mecro.h"
#include "SpriteManager.h"
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
private:

public:
	void MapDraw(HDC hdc, std::vector<POINT> CanMove_Pos);
	void MovePointDraw();
	void Draw_CanMovePos(HDC hdc, std::vector<POINT> CanMove_Pos);
};

