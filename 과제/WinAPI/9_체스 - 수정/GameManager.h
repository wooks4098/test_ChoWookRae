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
	std::vector<POINT> CanMove_Pos; //�̵������� ��ǥ ����
	Piece_info Piece_Pos[8][8]; //��� �ǽ� ��ġ ����
	


public:
	void SetData();
	void Draw(HDC hdc);

	//Ŭ�� �̺�Ʈ
	bool MouseClick(HDC hdc, HWND hWnd, POINT mouse);
	POINT MousePointChange(POINT mouse);//���콺 ������ ��ġ ��ǥ�� ��ȯ
	bool MouseClick_CanMovePos(POINT mouse);//�̵������� ��ǥ�� Ŭ���ߴ���

	
	int TurnCheck();//���� ���� �÷��̾� ��ȯ

	void Win(HWND hWnd);


	//void PieceCheck(POINT mouse); //� �ǽ��� Ŭ���ߴ��� 

};

