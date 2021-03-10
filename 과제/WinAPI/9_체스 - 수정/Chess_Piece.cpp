#include "Chess_Piece.h"


//Piece
void Chess_Piece::Draw(HDC hdc)
{
	SpriteManager::GetInstans()->Draw(hdc, 20 + m_Pos.x * WIDTH, 20 + m_Pos.y * HEIGHT, WIDTH, HEIGHT, m_name, true);
}
void Chess_Piece::SetPos(int x, int y)
{
	m_Pos.x = x;
	m_Pos.y = y;

}
int Chess_Piece::Change(HWND hWnd)
{
	return 0;
}
void Chess_Piece::isClick(bool check)
{
	m_isClick = check;
}

void Chess_Piece::Move(POINT mouse)
{
	m_Pos = mouse;
}

#pragma region Return
bool Chess_Piece::Return_isBlack()
{
	return m_isBlack;
}

POINT Chess_Piece::Return_Pos()
{
	return m_Pos;
}
int Chess_Piece::Return_PieceName()
{
	return m_name;
}

#pragma endregion



//king

King::King(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void King::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}



bool King::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;


	//첫 번째 줄
	Pos = m_Pos;
	Pos.x--;
	Pos.y--;
	for (int i = 0; i < 3; i++)
	{
		if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
		{
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
				||(Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))//다른 진영의 피스가 있을 때
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		Pos.x++;
	}


	//두 번째 줄
	Pos = m_Pos;
	Pos.x--;
	for (int i = 0; i < 2; i++)
	{
		if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
		{
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
				|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))//다른 진영의 피스가 있을 때
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		Pos.x += 2;

	}
	//세 번째 줄
	Pos = m_Pos;
	Pos.x--;
	Pos.y++;
	for (int i = 0; i < 3; i++)
	{
		if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
		{
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
				|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack))//다른 진영의 피스가 있을 때
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		Pos.x++;

	}

	return CanMove;
}

//Queen

Queen::Queen(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Queen::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}



bool Queen::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;
	Pos = m_Pos;
	//→ x++
	for (int i = 0; i < 8; i++)
	{
		Pos.x++;
		if (Pos.x > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	//← x--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.x--;
		if (Pos.x < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;


	}
	//↑ y--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y--;
		if (Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;


	}

	//↓ y++
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y++;
		if (Pos.y > 7)
			break;

		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;

	}

	//↗
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x++;
		Pos.y--;
		if (Pos.x > 7 || Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}


	//↖
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x--;
		Pos.y--;
		if (Pos.x < 0 || Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}


	//↙
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x--;
		Pos.y++;
		if (Pos.x < 0 || Pos.y > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	//↘
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x++;
		Pos.y++;
		if (Pos.x > 7 || Pos.y > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	return CanMove;
}
//Knight

Knight::Knight(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Knight::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


bool Knight::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;

	//↗
	Pos = m_Pos;
	Pos.x++;
	Pos.y -= 2;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			||(Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}

	Pos.x++;
	Pos.y++;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}
	//↘
	Pos = m_Pos;
	Pos.x +=2;
	Pos.y++;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}
	Pos.x--;
	Pos.y++;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}
	//↙
	Pos = m_Pos;
	Pos.x--;
	Pos.y += 2;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}
	Pos.x--;
	Pos.y--;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}

	//↖
	Pos = m_Pos;
	Pos.x -= 2;
	Pos.y--;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}
	Pos.x++;
	Pos.y--;
	if (Pos.x >= 0 && Pos.x <= 7 && Pos.y >= 0 && Pos.y <= 7)
	{
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1 //피스가 없을 때
			|| (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
		}
	}

	return CanMove;

}
//Bishop

Bishop::Bishop(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Bishop::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


bool Bishop::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;


	//↗
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x++;
		Pos.y--;
		if (Pos.x > 7 || Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	

	//↖
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x--;
		Pos.y--;
		if (Pos.x < 0 || Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}


	//↙
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x--;
		Pos.y++;
		if (Pos.x <0  || Pos.y > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	//↘
	Pos = m_Pos;
	for (int i = 0; i < 7; i++)
	{
		Pos.x++;
		Pos.y++;
		if (Pos.x > 7 || Pos.y > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	return CanMove;
}
//Rook

Rook::Rook(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Rook::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}


bool Rook::CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	bool CanMove = false;
	POINT Pos;
	Pos = m_Pos;
	//→ x++
	for (int i = 0; i < 8; i++)
	{
		Pos.x++;
		if (Pos.x > 7)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;
	}
	//← x--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.x--;
		if (Pos.x < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;


	}
	//↑ y--
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y--;
		if (Pos.y < 0)
			break;
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;


	}

	//↓ y++
	Pos = m_Pos;
	for (int i = 0; i < 8; i++)
	{
		Pos.y++;
		if (Pos.y > 7)
			break;

		if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1) //피스가 없을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			continue;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack) //다른 진영의 피스가 있을 때
		{
			CanMove_Pos->push_back(Pos);
			CanMove = true;
			break;
		}
		if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack == m_isBlack)//같은 진영의 피스가 있을 때
			break;

	}
	return CanMove;
}

//Pawn

Pawn::Pawn(int name, bool isBlack)
{
	SetPiece(name, isBlack);
}

void Pawn::SetPiece(int name, bool isBlack)
{
	m_name = name;
	m_isBlack = isBlack;
	m_isClick = false;
}

int Pawn::Change(HWND hWnd)
{
	if ((MessageBox(hWnd, TEXT("Queen"), TEXT("Promotion"), MB_YESNO)) == IDYES)
		return Piece_QUEEN_3;
	if ((MessageBox(hWnd, TEXT("Knight"), TEXT("Promotion"), MB_YESNO)) == IDYES)
		return Piece_KNIGHT_3;
	if ((MessageBox(hWnd, TEXT("Bishop"), TEXT("Promotion"), MB_YESNO)) == IDYES)
		return Piece_BISHOP_3;
	(MessageBox(hWnd, TEXT("Rook"), TEXT("Promotion"), MB_OK));
	return Piece_ROOK_3;

}

bool Pawn:: CanMovePos(std::vector<POINT> *CanMove_Pos, Piece_info Piece_Pos[8][8])
{
	
	//앞 2칸 && 앞 대각선 검은피스 있을 경우
	bool CanMove = false;
	POINT Pos;
	Pos = m_Pos;
	if (m_isBlack)//검은색인 경우
	{
		if (m_Pos.y == 1)//처음위치일 경우
		{
			//y+1 y+2			
			for (int i = 0; i < 2; i++)
			{
				Pos.y++;
				
				//앞에 다른 피스가 있는 경우 예외처리
				if(Piece_Pos[Pos.y][Pos.x].PieceNumber != -1)
					break;
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
			
		}
		else
		{
			//y+1
			Pos.y++;
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1)
			{
				CanMove_Pos->push_back(Pos); 
				CanMove = true;

			}
			//x-1 y+1
			Pos.x--;
			if (Pos.x >= 0 &&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
			// x+1 y+1
			Pos.x += 2;
			if (Pos.x <= 7 && Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		
	}
	else//흰색인 경우
	{
		if (m_Pos.y == 6)//처음위치일 경우
		{
			//y-1  y -2
			for (int i = 0; i < 2; i++)
			{
				Pos.y--;
				//앞에 다른 피스가 있는 경우 예외처리
				if (Piece_Pos[Pos.y][Pos.x].PieceNumber != -1)
					break;
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}
		}
		else
		{
			//y-1
			Pos.y--;
			if (Piece_Pos[Pos.y][Pos.x].PieceNumber == -1)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;

			}
			//x-1 y-1
			Pos.x--;
			if (Pos.x >= 0&&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;
			}

			// x+1 y-1
			Pos.x += 2;
			if (Pos.x<= 7 &&Piece_Pos[Pos.y][Pos.x].PieceNumber != -1 && Piece_Pos[Pos.y][Pos.x].isBlack != m_isBlack)
			{
				CanMove_Pos->push_back(Pos);
				CanMove = true;

			}
		}


	
	}
	return CanMove;
}