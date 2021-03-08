#pragma once
#include "Player.h"



class GameManager
{
#pragma region 싱글톤
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

	//클릭 이벤트
	void MouseClick(POINT mouse);
	POINT MousePointChange(POINT mouse);//마우스 포인터 위치 좌표로 변환

	void PieceCheck(POINT mouse); //어떤 피스를 클릭했는지 


	int TurnCheck();//현재 턴의 플레이어 반환
};

