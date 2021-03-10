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
	std::vector<POINT> CanMove_Pos; //이동가능한 좌표 저장
	Piece_info Piece_Pos[8][8]; //모든 피스 위치 저장
	


public:
	void SetData();
	void Draw(HDC hdc);

	//클릭 이벤트
	bool MouseClick(HDC hdc, HWND hWnd, POINT mouse);
	POINT MousePointChange(POINT mouse);//마우스 포인터 위치 좌표로 변환
	bool MouseClick_CanMovePos(POINT mouse);//이동가능한 좌표를 클릭했는지

	
	int TurnCheck();//현재 턴의 플레이어 반환

	void Win(HWND hWnd);


	//void PieceCheck(POINT mouse); //어떤 피스를 클릭했는지 

};

