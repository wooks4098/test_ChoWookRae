#include "CardManager.h"

CardManager::CardManager()
{
	m_preOpenCard = NULL;	// ������ ������ ī��
}

CardManager::~CardManager()
{
}

void CardManager::init()
{
	randSetImage();
	setPosAll();
}

void CardManager::randSetImage()
{
	int randCard[20];
	int arrNum = 0;
	int randSize = 20;

	while (arrNum < randSize)					// �ߺ��� �ƴ� ���� 20���� ������ �������� �ݺ���
	{
		bool doubleCheck = false;
		int randNum = rand() % randSize;		// 1���� NUM ������ŭ ���� ����

		for (int i = 0; i <= arrNum; i++)		// ������ ������ ���� �ߺ� Ȯ���� ���� for��
		{
			if (randCard[i] == randNum)			// �ߺ��� �ִٸ�?
			{
				doubleCheck = true;				// YES��, for �ݺ����� ���� ����
				break;
			}
		}
		if (doubleCheck == false)				// ���� Ȯ�� ��� �ߺ��� ���ٸ�?
		{
			randCard[arrNum] = randNum;		    // ���� �迭�� ���ҿ� Lotto �� �Է�
			arrNum++;							// �迭�� ���� �ּҷ� �̵�
		}
	}

	for (int i = 0; i < 20; i++)	
	{	
		if (randCard[i] >= 10)
			randCard[i] = randCard[i] - 10;	// �̹�����0~9�� ���̹Ƿ� 10~19�� �ߺ�ī�� �Ѱ� �� ����
		m_CardList[i].setImage((IMAGE)randCard[i]);
	}
}

void CardManager::setPosAll() // ī�帮��Ʈ ��ġ
{
	for (int i = 0; i < 5; i++)		
		m_CardList[i].setPos(50 + (100 * i), 10);
	for (int i = 0; i < 5; i++)
		m_CardList[i + 5].setPos(50 + (100 * i), 140);
	for (int i = 0; i < 5; i++)
		m_CardList[i + 10].setPos(50 + (100 * i), 270);
	for (int i = 0; i < 5; i++)
		m_CardList[i + 15].setPos(50 + (100 * i), 400);
}

int CardManager::selectCard(POINT mouse)
{
	bool check = false;

	for (int i = 0; i < 20; i++)
	{
		check = m_CardList[i].cardOpen(mouse);	// ���� ���콺 ��ġ�� ī�尡 ���� ������ ����

		if (check == true)	// ���� ���콺 ��ġ�� ī�带 �����ٸ�?
		{
			if (m_preOpenCard == NULL)	// ���� ������ ���� ī�尡 ������
				m_preOpenCard = &m_CardList[i];
			return i;	// ������ ī���� index ��ȯ
		}
	}
	return CARD_NONE;	// ���콺 �����Ͱ� ī�� �����ȿ� ������ ��ȯ
}

bool CardManager::CompareCard(int index1, int index2)
{
	if(index1 == index2)
		return false;
	if(m_CardList[index1].getImageIndex() == m_CardList[index2].getImageIndex())
		return true;
	else
		return false;
}

void CardManager::CardClose(int index)
{
	m_CardList[index].cardClose();
}

void CardManager::drawAll(HDC hdc)
{
	for (int i = 0; i < 20; i++)
		m_CardList[i].draw(hdc);
}

bool CardManager::winCheck(HWND hWnd)
{
	for (int i = 0; i < 20; i++)
	{
		if (m_CardList[i].getCardState() == CARD_CLOSE)
			return false;
	}
	return true;
}
