#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include <map>
struct Image
{
	RECT size;
	int ID;
};

class Sprite
{
private:
	std::map<std::string, Image> sprite;

public:
	void Create_Sprite();
	void DataSet_Sprite(std::string Name, Image image);
	void Find_Sprite(RECT* rect, int *id);
};

