#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


void main()
{
	vector<int> x;
	vector<vector<int>> Map;
	int Height, Width, Mapinfo;
	ifstream load;
	load.open("Map.txt");

	if (!load.eof())
	{
		load >> Height;
		load >> Width;
	}
	x.reserve(10);
	x.clear();
	for (int y= 0; y < Height; y++)
	{
		Map.push_back(x);
		for (int x = 0; x < Width; x++)
		{
			load >> Mapinfo;
			Map[y].push_back(Mapinfo);
		}
	}
	load.close();
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			cout <<Map[y][x]<<" ";
		}
		cout << endl;
	}

}