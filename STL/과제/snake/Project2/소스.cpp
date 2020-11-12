#include <iostream>
#include "GameManager.h"
#include <crtdbg.h>
void main()
{
	GameManager Game;
	Game.Start();
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	//_crtBreakAlloc = 291491;
}