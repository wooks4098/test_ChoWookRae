#pragma once
#include "Mecro.h"
#include "Sprite.h"


class SpriteManager
{
#pragma region ΩÃ±€≈Ê
private:

	static SpriteManager* m_pThis;
public:
	static SpriteManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new SpriteManager;
		}
		return m_pThis;
	}

#pragma endregion

private:
	Sprite sprite[RESOURCE_COUNT];
	


public:
	void SetImage(HWND hWnd);
	void Load_Image(HDC hdc, LPCWSTR FileName, int Piece_Number);

	void Draw(HDC hdc, float x, float y, float spX, float spY, int Piece_Number);

	SIZE GetSize(std::string name);
};

