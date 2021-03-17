#include "Map.h"



Map::Map()
{
	Ground[8];
	for (int i = 0; i < 8; i++)
	{
		Ground[i].BitMap_Number = BITMAP_BACK;
		Ground[i].pos.y = 84;
		Ground[i].pos.x = i * 67;
	}
	Ui.BitMap_Number = z_backBlack;
	Ui.pos.x = 0;
	Ui.pos.y = 0;
}
void Map::Draw(HDC hdc)
{
	BitMapManager::GetInstans()->Draw(hdc, Ui.pos, Ui.BitMap_Number);
	for (int i = 0; i < 8; i ++ )
	{
		BitMapManager::GetInstans()->Draw(hdc, Ground[i].pos, Ground[i].BitMap_Number);

	}
}


Map::~Map()
{
}
