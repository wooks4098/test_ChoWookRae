#pragma once
#include <Windows.h>
#include <math.h>
#include <stdlib.h>

#define M_PI 3.141592f

#define RESOURCE 27
#define CLEARFRAME 2
#define RUNFRAME 3
#define StartMap 0
#define EndMap 200
#define Map_Right_Move 2
#define Map_Left_Move -2
enum BITMAP_IMAGE
{
	BITMAP_BACK,
	BITMAP_BACK_DECO,
	BITMAP_BACK_NOMAL,
	BITMAP_BACK_NOMAL2,
	BITMAP_CASH,
	BITMAP_DIE,
	BITMAP_END,
	BITMAP_ENEMY_L,
	BITMAP_ENEMY_L1,
	BITMAP_ENEMY_R,
	BITMAP_ENEMY_R1,
	BITMAP_FRONT,
	BITMAP_FRONT1,
	BITMAP_ICON,
	BITMAP_MITER,
	BITMAP_PLAYER0,
	BITMAP_PLAYER1,
	BITMAP_PLAYER2,
	BITMAP_STAR,
	BITMAP_STAR1,
	BITMAP_STAR2,
	BITMAP_WIN,
	BITMAP_WIN2,
	z_backBlack,
	BITMAP_ItemEnemy_L,
	BITMAP_ItemEnemy_L1,
	BITMAP_ItemEnemy_R,
	BITMAP_ItemEnemy_R1,
};