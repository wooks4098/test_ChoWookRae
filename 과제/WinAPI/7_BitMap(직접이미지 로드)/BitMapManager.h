#pragma once
#include "Mecro.h"
#include "Bitmap.h"
#include "Card.h"
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

private:
	
	std::map<std::string, Bitmap> Image;


public:
	void SetImage( HWND hWnd);
	void Load_Image(HDC hdc, LPCWSTR FileName,std::string name);

	void Draw(HDC hdc, int x, int y, float spX, float spY, std::string name);

	SIZE GetSize(std::string name);
};

