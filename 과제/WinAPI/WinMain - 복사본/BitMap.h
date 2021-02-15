#include "Mecro.h"

class BitMap
{
private:

	HDC		MemDC;
	HBITMAP	m_pMyBitMap;
	HBITMAP	m_pOldBitMap;

public:
	void Draw(HDC hdc, HINSTANCE hInst, int x, int y, std::string Name);


};

