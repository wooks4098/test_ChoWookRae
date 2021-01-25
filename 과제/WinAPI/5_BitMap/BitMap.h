#pragma once
#include "BitMap.h"
#include <vector>
class BitMap
{
private:
	std::vector<BitMap>bitmap;
public:
	void Draw();
	BitMap();
	~BitMap();
};

