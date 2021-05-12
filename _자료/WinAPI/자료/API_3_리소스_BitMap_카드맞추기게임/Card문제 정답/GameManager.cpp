#include "GameManager.h"



GameManager::GameManager()
{

}

void GameManager::Draw(HDC hdc)
{
	for (int i = 0; i < CARDMAX ; i++)
		m_CardList[i].Draw(hdc);
}

void GameManager::Init(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	m_CardList[0].Init(hdc, hInst, IDB_BITMAP1, "������", 100 + (0 * 145) + (0 * 10), 100 + (0 * 235));
	m_CardList[1].Init(hdc, hInst, IDB_BITMAP2, "ȣ����", 100 + (1 * 145) + (1 * 10), 100 + (0 * 235));
	m_CardList[2].Init(hdc, hInst, IDB_BITMAP3, "����", 100 + (2 * 145) + (2 * 10), 100 + (0 * 235));
	m_CardList[3].Init(hdc, hInst, IDB_BITMAP4, "�ڳ���", 100 + (3 * 145) + (3 * 10), 100 + (0 * 235));
	m_CardList[4].Init(hdc, hInst, IDB_BITMAP5, "��", 100 + (4 * 145) + (4 * 10), 100 + (0 * 235));
	m_CardList[5].Init(hdc, hInst, IDB_BITMAP6, "��", 100 + (0 * 145) + (0 * 10), 100 + (1 * 235));
	m_CardList[6].Init(hdc, hInst, IDB_BITMAP7, "�����", 100 + (1 * 145) + (1 * 10), 100 + (1 * 235));
	m_CardList[7].Init(hdc, hInst, IDB_BITMAP8, "������", 100 + (2 * 145) + (2 * 10), 100 + (1 * 235));
	m_CardList[8].Init(hdc, hInst, IDB_BITMAP9, "������", 100 + (3 * 145) + (3 * 10), 100 + (1 * 235));
	m_CardList[9].Init(hdc, hInst, IDB_BITMAP10, "��", 100 + (4 * 145) + (4 * 10), 100 + (1 * 235));
	ReleaseDC(hWnd, hdc);
}


void GameManager::ColliderCheck(HWND hWnd, POINT point)
{

	for (int i = 0; i < CARDMAX; i++)
		m_CardList[i].ColliderCheck(hWnd, point);
}

GameManager::~GameManager()
{
}
