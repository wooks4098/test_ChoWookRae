#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

#define WIDTH 10
#define HEIGHT 10

struct Block
{
	int Number;
	bool isbomb;
	vector< Block*> NextBlock;
};

#pragma once
