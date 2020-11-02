#include "H.h"
#include <stdlib.h>
#pragma once

class Land_Mine
{
private:
	Block block[HEIGHT][WIDTH];

	void BlockSet_Neighbor( int N_x, int N_y);
	void BlockSet();
	void BLockSet_Bomb();

public:
	void Show_Land_Mine();
	Land_Mine();
	~Land_Mine();
};

