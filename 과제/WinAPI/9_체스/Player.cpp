#include "Player.h"


#pragma region 데이터 세팅
void Player::SetData_White()
{
	IsBlack = WHITE;
	SetPiece_Data_White();
	SetPos_White();
}

void Player::SetData_Black()
{
	IsBlack = BLACK;
	SetPiece_Data_Black();
	SetPos_Black();
}


void Player::SetPiece_Data_White()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Pos[y][x].Piece_Number = NULLPIECE;
		}
	}
	for (int i = 0; i < 16; i++)
	{
		switch (i)
		{
		case Piece_KING:
			Piece[i] = new King(SPRITE_W_KING, true);
			break;
		case Piece_QUEEN:
			Piece[i] = new Queen(SPRITE_W_QUEEN, true);
			break;
		case Piece_KNIGHT_0:
		case Piece_KNIGHT_1:
			Piece[i] = new Knight(SPRITE_W_BISHOP, true);
			break;
		case Piece_BISHOP_0:
		case Piece_BISHOP_1:
			Piece[i] = new Bishop(SPRITE_W_KNIGHT, true);
			break;
		case Piece_ROOK_0:
		case Piece_ROOK_1:
			Piece[i] = new Rook(SPRITE_W_ROOK, true);
			break;
		case Piece_PAWN_0:
		case Piece_PAWN_1:
		case Piece_PAWN_2:
		case Piece_PAWN_3:
		case Piece_PAWN_4:
		case Piece_PAWN_5:
		case Piece_PAWN_6:
		case Piece_PAWN_7:
			Piece[i] = new Pawn(SPRITE_W_PAWN, true);
			break;
		}
	}

}

void Player::SetPiece_Data_Black()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Pos[y][x].Piece_Number = NULLPIECE;
		}
	}
	for (int i = 0; i < 16; i++)
	{
		switch (i)
		{
		case Piece_KING:
			Piece[i] = new King(SPRITE_B_KING, true);
			break;
		case Piece_QUEEN:
			Piece[i] = new Queen(SPRITE_B_QUEEN, true);
			break;
		case Piece_KNIGHT_0:
		case Piece_KNIGHT_1:
			Piece[i] = new Knight(SPRITE_B_BISHOP, true);
			break;
		case Piece_BISHOP_0:
		case Piece_BISHOP_1:
			Piece[i] = new Bishop(SPRITE_B_KNIGHT, true);
			break;
		case Piece_ROOK_0:
		case Piece_ROOK_1:
			Piece[i] = new Rook(SPRITE_B_ROOK, true);
			break;
		case Piece_PAWN_0:
		case Piece_PAWN_1:
		case Piece_PAWN_2:
		case Piece_PAWN_3:
		case Piece_PAWN_4:
		case Piece_PAWN_5:
		case Piece_PAWN_6:
		case Piece_PAWN_7:
			Piece[i] = new Pawn(SPRITE_B_PAWN, true);
			break;
		}
	}
}


void Player::SetPos_White()
{
	int y;
	for (int x = 0; x < 8; x++)
	{
		//폰 세팅
		y = 7;
		Pos[y][x].Piece_Number = x + 8;
		Pos[y][x].x = x;
		Pos[y][x].y = y;

		//그외
		y = 6;
		Pos[y][x].Piece_Number = x;
		Pos[y][x].x = x;
		Pos[y][x].y = y;

	}
}


void Player::SetPos_Black()
{
	int y;
	for (int x = 0; x < 8; x++)
	{
		//폰 세팅
		y = 0;
		Pos[y][x].Piece_Number = x + 8;
		Pos[y][x].x = x;
		Pos[y][x].y = y;

		//그외
		y = 1;
		Pos[y][x].Piece_Number = x;
		Pos[y][x].x = x;
		Pos[y][x].y = y;
	}
}
#pragma endregion

void Player::Draw(HDC hdc)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (Pos[y][x].Piece_Number != NULLPIECE)
				Piece[Pos[y][x].Piece_Number]->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT);
		}
	}
}