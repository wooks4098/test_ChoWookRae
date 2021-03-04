#pragma once
#include<Windows.h>
#include<string>
#include<time.h>

#define RESOURCE_COUNT 15
#define WIDTH 75
#define HEIGHT 75
#define NULLPIECE -1

enum SPRITE
{
	SPRITE_BLOCK_0 = 0,
	SPRITE_BLOCK_1,
	SPRITE_BLOCK_2,
	SPRITE_B_KING,
	SPRITE_B_QUEEN,
	SPRITE_B_BISHOP,
	SPRITE_B_KNIGHT,
	SPRITE_B_ROOK,
	SPRITE_B_PAWN,
	SPRITE_W_KING,
	SPRITE_W_QUEEN,
	SPRITE_W_BISHOP,
	SPRITE_W_KNIGHT,
	SPRITE_W_ROOK,
	SPRITE_W_PAWN,

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
};