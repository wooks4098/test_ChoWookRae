#include "Mecro.h"

class Bitmap
{
private:
	HDC     MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE    m_size;

public:
	void Draw(HDC hdc, int x, int y, float spX, float spY);
	void CreatImage(HDC hdc, LPCWSTR FileName);
	inline SIZE GetSize()
	{
		return m_size;
	}
};

