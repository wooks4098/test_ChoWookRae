#pragma once

#include <vector>
#include<Windows.h>
#include<string>
#include<time.h>

#define RESOURCE_COUNT 15
#define WIDTH 75
#define HEIGHT 75
#define NULLPIECE -1
#define WHITE 0
#define BLACK 1
#define PIECECOUNT 16

//이동가능한 좌표가 담긴 변수


//피스 번호, 위치, 진영이 담긴 변수

//std::vector<POINT> dd;

//std::vector<CanMovePos_info> canMovePos_info;
//
//struct CanMovePos_info
//{
//	bool isBlack;
//	POINT Pos;
//};

struct Piece_info
{
	bool isBlack;
	int PieceNumber;
};


enum SPRITE
{
	SPRITE_B_PAWN= 0,
	SPRITE_B_KNIGHT,
	SPRITE_B_BISHOP,
	SPRITE_B_ROOK,
	SPRITE_B_KING,
	SPRITE_B_QUEEN,

	SPRITE_W_PAWN,
	SPRITE_W_KNIGHT,
	SPRITE_W_BISHOP,
	SPRITE_W_ROOK,


	SPRITE_W_KING,
	SPRITE_W_QUEEN,

	SPRITE_BLOCK_0,
	SPRITE_BLOCK_1,
	SPRITE_BLOCK_2,

};

enum Piece
{
	Piece_ROOK_0 = 0,
	Piece_KNIGHT_0,
	Piece_BISHOP_0,
	Piece_KING,
	Piece_QUEEN,
	Piece_BISHOP_1,
	Piece_KNIGHT_1,
	Piece_ROOK_1,

	Piece_PAWN_0,
	Piece_PAWN_1,
	Piece_PAWN_2,
	Piece_PAWN_3,
	Piece_PAWN_4,
	Piece_PAWN_5,
	Piece_PAWN_6,
	Piece_PAWN_7,
	Piece_QUEEN_3,
	Piece_KNIGHT_3,
	Piece_BISHOP_3,
	Piece_ROOK_3,
};