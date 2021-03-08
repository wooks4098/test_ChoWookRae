#include "Map.h"
Map* Map::m_pThis = NULL;

void Map::MapDraw(HDC hdc)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (y % 2 == 0)
			{
				if (x % 2 == 0)
				{
					SpriteManager::GetInstans()->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT, SPRITE_BLOCK_0,false);
				}
				else
				{
					SpriteManager::GetInstans()->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT, SPRITE_BLOCK_1, false);

				}

			}
			else
			{
				if (x % 2 == 0)
				{
					SpriteManager::GetInstans()->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT, SPRITE_BLOCK_1, false);

				}
				else
				{
					SpriteManager::GetInstans()->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT, SPRITE_BLOCK_0,false);

				}
			}
			SpriteManager::GetInstans()->Draw(hdc, 20 + x * WIDTH, 20 + y * HEIGHT, WIDTH, HEIGHT, SPRITE_BLOCK_2, true);
		}
	}
}