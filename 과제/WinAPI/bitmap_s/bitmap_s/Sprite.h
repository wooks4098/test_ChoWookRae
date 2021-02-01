#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "resource.h"
struct Image
{
	int Width;
	int Height;
	int ID;
};

class Sprite
{
private:
	std::map<std::string, Image> sprite;

public:
	void Create_Sprite();
	void DataSet_Sprite(std::string Name, int Id));
	void Find_Sprite(RECT* rect, int *id);
};

