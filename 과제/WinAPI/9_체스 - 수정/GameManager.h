#pragma once
#include "Player.h"



class GameManager
{
#pragma region �̱���
private:

	static GameManager* m_pThis;
public:
	static GameManager* GetInstans()
	{
		if (m_pThis == NULL)
		{
			m_pThis = new GameManager;
		}
		return m_pThis;
	}

#pragma endregion


private:
	int Trun;
	bool ClickPiece;

	Player player[2];
	Piece_info ClickPiece_info;




public:
	void SetData();
	void Draw(HDC hdc);

	//Ŭ�� �̺�Ʈ
	void MouseClick(POINT mouse);
	POINT MousePointChange(POINT mouse);//���콺 ������ ��ġ ��ǥ�� ��ȯ

	void PieceCheck(POINT mouse); //� �ǽ��� Ŭ���ߴ��� 


	int TurnCheck();//���� ���� �÷��̾� ��ȯ
};

