#include "BitMap.h"

BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc, LPCWSTR FileName)
{
	MemDC = CreateCompatibleDC(hdc);

	//1��° �μ� : NULL����
	//2��° �μ� : ���ϰ��(������Ʈ ������ ����Ʈ)
	//3��° �μ� : IMAGE_BITMAP, IMAGE_ICON, IMAGE_CURSOR
	//4, 5��° �μ� : �������̳� Ŀ���� ��� �ʺ�� ����, ��Ʈ���̸� 0, 0
	//6��° �μ� : �������� �÷��� �ɼ����� �׸��� ��带 �ٲ� �� �ִ�.
	//���� �״�� ǥ���ϴ� �ɼ� - LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE ����
	m_BitMap = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
					, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);
	BITMAP BitMap_Info;
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info);
	m_size.cx = BitMap_Info.bmWidth;
	m_size.cy = BitMap_Info.bmHeight;
}
void BitMap::Draw(HDC hdc, int x, int y, float spX, float spY)
{
	StretchBlt(hdc, x, y, m_size.cx * spX, m_size.cy * spY, MemDC, 0, 0, m_size.cx, m_size.cy, SRCCOPY);
}

BitMap::~BitMap()
{
	SelectObject(MemDC, m_OldBitMap);
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
