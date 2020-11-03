#include "H.h"
#include <stdlib.h>
#include "MapDraw.h"
#pragma once

class Land_Mine
{
private:
	Block block[HEIGHT][WIDTH];
	MapDraw Map;
	int m_ix, m_iy;


	void BlockSet_Neighbor( int N_x, int N_y);
	void BlockSet();
	void BLockSet_Bomb();

public:
	void Test_Show_Land_Mine();

	void Draw_Land_MIne();
	void BlockDraw(int x, int y);
	void OpenBlock(Block *block);

	Land_Mine();
	~Land_Mine();
};

